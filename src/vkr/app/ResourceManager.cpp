#include "ResourceManager.h"

#include <map>
#include <vector>

#include <vine/core/Ptr.h>

#include <xgcomm/Resources.h>

#include <vkr/engine/Shader.h>

namespace vkr {

static std::map<std::string, vine::RefPtr<Shader>> s_shaders;

ResourceManager::ResourceManager() {
}

ResourceManager* ResourceManager::instance() {
    static ResourceManager* inst = new ResourceManager();
    return inst;
}

Shader* ResourceManager::getShader(const std::string& name) {
    if (s_shaders.find(name) == s_shaders.end()) {
        auto vs = "shaders/" + name + ".vs.glsl";
        auto gs = "shaders/" + name + ".gs.glsl";
        auto fs = "shaders/" + name + ".fs.glsl";

        auto shader = Shader::create(XG_RES("") + vs, XG_RES("") + gs, XG_RES("") + fs);
        if (shader) {
            s_shaders.insert({ name, shader });
        }
        return shader;
    }
    return s_shaders[name].get();
}

Shader* ResourceManager::getInternalShader(InternalShader shader) {
    if (shader == IS_Base) {
        return getShader("Base");
    }
    else if (shader == IS_Geometry) {
        return getShader("MeshShape");
    }
    else if (shader == IS_PointCloud) {
        return getShader("PointCloud");
    }
    else if (shader == IS_SkyBox) {
        return getShader("SkyBox");
    }
    return nullptr;
}

CubeMap* ResourceManager::getInternalCubeMap(InternalCubeMap map) {
    std::vector<std::string> files;
    if (map == ICM_CubeMap1) {
        files.push_back(XG_RES("images/right.jpg"));
        files.push_back(XG_RES("images/left.jpg"));
        files.push_back(XG_RES("images/top.jpg"));
        files.push_back(XG_RES("images/bottom.jpg"));
        files.push_back(XG_RES("images/front.jpg"));
        files.push_back(XG_RES("images/back.jpg"));
    }
    else if (map == ICM_CubeMap2) {
        files.push_back(XG_RES("images/posx.jpg"));
        files.push_back(XG_RES("images/negx.jpg"));
        files.push_back(XG_RES("images/posy.jpg"));
        files.push_back(XG_RES("images/negy.jpg"));
        files.push_back(XG_RES("images/posz.jpg"));
        files.push_back(XG_RES("images/negz.jpg"));
    }
    else
        return nullptr;
    return nullptr;
}
} // namespace vkr