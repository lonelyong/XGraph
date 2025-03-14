#include <glr/engine/FrameBufferObject.h>

#include <iostream>
#include <map>

#include <vine/core/Exception.h>
#include <vine/core/Ptr.h>

#include <glr/engine/RenderBuffer.h>
#include <glr/engine/State.h>
#include <glr/engine/Texture2D.h>

namespace glr {
VI_OBJECT_META_IMPL(FrameBufferObject, BindableObject);

struct FrameBufferObject::Data {
    std::map<BufferComponent, vine::RefPtr<PixelData>> components;
};

FrameBufferObject::FrameBufferObject()
  : d(new Data()) {
}

FrameBufferObject::~FrameBufferObject() {
    delete d;
}

void FrameBufferObject::attachRenderBuffer(BufferComponent comp, RenderBuffer* buffer) {
    if (getNbInstances()) {
        throw vine::Exception(vine::Exception::INVALID_OPERATION);
    }
    auto iter = d->components.find(comp);
    if (iter == d->components.end())
        d->components.insert({ comp, buffer });
    else
        iter->second = buffer;
}

void FrameBufferObject::attachTexture(BufferComponent comp, Texture* tex) {
    if (getNbInstances()) {
        throw vine::Exception(vine::Exception::INVALID_OPERATION);
    }
    auto iter = d->components.find(comp);
    if (iter == d->components.end())
        d->components.insert({ comp, tex });
    else
        iter->second = tex;
}

RenderBuffer* FrameBufferObject::getRenderBuffer(BufferComponent comp) const {
    auto iter = d->components.find(comp);
    if (iter == d->components.end()) {
        return nullptr;
    }
    return vine::obj_cast<RenderBuffer>(iter->second.get());
}

Texture* FrameBufferObject::getTexture(BufferComponent comp) const {
    auto iter = d->components.find(comp);
    if (iter == d->components.end()) {
        return nullptr;
    }
    return vine::obj_cast<Texture>(iter->second.get());
}

PixelData* FrameBufferObject::getComponent(BufferComponent comp) const {
    auto iter = d->components.find(comp);
    if (iter == d->components.end()) {
        return nullptr;
    }
    return iter->second.get();
}

GLuint FrameBufferObject::onCreate(State& state) {
    GLuint id;
    glGenFramebuffers(1, &id);
    glBindFramebuffer(GL_FRAMEBUFFER, id);

    for (auto&& kv : d->components) {
        auto& buffer = kv.second;
        buffer->bind(state);
        if (buffer->isKindOf<Texture2D>()) {
            glFramebufferTexture2D(GL_FRAMEBUFFER, kv.first, GL_TEXTURE_2D, buffer->getId(state), 0);
        }
        else if (buffer->isKindOf<RenderBuffer>()) {
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, kv.first, GL_RENDERBUFFER, buffer->getId(state));
        }
        buffer->unbind(state);
    }

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
        std::cerr << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    }

    return id;
}

bool FrameBufferObject::onRelease(State& state) {
    auto id = getId(state);
    glDeleteFramebuffers(1, &id);
    return true;
}

bool FrameBufferObject::onUpdate(State& state) {
    return false;
}

bool FrameBufferObject::onBind(State& state) {
    auto id = getId(state);
    glBindFramebuffer(GL_FRAMEBUFFER, id);
    return true;
}

bool FrameBufferObject::onUnbind(State& state) {
    GLint curr_id = 0;
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &curr_id);
    if (curr_id == getId(state)) {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }
    return true;
}
} // namespace glr