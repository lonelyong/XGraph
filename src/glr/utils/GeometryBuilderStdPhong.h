#pragma once

#include <glr/glrenderer_global.h>

namespace glr {
class GLR_API GeometryBuilderStdPhong {
  public:
    void setVertexArray();
    void setNormalArray();
    void setColorArray();
    void setTexCoordArray();
};
} // namespace glr