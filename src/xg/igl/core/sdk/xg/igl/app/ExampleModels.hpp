#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class Model;

class IGL_CORE_API ExampleModels {
  public:
    static Model* createAxis(float len, const Vec3d& posi);

    static Model* createCube(float len, const Vec3d& posi, bool with_tex = false);

    static Model* createSkyBox();

    static Model* createPointCloud(int n);

    static Model* createImage(const char* file);
};

} // namespace glr
} // namespace xg