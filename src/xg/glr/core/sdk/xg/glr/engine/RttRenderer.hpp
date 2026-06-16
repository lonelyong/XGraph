#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/Renderer.h>

namespace xg {
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
} // namespace glr
} // namespace xg