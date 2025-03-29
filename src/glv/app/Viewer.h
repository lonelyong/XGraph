#pragma once
#include <osgViewer/Viewer>

#include "CameraPicker.h"

namespace osg {
class Node;
class Camera;
} // namespace osg

namespace glv {
class Viewer : public osgViewer::Viewer {
  public:
    Viewer();

  public:
    void fitToScreen();
    void addNode(osg::Node* node);
    void addSlave(osg::Camera* cam,
                  bool         useMasterSceneData  = false,
                  bool         useMasterViewMatrix = false,
                  bool         useMasterProjMatrix = false,
                  bool         useMasterViewport   = false);

  private:
    osg::ref_ptr<osg::Group>   root_node;
    osg::ref_ptr<CameraPicker> cam_picker;
};
} // namespace glv