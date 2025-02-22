#pragma once

#include <vkr/vkr_global.h>

#include <string>

namespace vkr {
class Shader;
class CubeMap;
// 暂不考虑多上下文共享资源
class VKR_API ResourceManager {
  public:
    enum InternalShader
    {
        IS_Base = 0,
        IS_Geometry,
        IS_PointCloud,
        IS_SkyBox
    };

    enum InternalCubeMap
    {
        ICM_CubeMap1,
        ICM_CubeMap2
    };

  private:
    ResourceManager();

  public:
    Shader*  getShader(const std::string& name);
    Shader*  getInternalShader(InternalShader shader);
    CubeMap* getInternalCubeMap(InternalCubeMap map);

  public:
    static ResourceManager* instance();
};
} // namespace vkr