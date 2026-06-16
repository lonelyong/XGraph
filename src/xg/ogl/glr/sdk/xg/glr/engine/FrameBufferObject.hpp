#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/BindableObject.h>
#include <xg/glr/engine/State.h>

namespace glr {
class RenderBuffer;
class Texture;
class PixelData;

class GLR_API FrameBufferObject : public BindableObject {
    V_OBJECT_META_DECL

  public:
    enum BufferComponent
    {
        DEPTH_ATTACHMENT         = IGL_DEPTH_ATTACHMENT,
        STENCIL_ATTACHMENT       = IGL_STENCIL_ATTACHMENT,
        DEPTH_STENCIL_ATTACHMENT = IGL_DEPTH_STENCIL_ATTACHMENT,
        COLOR_ATTACHMENT0        = IGL_COLOR_ATTACHMENT0,
        COLOR_ATTACHMENT1        = IGL_COLOR_ATTACHMENT1,
        COLOR_ATTACHMENT2        = IGL_COLOR_ATTACHMENT2,
        COLOR_ATTACHMENT3        = IGL_COLOR_ATTACHMENT3,
        COLOR_ATTACHMENT4        = IGL_COLOR_ATTACHMENT4,
        COLOR_ATTACHMENT5        = IGL_COLOR_ATTACHMENT5,
        COLOR_ATTACHMENT6        = IGL_COLOR_ATTACHMENT6,
        COLOR_ATTACHMENT7        = IGL_COLOR_ATTACHMENT7,
    };

  public:
    FrameBufferObject();
    virtual ~FrameBufferObject();

  public:
    void attachRenderBuffer(BufferComponent comp, RenderBuffer* buffer);
    void attachTexture(BufferComponent comp, Texture* tex);

    RenderBuffer* getRenderBuffer(BufferComponent comp) const;
    Texture*      getTexture(BufferComponent comp) const;
    PixelData*    getComponent(BufferComponent comp) const;

  protected:
    virtual GLuint_t onCreate(State& state) override;
    virtual bool     onRelease(State& state) override;
    virtual bool     onUpdate(State& state) override;
    virtual bool     onBind(State& state) override;
    virtual bool     onUnbind(State& state) override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr