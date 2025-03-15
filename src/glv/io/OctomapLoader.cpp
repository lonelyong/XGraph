#include "OctomapLoader.h"

#include <filesystem>

#include <glad/glad.h>

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

namespace glv {

namespace {
osg::Vec4 s_default_face_color = osg::Vec4(0.88, 0.88, 0.88, 1.0);


} // namespace


struct DrawCallback_Transform : osg::Drawable::DrawCallback {

    virtual void drawImplementation(osg::RenderInfo& renderInfo, const osg::Drawable* drawable) const override {
        if (transform_feedback_id_ == 0) {
            auto geom     = drawable->asGeometry();
            auto vertices = (osg::Vec3Array*)geom->getVertexArray();

            glGenTransformFeedbacks(1, &transform_feedback_id_);
            glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, transform_feedback_id_);

            glGenBuffers(1, &transform_feedback_buffer_id_);
            glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, transform_feedback_buffer_id_);

            glBufferData(GL_TRANSFORM_FEEDBACK_BUFFER, sizeof(float) * 10 * vertices->size(), nullptr, GL_STATIC_DRAW);
            glBindBufferBase(GL_TRANSFORM_FEEDBACK_BUFFER, 0, transform_feedback_buffer_id_);

            /*
            glDrawTransformFeedback 使用由 mode 指定的图元类型，并根据由 id 指定的变换反馈（Transform
            Feedback）对象检索的计数来绘制图元。 调用 glDrawTransformFeedback 等效于调用 glDrawArrays，其中 mode
            采用相同的指定值，first 设为 0，count 设为上次该变换反馈对象处于活动状态时，在顶点流 0 上捕获的顶点数量。
            */
            // glDrawTransformFeedback(GL_POINTS, transform_feedback_id_);

            /*
            变换反馈模式（Transform Feedback
            Mode）用于捕获由顶点着色器（或如果启用了几何着色器，则由几何着色器）写入的可变变量（Varying
            Variables）的值。 从调用 glBeginTransformFeedback 直到后续调用 glEndTransformFeedback
            之间，变换反馈被认为是处于活动状态的。 变换反馈命令必须成对使用。
            如果没有几何着色器，在变换反馈处于活动状态时，glDrawArrays 的 mode 参数必须与下表中指定的模式匹配：
            */
            glBeginTransformFeedback(GL_TRIANGLE_STRIP);
            glEnable(GL_RASTERIZER_DISCARD);
            drawable->drawImplementation(renderInfo);
            glDisable(GL_RASTERIZER_DISCARD);
            glEndTransformFeedback();

            //glGetTransformFeedbackiv(, );

            glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
            glBindBuffer(GL_TRANSFORM_FEEDBACK_BUFFER, 0);
        }
        glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, transform_feedback_id_);
        drawable->drawImplementation(renderInfo);
        glBindTransformFeedback(GL_TRANSFORM_FEEDBACK, 0);
    }
    mutable GLuint             transform_feedback_id_        = 0;
    mutable GLuint             transform_feedback_buffer_id_ = 0;
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
        geom->setVertexAttribArray(1, colors, osg::Array::BIND_OVERALL);
        geom->setVertexAttribArray(15, sizes, osg::Array::BIND_PER_VERTEX);
        //geom->setDrawCallback(new DrawCallbackTransformFeedback());

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

#else
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