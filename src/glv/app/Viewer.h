#pragma once
#include <osgViewer/Viewer>

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
    void addCamera(osg::Camera* cam,
                   bool         useMasterSceneData  = false,
                   bool         useMasterViewMatrix = false,
                   bool         useMasterProjMatrix = false,
                   bool         useMasterViewport   = false);

  private:
    struct Data;
    Data* const d;
};
} // namespace glv