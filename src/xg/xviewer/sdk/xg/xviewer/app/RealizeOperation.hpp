#pragma once

#include <osg/GraphicsThread>

namespace osg {
class GraphicsContext;
}

namespace xg {
namespace xviewer {

class RealizeOperation : public osg::GraphicsOperation {
  public:
    RealizeOperation();

  public:
    virtual void operator()(osg::GraphicsContext* gc) override;
};
} // namespace xviewer
} // namespace xg