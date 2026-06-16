#pragma once

#include <osg/Camera>

namespace osg {
class Texture2D;
}

namespace glv {

class CameraPicker : public osg::Camera {
  public:
    CameraPicker();
    virtual ~CameraPicker();

  public:
  private:
    osg::ref_ptr<osg::Texture2D> color_buf0;
    osg::ref_ptr<osg::Texture2D> depth_buf;
};
} // namespace glv