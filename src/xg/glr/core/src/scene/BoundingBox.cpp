#include <xg/glr/scene/BoundingBox.hpp>

#include <cmath>
#include <utility>

namespace xg {
namespace glr {
namespace {
void swap(Vec3d& min, Vec3d& max) {
    if (min.x > max.x) std::swap<double>(min.x, max.x);
    if (min.y > max.y) std::swap<double>(min.y, max.y);
    if (min.z > max.z) std::swap<double>(min.z, max.z);
}
} // namespace

BoundingBox::BoundingBox()
  : min_(0)
  , max_(0) {
}

BoundingBox::BoundingBox(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax)
  : min_(xmin, ymin, zmin)
  , max_(xmax, ymax, zmax) {
    swap(min_, max_);
}

Vec3d BoundingBox::getCenter() const {
    return min_ + (max_ - min_) * Vec3d(0.5);
}

double BoundingBox::getRadius() const {
    return sqrt(pow(getXLength(), 2) + pow(getYLength(), 2) + pow(getZLength(), 2));
}

double BoundingBox::getXLength() const {
    return max_.x - min_.x;
}

double BoundingBox::getYLength() const {
    return max_.y - min_.y;
}

double BoundingBox::getZLength() const {

    return max_.z - min_.z;
}

void BoundingBox::combine(const BoundingBox& box) {
    auto temp = box;
    swap(min_, temp.min_);
    swap(temp.max_, max_);
}

void BoundingBox::expandBy(const Vec3d& pt) {
    auto temp = pt;
    swap(min_, temp);
    swap(temp, max_);
}

void BoundingBox::set(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax){
    min_.x = xmin;
    min_.y = ymin;
    min_.z = zmin;

    max_.x = xmax;
    max_.y = ymax;
    max_.z = zmax;
}
} // namespace glr
} // namespace xg