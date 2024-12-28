#pragma once

#include <glr/glrenderer_global.h>

#include <glr/scene/Geometry.h>

namespace glr {
class GLR_API SimpleGeometry : public Geometry {
    VI_OBJECT_META;

  public:
    SimpleGeometry();
    virtual ~SimpleGeometry();

  public:
    void setVertices(Vec3fArray* vertices);
    void setNormals(Vec3fArray* normals);
    void setColors(Vec4fArray* colors);
};
} // namespace glr