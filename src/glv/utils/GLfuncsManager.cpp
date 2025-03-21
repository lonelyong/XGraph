#include "GLfuncsManager.h"

#include <memory>
#include <unordered_map>

#include <osg/GLExtensions>

#include <glr/igl/GLfuncs.h>

namespace glv {

static std::unordered_map<osg::GraphicsContext*, std::shared_ptr<glr::GLfuncs>> s_funcs_map;

GLfuncsManager& GLfuncsManager::instance() {
    static GLfuncsManager mgr;
    return mgr;
}

bool GLfuncsManager::registerByContext(osg::GraphicsContext* ctx) {
    if (s_funcs_map.contains(ctx)) return true;

    auto funcs = glr::GLfuncs::loadGLLoader([](const char* name) { return osg::getGLExtensionFuncPtr(name); });

    if (funcs) {
        s_funcs_map.insert({ ctx, std::shared_ptr<glr::GLfuncs>(funcs) });
        return true;
    }

    return false;
}

glr::GLfuncs* GLfuncsManager::getOrRegisterByContext(osg::GraphicsContext* ctx) {
    if (s_funcs_map.contains(ctx)) return s_funcs_map[ctx].get();

    auto funcs = glr::GLfuncs::loadGLLoader([](const char* name) { return osg::getGLExtensionFuncPtr(name); });

    if (!funcs) {
        funcs = glr::GLfuncs::load();
    }

    if (funcs) {
        s_funcs_map.insert({ ctx, std::shared_ptr<glr::GLfuncs>(funcs) });
        return funcs;
    }

    return nullptr;
}

glr::GLfuncs* GLfuncsManager::getByContext(osg::GraphicsContext* ctx) const {
    if (s_funcs_map.contains(ctx)) {
        return s_funcs_map[ctx].get();
    }
    return nullptr;
}
} // namespace glv
