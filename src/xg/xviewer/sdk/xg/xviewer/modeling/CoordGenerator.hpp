#pragma once
#include <osg/Vec3d>

namespace osg {
class MatrixTransform;
class Camera;
} // namespace osg
namespace xg {
namespace xviewer {
osg::MatrixTransform*
createCoord(double cyli_len, double cyli_r, double cone_len, double cone_r, bool auto_rotate_to_screen);

osg::Camera* createHudCoord(osg::Camera* master, double cyli_len, double cyli_r, double cone_len, double cone_r);
} // namespace xviewer
} // namespace xg