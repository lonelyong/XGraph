#include "OctomapLoader.h"

#include <filesystem>

#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Material>
#include <osg/MatrixTransform>
#include <osg/Program>
#include <osg/PolygonMode>
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

osg::MatrixTransform* OctomapLoader::loadFile(const std::string& file) {
    octomap::OcTree tree(file);

    auto vertices = osg::ref_ptr(new osg::Vec3Array());
    auto colors   = osg::ref_ptr(new osg::Vec4Array());
    auto sizes    = osg::ref_ptr(new osg::FloatArray());

    colors->push_back(osg::Vec4(0.0f, 1.f, 0.f, 1.f));

    for (octomap::OcTree::leaf_iterator it = tree.begin_leafs(tree.getTreeDepth()), end = tree.end_leafs(); it != end;
         ++it) {
        vertices->push_back(osg::Vec3f(it.getX(), it.getY(), it.getZ()));
        sizes->push_back(it.getSize());
    }

    auto geom = osg::ref_ptr(new osg::Geometry());
    geom->setVertexArray(vertices);
    geom->setVertexAttribArray(15, sizes, osg::Array::BIND_PER_VERTEX);
    geom->setColorArray(colors, osg::Array::BIND_OVERALL);
    geom->addPrimitiveSet(new osg::DrawArrays(GL_POINTS, 0, vertices->size()));
    geom->setUseVertexBufferObjects(true);
    geom->setUseVertexArrayObject(true);

    auto geod = osg::ref_ptr<osg::Geode>(new osg::Geode());
    geod->addDrawable(geom);

    auto appdir = xg::getApplicationDir() + "/";

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

    auto root = osg::ref_ptr(new osg::MatrixTransform());
    root->addChild(geod);
    root->getOrCreateStateSet()->setMode(GL_LIGHTING, 0);
    root->getOrCreateStateSet()->setAttribute(prog);

    //root->getOrCreateStateSet()->setAttribute(new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK, osg::PolygonMode::LINE));
    return root.release();
}
} // namespace glv