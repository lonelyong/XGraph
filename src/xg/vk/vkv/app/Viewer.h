#pragma once

#include <vsg/app/Camera.h>
#include <vsg/app/Viewer.h>
#include <vsg/nodes/Node.h>

namespace vkv {
class Viewer : public vsg::Inherit<vsg::Viewer, Viewer> {
  public:
    Viewer();
    void run();
    void fitToScreen();
    void addNode(vsg::ref_ptr<vsg::Node> node);

  private:
    struct Data;
    Data* const d;
};
} // namespace vkv