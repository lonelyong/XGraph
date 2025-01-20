#pragma once

#include <vector>

#include <osg/Vec3>
#include <osg/Vec4>

namespace osg {
class MatrixTransform;
}
namespace glv {

class DottedCurve;

osg::MatrixTransform* createBSpline(const std::vector<osg::Vec3>& ctrl_points,
                                    const std::vector<double>&     params,
                                    const std::vector<osg::Vec3>& tangents,
                                    const osg::Vec4&               color);

DottedCurve* createDottedCurve(const std::vector<osg::Vec3>& ctrl_points,
                              const std::vector<double>&     params,
                              const std::vector<osg::Vec3>& tangents);
} // namespace glv