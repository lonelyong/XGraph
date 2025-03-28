#pragma once
#include <osgViewer/Viewer>

#include "PickerCamera.h"

namespace osg {
class Node;
class Camera;
} // namespace osg

namespace glv {
class Viewer : public osgViewer::Viewer {
  public:
    Viewer();
    void fitToScreen();
    void addNode(osg::Node* node);
    void addSlave(osg::Camera* cam,
                  bool         useMasterSceneData  = false,
                  bool         useMasterViewMatrix = false,
                  bool         useMasterProjMatrix = false,
                  bool         useMasterViewport   = false);

  private:
    osg::ref_ptr<osg::Group>   root_node;
    osg::ref_ptr<PickerCamera> picker_cam;
};
} // namespace glv