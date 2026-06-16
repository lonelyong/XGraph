#pragma once

#include <osg/GraphicsThread>

namespace osg {
class GraphicsContext;
}

namespace glv {

class RealizeOperation : public osg::GraphicsOperation {
  public:
    RealizeOperation();

  public:
    virtual void operator()(osg::GraphicsContext* gc) override;
};
} // namespace glv