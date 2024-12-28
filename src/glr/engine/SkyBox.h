#pragma once

#include <glr/glrenderer_global.h>

namespace glr {
class Model;
class CubeMap;
GLR_API Model* createSkyBox(CubeMap* tex);
} // namespace glr