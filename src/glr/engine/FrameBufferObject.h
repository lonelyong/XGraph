#pragma once

#include <glr/glr_global.h>

#include <glr/engine/BindableObject.h>
#include <glr/engine/State.h>

namespace glr {
class RenderBuffer;
class Texture;
class PixelData;

class GLR_API FrameBufferObject : public BindableObject {
    VI_OBJECT_META;

  public:
    enum BufferComponent
    {
        DEPTH_ATTACHMENT         = HGL_DEPTH_ATTACHMENT,
        STENCIL_ATTACHMENT       = HGL_STENCIL_ATTACHMENT,
        DEPTH_STENCIL_ATTACHMENT = HGL_DEPTH_STENCIL_ATTACHMENT,
        COLOR_ATTACHMENT0        = HGL_COLOR_ATTACHMENT0,
        COLOR_ATTACHMENT1        = HGL_COLOR_ATTACHMENT1,
        COLOR_ATTACHMENT2        = HGL_COLOR_ATTACHMENT2,
        COLOR_ATTACHMENT3        = HGL_COLOR_ATTACHMENT3,
        COLOR_ATTACHMENT4        = HGL_COLOR_ATTACHMENT4,
        COLOR_ATTACHMENT5        = HGL_COLOR_ATTACHMENT5,
        COLOR_ATTACHMENT6        = HGL_COLOR_ATTACHMENT6,
        COLOR_ATTACHMENT7        = HGL_COLOR_ATTACHMENT7,
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
    VI_OBJECT_DATA;
};
} // namespace glr