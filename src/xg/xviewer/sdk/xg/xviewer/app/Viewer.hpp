#pragma once

#include <osgViewer/Viewer>

#include <xg/xviewer/app/CameraPicker.hpp>

#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE
namespace osgVerse {
class Pipeline;
}
#endif // XG_XVIEWER_BUILD_WITH_OSGVERSE

namespace osg {
class Node;
class Camera;
class GraphicsContext;
} // namespace osg

namespace xg {
namespace xviewer {


class Viewer : public osgViewer::Viewer {
  public:
    Viewer();

  public:
    void addNode(osg::Node* node);
#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE
    void addNodeAsDeferred(osg::Node* node);
    void addNodeAsForward(osg::Node* node);
    void addNodeAsCustom(osg::Node* node);
#endif
    void addSlave(osg::Camera* cam,
                  bool         useMasterSceneData  = false,
                  bool         useMasterViewMatrix = false,
                  bool         useMasterProjMatrix = false,
                  bool         useMasterViewport   = false);

    osg::GraphicsContext* getGraphicsContext() const;

    void fitToScreen();

  private:
    void initPipelineDefault();
#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE
    void initPipelineVerse();
#endif // XG_XVIEWER_BUILD_WITH_OSGVERSE

  private:
    osg::ref_ptr<osg::GraphicsContext> gc_;
    osg::ref_ptr<osg::Group>           root_node_;
    osg::ref_ptr<CameraPicker>         cam_picker_;

#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE
    osg::ref_ptr<osgVerse::Pipeline> pipeline_;
#endif
};
} // namespace xviewer
} // namespace xg