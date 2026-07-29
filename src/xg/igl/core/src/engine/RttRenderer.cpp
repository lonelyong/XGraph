#include <xg/igl/engine/RttRenderer.hpp>

#include <exception>
#include <iostream>



#include <GLFW/glfw3.h>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/FrameBufferObject.hpp>
#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/RenderInfo.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(RttRenderer, Renderer);

struct RttRenderer::Data {
    vine::RefPtr<FrameBufferObject> fbo = nullptr;
};

RttRenderer::RttRenderer()
  : d(new Data())
{}

RttRenderer::~RttRenderer()
{}

int RttRenderer::render(RenderInfo& info)
{
    if (!d->fbo)
        return -1;

    auto ctx = getContext();

    if (!ctx)
        return -1;

    d->fbo->bind(*ctx->getState());

    auto code = Renderer::render(info);

    d->fbo->unbind(*ctx->getState());
    return code;
}

void RttRenderer::setFbo(FrameBufferObject* fbo)
{ d->fbo = fbo; }

FrameBufferObject* RttRenderer::getFbo() const
{ return d->fbo.get(); }

} // namespace glr
} // namespace xg