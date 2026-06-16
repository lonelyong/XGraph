#pragma once

#include <xg/glr/glr_global.h>

namespace xg {
namespace glr {
class Model;
class CubeMap;
GLR_API Model* createSkyBox(CubeMap* tex);
} // namespace glr
} // namespace xg