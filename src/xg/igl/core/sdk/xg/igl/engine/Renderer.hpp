#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/EventReceiver.hpp>

namespace xg
{
namespace glr
{

class Program;
class Model;
class Camera;
class CameraManipulator;
class GraphicContext;
class Scene;
class RenderInfo;
class Event;

class IGL_CORE_API Renderer : public EventReceiver {
    V_OBJECT_META_DECL

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
    Camera*     getCamera() const;
    void        setCamera(Camera* cam);

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
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg
