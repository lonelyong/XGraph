#include "ResourceManager.h"

#include <map>

#include <vine/Ptr.hpp>

#include <xgcomm/Environment.h>
#include <xgcomm/Resources.h>

#include <glr/engine/CubeMap.h>
#include <glr/engine/Program.h>

namespace glr {

static std::map<std::string, vine::RefPtr<Program>> s_shaders;

ResourceManager::ResourceManager() {
}

ResourceManager* ResourceManager::instance() {
    static ResourceManager* inst = new ResourceManager();
    return inst;
}

Program* ResourceManager::getShader(const std::string& name) {
    if (s_shaders.find(name) == s_shaders.end()) {
        auto vs     = "shaders/" + name + ".vs.glsl";
        auto gs     = "shaders/" + name + ".gs.glsl";
        auto fs     = "shaders/" + name + ".fs.glsl";
        auto appdir = xg::getApplicationDir();
        appdir += "/";

        auto shader = Program::createFromFile(appdir + XG_RES("") + vs, appdir + XG_RES("") + gs, appdir + XG_RES("") + fs);
        if (shader) {
            s_shaders.insert({ name, shader });
        }
        return shader;
    }
    return s_shaders[name].get();
}

Program* ResourceManager::getInternalShader(InternalShader shader) {
    if (shader == EXAMPLE_SAHDER_BASE) {
        return getShader("Base");
    }
    else if (shader == EXAMPLE_SAHDER_STD_PHONG) {
        return getShader("StdPhong");
    }
    else if (shader == EXAMPLE_SAHDER_POINT_CLOUD) {
        return getShader("PointCloud");
    }
    else if (shader == EXAMPLE_SAHDER_SKY_BOX) {
        return getShader("SkyBox");
    }
    else if (shader == EXAMPLE_SAHDER_DIRECT) {
        return getShader("Direct");
    }
    return nullptr;
}

CubeMap* ResourceManager::getInternalCubeMap(InternalCubeMap map) {
    auto appdir = xg::getApplicationDir();
    appdir += "/";
    std::vector<std::string> files;
    if (map == EXAMPLE_CUBE_MAP1) {
        files.push_back(appdir + XG_RES("images/right.jpg"));
        files.push_back(appdir + XG_RES("images/left.jpg"));
        files.push_back(appdir + XG_RES("images/top.jpg"));
        files.push_back(appdir + XG_RES("images/bottom.jpg"));
        files.push_back(appdir + XG_RES("images/front.jpg"));
        files.push_back(appdir + XG_RES("images/back.jpg"));
    }
    else if (map == EXAMPLE_CUBE_MAP2) {
        files.push_back(appdir + XG_RES("images/posx.jpg"));
        files.push_back(appdir + XG_RES("images/negx.jpg"));
        files.push_back(appdir + XG_RES("images/posy.jpg"));
        files.push_back(appdir + XG_RES("images/negy.jpg"));
        files.push_back(appdir + XG_RES("images/posz.jpg"));
        files.push_back(appdir + XG_RES("images/negz.jpg"));
    }
    else
        return nullptr;
    auto cm = new CubeMap();
    cm->setImages(files);
    return cm;
}
} // namespace glr