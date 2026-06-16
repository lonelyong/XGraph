#pragma once

#include <vector>

#include <vsg/maths/vec3.h>
#include <vsg/maths/vec4.h>

namespace vsg {
class MatrixTransform;
}
namespace vkv {

class DottedCurve;

vsg::MatrixTransform* createBSpline(const std::vector<vsg::dvec3>& ctrl_points,
                                    const std::vector<double>&     params,
                                    const std::vector<vsg::dvec3>& tangents,
                                    const vsg::dvec4&              color);

DottedCurve* createDottedCurve(const std::vector<vsg::dvec3>& ctrl_points,
                               const std::vector<double>&     params,
                               const std::vector<vsg::dvec3>& tangents);
} // namespace vkv