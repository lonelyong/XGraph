#pragma once

#include <osg/GraphicsThread>

namespace osg {
class GraphicsContext;
}

namespace xviewer {

class RealizeOperation : public osg::GraphicsOperation {
  public:
    RealizeOperation();

  public:
    virtual void operator()(osg::GraphicsContext* gc) override;
};
} // namespace xviewer