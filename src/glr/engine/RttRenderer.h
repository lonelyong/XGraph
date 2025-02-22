#pragma once

#include <glr/glr_global.h>

#include <glr/engine/Renderer.h>

namespace glr {
class Renderer;
class FrameBufferObject;
class GLR_API RttRenderer : public Renderer {
    VI_OBJECT_META;

  public:
    RttRenderer();
    virtual ~RttRenderer();

  public:
    virtual int render(RenderInfo& info) override;

    void setFbo(FrameBufferObject* fbo);

    FrameBufferObject* getFbo() const;

  private:
    VI_OBJECT_DATA;
};
}; // namespace glr