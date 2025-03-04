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

namespace glv {

namespace {
osg::Vec4 s_default_face_color = osg::Vec4(0.88, 0.88, 0.88, 1.0);

} // namespace

bool OctomapLoader::isSupported(const std::string& file) {
    namespace fs = std::filesystem;
    fs::path path(file);
    if (!path.has_extension()) return false;
    auto                         file_ext = path.extension().string();
    static std::set<std::string> exts     = { ".bt" };
    return exts.contains(file_ext);
}

OctomapLoader::OctomapLoader()
  : option_(RENDER_AS_BOX_DIRECTLY) {
}

void OctomapLoader::setOption(Option option) {
    option_ = option;
}

OctomapLoader::Option OctomapLoader::getOption() {
    return option_;
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

    if (option_ == RENDER_AS_POINT) {
        for (octomap::OcTree::leaf_iterator it = tree.begin_leafs(tree.getTreeDepth()), end = tree.end_leafs();
             it != end;
             ++it) {
            vertices->push_back(osg::Vec3f(it.getX(), it.getY(), it.getZ()));
        }

        auto mate = osg::ref_ptr(new osg::Material());
        mate->setColorMode(osg::Material::EMISSION);
        mate->setAmbient(osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1));
        mate->setDiffuse(osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1));
        mate->setSpecular(osg::Material::FRONT_AND_BACK, osg::Vec4(0, 0, 0, 1));

        geom->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices->size()));
        //root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
        root->getOrCreateStateSet()->setAttributeAndModes(mate, osg::StateAttribute::ON);
    }
    else if (option_ == RENDER_AS_BOX_DIRECTLY) {
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
    else if (option_ == RENDER_AS_BOX_USE_GEOMETRY_SHADER) {
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

        auto appdir = xg::getApplicationDir() + "/";
        auto vs     = osg::ref_ptr(new osg::Shader(osg::Shader::VERTEX));
        auto gs     = osg::ref_ptr(new osg::Shader(osg::Shader::GEOMETRY));
        auto fs     = osg::ref_ptr(new osg::Shader(osg::Shader::FRAGMENT));
        vs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube.vs.glsl"));
        gs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube.gs.glsl"));
        fs->loadShaderSourceFromFile(appdir + XG_RES("shaders/octmap_cube.fs.glsl"));

        auto prog = new osg::Program();
        prog->addShader(vs);
        prog->addShader(gs);
        prog->addShader(fs);
        root->getOrCreateStateSet()->setAttribute(prog);
    }
    else {
        return nullptr;
    }
    // root->getOrCreateStateSet()->setAttribute(new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK,
    // osg::PolygonMode::LINE));
    return root.release();
}
} // namespace glv