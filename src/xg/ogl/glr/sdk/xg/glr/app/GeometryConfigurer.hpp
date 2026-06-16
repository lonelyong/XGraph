#pragma once

#include <xg/glr/glr_global.h>

namespace glr {
class Geometry;
class StateSet;
class GLR_API GeometryConfigurer {
  public:
    /**
     * @brief 匹配geom的顶点数据与StdPhong着色器的location
     * @param geom
     * @param ss 如果ss为空，则会使用geom的StateSet
     */
    static void configureStdPhong(Geometry* geom, StateSet* ss = nullptr);
};
} // namespace glr