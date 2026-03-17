#pragma once

#include <glr/glr_global.h>

#include <glr/engine/Renderer.h>

namespace glr {
class Renderer;
class FrameBufferObject;
class GLR_API RttRenderer : public Renderer {
    V_OBJECT_META_DECL

  public:
    RttRenderer();
    virtual ~RttRenderer();

  public:
    virtual int render(RenderInfo& info) override;

    void setFbo(FrameBufferObject* fbo);

    FrameBufferObject* getFbo() const;

  private:
    struct Data; Data* const d;;
};
}; // namespace glr