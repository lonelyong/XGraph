#pragma once

#include <osg/Camera>

namespace glv {
class Viewer;
class PickerCamera : public osg::Camera {
  public:
    PickerCamera();
    virtual ~PickerCamera();

  public:
  private:
    struct Data;
    Data* const d;
};
} // namespace glv