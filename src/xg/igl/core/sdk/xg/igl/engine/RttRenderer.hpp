#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/Renderer.hpp>

namespace xg
{
namespace glr
{

class Renderer;
class FrameBufferObject;

class IGL_CORE_API RttRenderer : public Renderer {
    V_OBJECT_META_DECL

  public:
    RttRenderer();
    virtual ~RttRenderer();

  public:
    virtual int render(RenderInfo& info) override;

    void setFbo(FrameBufferObject* fbo);

    FrameBufferObject* getFbo() const;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg