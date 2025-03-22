#include "OctomapLoader.h"

#include <filesystem>

#include <osg/CullFace>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Material>
#include <osg/MatrixTransform>
#include <osg/PolygonMode>
#include <osg/Program>
#include <osgUtil/SmoothingVisitor>

#include <octomap/octomap.h>

#include <xgcomm/Environment.h>
#include <xgcomm/Resources.h>

#include <glr/igl/GLfuncs.h>

#include <glv/utils/GLfuncsManager.h>

namespace glv {

namespace {
osg::Vec4 s_default_face_color = osg::Vec4(0.88, 0.88, 0.88, 1.0);


} // namespace


struct DrawCallback_Transform : osg::Drawable::DrawCallback {

    DrawCallback_Transform(osg::Vec3Array* vertices_feedback, osg::Vec3Array* norms_feedback)
      : vertices_feedback_(vertices_feedback)
      , norms_feedback_(norms_feedback) {}

    virtual void drawImplementation(osg::RenderInfo& renderInfo, const osg::Drawable* drawable) const override {
        if (transform_feedback_id_) return;

        auto funcs = GLfuncsManager::instance().getOrRegisterByContext(renderInfo.getState()->getGraphicsContext());
        if (!funcs) return;

        auto vertices_feedback_buffer = vertices_feedback_->getOrCreateGLBufferObject(renderInfo.getContextID());
        auto norms_feedback_buffer    = norms_feedback_->getOrCreateGLBufferObject(renderInfo.getContextID());

        funcs->iglGenTransformFeedbacks(1, &transform_feedback_id_);
        funcs->iglBindTransformFeedback(IGL_TRANSFORM_FEEDBACK, transform_feedback_id_);
        //funcs->iglBindBufferBase(IGL_TRANSFORM_FEEDBACK_BUFFER, 0, vertices_feedback_buffer->getGLObjectID());
        //funcs->iglBindBufferBase(IGL_TRANSFORM_FEEDBACK_BUFFER, 1, norms_feedback_buffer->getGLObjectID());
        funcs->iglTransformFeedbackBufferBase(transform_feedback_id_, 0, vertices_feedback_buffer->getGLObjectID());
        funcs->iglTransformFeedbackBufferBase(transform_feedback_id_, 1, norms_feedback_buffer->getGLObjectID());

        /*
        glDrawTransformFeedback 使用由 mode 指定的图元类型，并根据由 id 指定的变换反馈（Transform
        Feedback）对象检索的计数来绘制图元。 调用 glDrawTransformFeedback 等效于调用 glDrawArrays，其中 mode
        采用相同的指定值，first 设为 0，count 设为上次该变换反馈对象处于活动状态时，在顶点流 0 上捕获的顶点数量。
        */
        // glDrawTransformFeedback(GL_POINTS, transform_feedback_id_);

        GLuint_t query_id(0);
        funcs->iglGenQueries(1, &query_id);
        funcs->iglBeginQuery(IGL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, query_id);

        GLint_t query_counter_bits(0);
        funcs->iglGetQueryiv(IGL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN, IGL_QUERY_COUNTER_BITS, &query_counter_bits);

        assert(query_counter_bits >= 1);

        /*
        变换反馈模式（Transform Feedback
        Mode）用于捕获由顶点着色器（或如果启用了几何着色器，则由几何着色器）写入的可变变量（Varying
        Variables）的值。 从调用 glBeginTransformFeedback 直到后续调用 glEndTransformFeedback
        之间，变换反馈被认为是处于活动状态的。 变换反馈命令必须成对使用。
        如果没有几何着色器，在变换反馈处于活动状态时，glDrawArrays 的 mode 参数必须与下表中指定的模式匹配：
        */
        funcs->iglBeginTransformFeedback(GL_POINTS);
        funcs->iglEnable(GL_RASTERIZER_DISCARD);
        drawable->drawImplementation(renderInfo);
        funcs->iglDisable(GL_RASTERIZER_DISCARD);
        funcs->iglEndTransformFeedback();

        funcs->iglEndQuery(IGL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN);
        GLuint_t nb_priv_written(0);
        funcs->iglGetQueryObjectuiv(query_id, GL_QUERY_RESULT, &nb_priv_written);
        funcs->iglDeleteQueries(1, &query_id);

        GLint_t size_of_buffer(0);

        funcs->iglBindBuffer(IGL_TRANSFORM_FEEDBACK_BUFFER, vertices_feedback_buffer->getGLObjectID());
        funcs->iglGetBufferSubData(IGL_TRANSFORM_FEEDBACK_BUFFER,
                                   0,
                                   vertices_feedback_->size() * 3 * sizeof(float),
                                   (void*)vertices_feedback_->getDataPointer());
        funcs->iglGetBufferParameteriv(IGL_TRANSFORM_FEEDBACK_BUFFER, IGL_BUFFER_SIZE, &size_of_buffer);

        funcs->iglBindTransformFeedback(IGL_TRANSFORM_FEEDBACK, 0);
        funcs->iglBindBufferBase(IGL_TRANSFORM_FEEDBACK_BUFFER, 0, 0);
        funcs->iglBindBufferBase(IGL_TRANSFORM_FEEDBACK_BUFFER, 1, 0);

        // funcs->iglBindTransformFeedback(IGL_TRANSFORM_FEEDBACK, transform_feedback_id_);
        // drawable->drawImplementation(renderInfo);
        // funcs->iglBindTransformFeedback(IGL_TRANSFORM_FEEDBACK, 0);
    }
    mutable GLuint transform_feedback_id_ = 0;

    osg::ref_ptr<osg::Vec3Array> vertices_feedback_;
    osg::ref_ptr<osg::Vec3Array> norms_feedback_;
};

bool OctomapLoader::isSupported(const std::string& file) {
    namespace fs = std::filesystem;
    fs::path path(file);
    if (!path.has_extension()) return false;
    auto                         file_ext = path.extension().string();
    static std::set<std::string> exts     = { ".bt" };
    return exts.contains(file_ext);
}

OctomapLoader::OctomapLoader()
  : render_option_(RENDER_AS_BOX) {
}

void OctomapLoader::setRenderOption(RenderOption option) {
    render_option_ = option;
}

OctomapLoader::RenderOption OctomapLoader::getRenderOption() {
    return render_option_;
}

osg::MatrixTransform* OctomapLoader::loadFile(const std::string& file) {
    octomap::OcTree tree(file);

    auto vertices = osg::ref_ptr(new osg::Vec3Array());
    auto colors   = osg::ref_ptr(new osg::Vec4Array());

    colors->push_back(osg::Vec4(0.0f, 1.f, 0.f, 1.f));

    auto geom = osg::ref_ptr(new osg::Geometry());
    geom->setVertexArray(vertices);
    geom->setColorArray(colors, osg::Array::BIND_OVERALL);
    geom->setUseVertexBufferObjects(true);
    geom->setUseVertexArrayObject(true);

    auto geod = osg::ref_ptr<osg::Geode>(new osg::Geode());
    geod->addDrawable(geom);

    auto root = osg::ref_ptr(new osg::MatrixTransform());
    root->addChild(geod);
    root->getOrCreateStateSet()->setAttribute(new osg::CullFace(osg::CullFace::BACK));

    if (render_option_ == RENDER_AS_POINT) {
        for (octomap::OcTree::leaf_iterator it = tree.begin_leafs(tree.getTreeDepth()), end = tree.end_leafs();
             it != end;
             ++it) {
            vertices->push_back(osg::Vec3f(it.getX(), it.getY(), it.getZ()));
        }

        // for (int i = 0; i < boundaries->size(); ++i) {
        //     if (boundaries->points[i].boundary_point) {
        //         vertices->push_back(osg::Vec3f(pc->points[i].x, pc->points[i].y, pc->points[i].z));
        //     }
        // }

        auto mate = osg::ref_ptr(new osg::Material());
        mate->setColorMode(osg::Material::EMISSION);
        mate->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1));
        mate->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1));
        mate->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1));

        geom->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices->size()));
        // root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
        root->getOrCreateStateSet()->setAttributeAndModes(mate, osg::StateAttribute::ON);
    }
    else if (render_option_ == RENDER_AS_BOX) {
        auto sizeH = 0.0;
        auto norms = osg::ref_ptr(new osg::Vec3Array());
        for (octomap::OcTree::leaf_iterator it = tree.begin_leafs(tree.getTreeDepth()), end = tree.end_leafs();
             it != end;
             ++it) {
            sizeH = it.getSize() * 0.5;
            // vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ())); // b1
            // vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));  // b2
            // vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));   // b3
            // vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));  // b4
            // vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));  // t1
            // vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));   // t2
            // vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));    // t3
            // vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));   // t4

            // BOTTOM
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            norms->push_back(osg::Vec3f(0, 0, -1));
            norms->push_back(osg::Vec3f(0, 0, -1));
            norms->push_back(osg::Vec3f(0, 0, -1));
            norms->push_back(osg::Vec3f(0, 0, -1));
            norms->push_back(osg::Vec3f(0, 0, -1));
            norms->push_back(osg::Vec3f(0, 0, -1));

            // TOP
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            norms->push_back(osg::Vec3f(0, 0, 1));
            norms->push_back(osg::Vec3f(0, 0, 1));
            norms->push_back(osg::Vec3f(0, 0, 1));
            norms->push_back(osg::Vec3f(0, 0, 1));
            norms->push_back(osg::Vec3f(0, 0, 1));
            norms->push_back(osg::Vec3f(0, 0, 1));

            // FRONT
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            norms->push_back(osg::Vec3f(0, -1, 0));
            norms->push_back(osg::Vec3f(0, -1, 0));
            norms->push_back(osg::Vec3f(0, -1, 0));
            norms->push_back(osg::Vec3f(0, -1, 0));
            norms->push_back(osg::Vec3f(0, -1, 0));
            norms->push_back(osg::Vec3f(0, -1, 0));

            // BACK
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            norms->push_back(osg::Vec3f(0, 1, 0));
            norms->push_back(osg::Vec3f(0, 1, 0));
            norms->push_back(osg::Vec3f(0, 1, 0));
            norms->push_back(osg::Vec3f(0, 1, 0));
            norms->push_back(osg::Vec3f(0, 1, 0));
            norms->push_back(osg::Vec3f(0, 1, 0));


            // LEFT
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(-sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            norms->push_back(osg::Vec3f(-1, 0, 0));
            norms->push_back(osg::Vec3f(-1, 0, 0));
            norms->push_back(osg::Vec3f(-1, 0, 0));
            norms->push_back(osg::Vec3f(-1, 0, 0));
            norms->push_back(osg::Vec3f(-1, 0, 0));
            norms->push_back(osg::Vec3f(-1, 0, 0));

            // RIGHT
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), -sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), sizeH + it.getZ()));
            vertices->push_back(osg::Vec3(sizeH + it.getX(), -sizeH + it.getY(), -sizeH + it.getZ()));
            norms->push_back(osg::Vec3f(1, 0, 0));
            norms->push_back(osg::Vec3f(1, 0, 0));
            norms->push_back(osg::Vec3f(1, 0, 0));
            norms->push_back(osg::Vec3f(1, 0, 0));
            norms->push_back(osg::Vec3f(1, 0, 0));
            norms->push_back(osg::Vec3f(1, 0, 0));
        }

        auto mate = osg::ref_ptr(new osg::Material());
        mate->setColorMode(osg::Material::AMBIENT_AND_DIFFUSE);
        geom->setNormalArray(norms, osg::Array::BIND_PER_VERTEX);
        geom->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLES, 0, vertices->size()));
        root->getOrCreateStateSet()->setAttributeAndModes(mate, osg::StateAttribute::ON);
    }
    else if (render_option_ == RENDER_AS_BOX_USE_GEOMETRY_SHADER) {
        auto sizes = osg::ref_ptr(new osg::FloatArray());
        for (octomap::OcTree::leaf_iterator it = tree.begin_leafs(tree.getTreeDepth()), end = tree.end_leafs();
             it != end;
             ++it) {
            vertices->push_back(osg::Vec3f(it.getX(), it.getY(), it.getZ()));
            sizes->push_back(it.getSize());
        }

        geom->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices->size()));
        geom->setVertexAttribArray(15, sizes, osg::Array::BIND_PER_VERTEX);
        auto appdir = xg::getApplicationDir() + "/";

        // use transform feedback
#if 1
        auto vs = osg::ref_ptr(new osg::Shader(osg::Shader::VERTEX));
        auto gs = osg::ref_ptr(new osg::Shader(osg::Shader::GEOMETRY));
        vs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube_transform.vs.glsl"));
        gs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube_transform.gs.glsl"));
        auto prog = new osg::Program();
        prog->addShader(vs);
        prog->addShader(gs);
        // 输出变量交替存储再同一个缓冲区
        // prog->setTransformFeedBackMode(GL_INTERLEAVED_ATTRIBS);
        // 不同的输出变量独立存储，需要绑定多个缓冲区
        prog->setTransformFeedBackMode(GL_SEPARATE_ATTRIBS);
        prog->addTransformFeedBackVarying("gl_Position");
        prog->addTransformFeedBackVarying("norm");

        auto vertices_feedback = osg::ref_ptr(new osg::Vec3Array());
        auto norms_feedback    = osg::ref_ptr(new osg::Vec3Array());

        // 主动设置VBO,否则同一个Geom默认会公用VBO
        vertices_feedback->setBufferObject(new osg::VertexBufferObject());
        vertices_feedback->resize(vertices->size() * 24);
        norms_feedback->setBufferObject(new osg::VertexBufferObject());
        norms_feedback->resize(vertices->size() * 24);

        geom->setDrawCallback(new DrawCallback_Transform(vertices_feedback, norms_feedback));
        geom->getOrCreateStateSet()->setAttributeAndModes(prog, 1);


        auto vs_feedback = osg::ref_ptr(new osg::Shader(osg::Shader::VERTEX));
        auto fs_feedback = osg::ref_ptr(new osg::Shader(osg::Shader::FRAGMENT));
        vs_feedback->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube_feedback.vs.glsl"));
        fs_feedback->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube_feedback.fs.glsl"));

        auto prog_feedback = new osg::Program();
        prog_feedback->addShader(vs_feedback);
        prog_feedback->addShader(fs_feedback);

        auto geom_feedback = osg::ref_ptr(new osg::Geometry());
        geom_feedback->setVertexArray(vertices_feedback);
        geom_feedback->setNormalArray(norms_feedback, osg::Array::BIND_PER_VERTEX);
        geom_feedback->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices_feedback->size()));
        geom_feedback->getOrCreateStateSet()->setAttributeAndModes(prog_feedback, 1);
        geom_feedback->setUseVertexBufferObjects(true);
        geom_feedback->setColorArray(colors, osg::Array::BIND_OVERALL);

        geod->addDrawable(geom_feedback);
#else
        geom->setVertexAttribArray(1, colors, osg::Array::BIND_OVERALL);

        auto vs = osg::ref_ptr(new osg::Shader(osg::Shader::VERTEX));
        auto gs = osg::ref_ptr(new osg::Shader(osg::Shader::GEOMETRY));
        auto fs = osg::ref_ptr(new osg::Shader(osg::Shader::FRAGMENT));
        vs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube.vs.glsl"));
        gs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube.gs.glsl"));
        fs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube.fs.glsl"));

        auto prog = new osg::Program();
        prog->addShader(vs);
        prog->addShader(gs);
        prog->addShader(fs);
        root->getOrCreateStateSet()->setAttribute(prog);
#endif
    }
    else {
        return nullptr;
    }
    // root->getOrCreateStateSet()->setAttribute(new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK,
    // osg::PolygonMode::LINE));
    return root.release();
}
} // namespace glv