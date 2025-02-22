#pragma once

#include <vkr/vkr_global.h>

#include <vkr/engine/EventReceiver.h>

namespace vkr {
class Shader;
class Model;
class Camera;
class CameraManipulator;
class GraphicContext;
class Scene;
class RenderInfo;
class Event;

class VKR_API Renderer : public EventReceiver {
    VI_OBJECT_META;

  public:
    enum RenderOrder
    {
        PRE_RENDER,
        MID_RENDER,
        POST_RENDER,
    };

  public:
    Renderer();
    virtual ~Renderer();

  public:
    virtual int render(RenderInfo& info);

    Camera* getCamera() const;
    void    setCamera(Camera* cam);

    GraphicContext* getContext() const;
    void            setContext(GraphicContext* ctx);

    CameraManipulator* getCameraManipulator() const;
    void               setCameraManipulator(CameraManipulator* cm);

    void        setRenderOrder(RenderOrder order);
    RenderOrder getRenderOrder() const;

    void   setScene(Scene* scene);
    Scene* getScene() const;

    void setUseMasterScene(bool val);
    bool getUseMasterScene() const;

    void setUseMasterViewport(bool val);
    bool getUseMasterViewport() const;

    void setUseMasterViewMatrix(bool val);
    bool getUseMasterViewMatrix() const;

    void setUseMasterProjectionMatrix(bool val);
    bool getUseMasterProjectionMatrix() const;

    void setFreeze(bool val);
    bool getFreezed() const;

    virtual bool handleEvent(Event* e) override;
    virtual void update(UpdateContext* ctx) override;

  private:
    VI_OBJECT_DATA;
};

} // namespace vkr
