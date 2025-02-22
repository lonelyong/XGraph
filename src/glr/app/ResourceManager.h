#pragma once

#include <glr/glr_global.h>

#include <string>

namespace glr {
class Shader;
class CubeMap;
// 暂不考虑多上下文共享资源
class GLR_API ResourceManager {
  public:
    enum InternalShader
    {
        EXAMPLE_SAHDER_BASE = 0,
        EXAMPLE_SAHDER_STD_PHONG,
        EXAMPLE_SAHDER_POINT_CLOUD,
        EXAMPLE_SAHDER_SKY_BOX
    };

    enum InternalCubeMap
    {
        EXAMPLE_CUBE_MAP1,
        EXAMPLE_CUBE_MAP2
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
} // namespace glr