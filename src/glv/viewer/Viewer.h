#pragma once

namespace osg {
class Node;
class Camera;
} // namespace osg

namespace glv {
class Viewer {
  public:
    Viewer();
    void         run();
    void         fitToScreen();
    void         addNode(osg::Node* node);
    void         addCamera(osg::Camera* cam,
                           bool         useMasterSceneData  = false,
                           bool         useMasterViewMatrix = false,
                           bool         useMasterProjMatrix = false,
                           bool         useMasterViewport   = false);
    osg::Camera* getMasterCamera() const;

  private:
    struct Data;
    Data* const d;
};
} // namespace glv