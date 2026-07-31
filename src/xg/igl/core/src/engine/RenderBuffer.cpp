#include <xg/igl/engine/RenderBuffer.hpp>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/FrameBufferObject.hpp>
#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

void RenderBuffer_set_FrameBuffer(RenderBuffer* rb, FrameBufferObject* fbo)
{
    rb->fbo_ = fbo;
}

V_OBJECT_META_IMPL(RenderBuffer, PixelData);

RenderBuffer::RenderBuffer() = default;

bool RenderBuffer::onUpdate(State& state)
{ return false; }

bool RenderBuffer::onBind(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglBindRenderbuffer(IGL_RENDERBUFFER, getId(state));
    return true;
}

bool RenderBuffer::onUnbind(State& state)
{
    auto    funcs   = state.getContext()->getFuncs();
    GLint_t curr_id = 0;
    funcs->oglGetIntegerv(IGL_RENDERBUFFER_BINDING, &curr_id);
    if (curr_id == getId(state)) { funcs->oglBindRenderbuffer(IGL_RENDERBUFFER, 0); }
    return true;
}

GLuint_t RenderBuffer::onCreate(State& state)
{
    auto     funcs = state.getContext()->getFuncs();
    GLuint_t id;
    funcs->oglGenRenderbuffers(1, &id);
    funcs->oglBindRenderbuffer(IGL_RENDERBUFFER, id);
    funcs->oglRenderbufferStorage(IGL_RENDERBUFFER, IF_RGBA, w_, h_);
    return id;
}

bool RenderBuffer::onRelease(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->oglDeleteRenderbuffers(1, &id);
    return true;
}

} // namespace glr
} // namespace xg