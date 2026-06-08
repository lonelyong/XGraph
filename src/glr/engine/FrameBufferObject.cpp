#include <glr/engine/FrameBufferObject.h>

#include <iostream>
#include <map>

#include <vine/Exception.hpp>
#include <vine/Ptr.hpp>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/RenderBuffer.h>
#include <glr/engine/State.h>
#include <glr/engine/Texture2D.h>
#include <glr/igl/GLfuncs.h>

namespace glr {
V_OBJECT_META_IMPL(FrameBufferObject, BindableObject);

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
    if (getNumInstances()) {
        throw vine::Exception(vine::Exception::INVALID_OPERATION);
    }
    auto iter = d->components.find(comp);
    if (iter == d->components.end())
        d->components.insert({ comp, buffer });
    else
        iter->second = buffer;
}

void FrameBufferObject::attachTexture(BufferComponent comp, Texture* tex) {
    if (getNumInstances()) {
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

GLuint_t FrameBufferObject::onCreate(State& state) {
    auto funcs = state.getContext()->getFuncs();

    GLuint_t id;
    funcs->iglGenFramebuffers(1, &id);
    funcs->iglBindFramebuffer(IGL_FRAMEBUFFER, id);

    for (auto&& kv : d->components) {
        auto& buffer = kv.second;
        buffer->bind(state);
        if (buffer->isKindOf<Texture2D>()) {
            funcs->iglFramebufferTexture2D(IGL_FRAMEBUFFER, kv.first, IGL_TEXTURE_2D, buffer->getId(state), 0);
        }
        else if (buffer->isKindOf<RenderBuffer>()) {
            funcs->iglFramebufferRenderbuffer(IGL_FRAMEBUFFER, kv.first, IGL_RENDERBUFFER, buffer->getId(state));
        }
        buffer->unbind(state);
    }

    if (funcs->iglCheckFramebufferStatus(IGL_FRAMEBUFFER) != IGL_FRAMEBUFFER_COMPLETE) {
        std::cerr << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;
    }

    return id;
}

bool FrameBufferObject::onRelease(State& state) {
    auto id    = getId(state);
    auto funcs = state.getContext()->getFuncs();
    funcs->iglDeleteFramebuffers(1, &id);
    return true;
}

bool FrameBufferObject::onUpdate(State& state) {
    return false;
}

bool FrameBufferObject::onBind(State& state) {
    auto id    = getId(state);
    auto funcs = state.getContext()->getFuncs();
    funcs->iglBindFramebuffer(IGL_FRAMEBUFFER, id);
    return true;
}

bool FrameBufferObject::onUnbind(State& state) {
    GLint_t curr_id = 0;
    auto    funcs   = state.getContext()->getFuncs();
    funcs->iglGetIntegerv(IGL_FRAMEBUFFER_BINDING, &curr_id);
    if (curr_id == getId(state)) {
        funcs->iglBindFramebuffer(IGL_FRAMEBUFFER, 0);
    }
    return true;
}
} // namespace glr