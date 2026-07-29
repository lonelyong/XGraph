#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API BoundingBox {
  public:
    BoundingBox();
    BoundingBox(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax);

  public:
    Vec3d  getCenter() const;
    double getRadius() const;
    double getXLength() const;
    double getYLength() const;
    double getZLength() const;

    void combine(const BoundingBox& box);
    void expandBy(const Vec3d& pt);

    void set(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax);

  private:
    Vec3d min_;
    Vec3d max_;
};

} // namespace glr
} // namespace xg