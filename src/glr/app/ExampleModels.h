#pragma once

#include <glr/engine/types.h>
#include <glr/glrenderer_global.h>

namespace glr {
class Model;

class GLR_API ExampleModels {
  public:
    static Model* createAxis(float len, const Vec3d& posi);

    static Model* createCube(float len, const Vec3d& posi, bool with_tex = false);

    static Model* createSkyBox();

    static Model* createPointCloud(int n);

    static Model* createImage(const char* file);
};
} // namespace glr