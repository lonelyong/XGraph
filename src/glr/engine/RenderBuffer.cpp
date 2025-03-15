#include <glr/engine/RenderBuffer.h>

#include <glad/glad.h>

#include <vine/core/Ptr.h>

#include <glr/engine/FrameBufferObject.h>

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

void RenderBuffer::setWidth(GLsizei w) {
    d->w = w;
}

void RenderBuffer::setHeight(GLsizei h) {
    d->h = h;
}

GLsizei RenderBuffer::getWidth() const {
    return d->w;
}

GLsizei RenderBuffer::getHeight() const {
    return d->h;
}

bool RenderBuffer::onUpdate(State& state) {
    return false;
}

bool RenderBuffer::onBind(State& state) {
    glBindRenderbuffer(GL_RENDERBUFFER, getId(state));
    return true;
}

bool RenderBuffer::onUnbind(State& state) {
    GLint curr_id = 0;
    glGetIntegerv(GL_RENDERBUFFER_BINDING, &curr_id);
    if (curr_id == getId(state)) {
        glBindRenderbuffer(GL_RENDERBUFFER, 0);
    }
    return true;
}

GLuint_t RenderBuffer::onCreate(State& state) {
    GLuint_t id;
    glGenRenderbuffers(1, &id);
    glBindRenderbuffer(GL_RENDERBUFFER, id);
    glRenderbufferStorage(GL_RENDERBUFFER, IF_RGBA, d->w, d->h);
    return id;
}

bool RenderBuffer::onRelease(State& state) {
    auto id = getId(state);
    glDeleteRenderbuffers(1, &id);
    return true;
}
} // namespace glr