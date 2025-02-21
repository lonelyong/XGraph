#pragma once
#include <vector>

#include <vsg/maths/vec3.h>
#include <vsg/maths/vec4.h>

namespace vsg {
class MatrixTransform;
}

namespace vkv {
class DottedCurve {
  public:
    DottedCurve();
    virtual ~DottedCurve();

  private:
    DottedCurve(const DottedCurve&)            = delete;
    DottedCurve(DottedCurve&&)                 = delete;
    DottedCurve& operator=(const DottedCurve&) = delete;

  public:
    void                    setInputPoints(const std::vector<vsg::dvec3>& pts);
    void                    setInputPoints(std::vector<vsg::dvec3>&& pts);
    void                    setIsClosed(bool val);
    void                    sort();
    void                    downsample(float max_dist, float max_angle, int max_iterations);
    std::vector<vsg::dvec3> getPoints() const;
    vsg::MatrixTransform*   createGeometry(bool              points_visible = true,
                                           bool              lines_visible  = true,
                                           const vsg::dvec4& points_color   = vsg::dvec4(1, 0, 0, 1),
                                           const vsg::dvec4& lines_color    = vsg::dvec4(0, 1, 0, 1)) const;

  private:
    struct Data;
    Data* const d;
};
} // namespace vkv