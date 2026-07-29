#pragma once

#include <xg/igl/glr_global.hpp>

namespace xg
{
namespace glr
{

class Model;
class CubeMap;
IGL_CORE_API Model* createSkyBox(CubeMap* tex);

} // namespace glr
} // namespace xg