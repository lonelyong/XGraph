#include <glr/engine/RenderBuffer.h>

#include <vine/core/Ptr.h>

#include <glr/engine/FrameBufferObject.h>
#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

namespace {
struct RenderBufferData {
    vine::RefPtr<FrameBufferObject> fbo = nullptr;
    GLuint_t                        w   = 1920;
    GLuint_t                        h   = 1080;
};
} // namespace

void RenderBuffer_set_FrameBuffer(void* data, FrameBufferObject* fbo) {
    auto d = (RenderBufferData*)data;
    d->fbo = fbo;
}

VI_OBJECT_META_IMPL(RenderBuffer, PixelData);

struct RenderBuffer::Data : public RenderBufferData {};

RenderBuffer::RenderBuffer()
  : d(new Data()) {
}

FrameBufferObject* RenderBuffer::getFrameBuffer() const {
    return d->fbo.get();
}

void RenderBuffer::setWidth(GLsizei_t w) {
    d->w = w;
}

void RenderBuffer::setHeight(GLsizei_t h) {
    d->h = h;
}

GLsizei_t RenderBuffer::getWidth() const {
    return d->w;
}

GLsizei_t RenderBuffer::getHeight() const {
    return d->h;
}

bool RenderBuffer::onUpdate(State& state) {
    return false;
}

bool RenderBuffer::onBind(State& state) {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglBindRenderbuffer(IGL_RENDERBUFFER, getId(state));
    return true;
}

bool RenderBuffer::onUnbind(State& state) {
    auto    funcs   = state.getContext()->getFuncs();
    GLint_t curr_id = 0;
    funcs->iglGetIntegerv(IGL_RENDERBUFFER_BINDING, &curr_id);
    if (curr_id == getId(state)) {
        funcs->iglBindRenderbuffer(IGL_RENDERBUFFER, 0);
    }
    return true;
}

GLuint_t RenderBuffer::onCreate(State& state) {
    auto     funcs = state.getContext()->getFuncs();
    GLuint_t id;
    funcs->iglGenRenderbuffers(1, &id);
    funcs->iglBindRenderbuffer(IGL_RENDERBUFFER, id);
    funcs->iglRenderbufferStorage(IGL_RENDERBUFFER, IF_RGBA, d->w, d->h);
    return id;
}

bool RenderBuffer::onRelease(State& state) {
    auto funcs = state.getContext()->getFuncs();
    auto id = getId(state);
    funcs->iglDeleteRenderbuffers(1, &id);
    return true;
}
} // namespace glr