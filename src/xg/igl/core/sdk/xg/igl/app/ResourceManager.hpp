#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>

namespace xg
{
namespace glr
{

class Program;
class CubeMap;

class IGL_CORE_API ResourceManager {
  public:
    enum InternalShader
    {
        EXAMPLE_SAHDER_BASE = 0,
        EXAMPLE_SAHDER_STD_PHONG,
        EXAMPLE_SAHDER_POINT_CLOUD,
        EXAMPLE_SAHDER_SKY_BOX,
        EXAMPLE_SAHDER_DIRECT
    };

    enum InternalCubeMap
    {
        EXAMPLE_CUBE_MAP1,
        EXAMPLE_CUBE_MAP2
    };

  private:
    ResourceManager();

  public:
    Program* getShader(const std::string& name);
    Program* getInternalShader(InternalShader shader);
    CubeMap* getInternalCubeMap(InternalCubeMap map);

  public:
    static ResourceManager* instance();
};

} // namespace glr
} // namespace xg