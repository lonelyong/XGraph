#include <glr/engine/BufferObject.h>

#include <map>

#include <glad/glad.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>

namespace glr {
VI_OBJECT_META_IMPL(BufferObject, BindableObject);

struct BufferObject::Data {
    std::map<int, bool> dirties;
};

BufferObject::BufferObject()
  : d(new Data()) {
}

GLuint_t BufferObject::onCreate(State& state) {
    GLuint_t id = 0;
    glGenBuffers(1, &id);
    return id;
}

bool BufferObject::onRelease(State& state) {
    auto id = getId(state);
    glDeleteBuffers(1, &id);
    return true;
}

bool BufferObject::onBind(State& state) {
    glBindBuffer(getTarget(), getId(state));
    return true;
}

bool BufferObject::onUnbind(State& state) {
    GLint curr_id = 0;

    glGetIntegerv(getBindingOfTarget(getTarget()), &curr_id);

    if (curr_id == getId(state)) {
        glBindBuffer(getTarget(), 0);
    }

    return true;
}

GLenum_t BufferObject::getBindingOfTarget(Target target) {
    switch (target) {
    case ARRAY_BUFFER: return GL_ARRAY_BUFFER_BINDING;
    case ELEMENT_ARRAY_BUFFER: return GL_ELEMENT_ARRAY_BUFFER_BINDING;
    case PIXEL_PACK_BUFFER: return GL_PIXEL_PACK_BUFFER_BINDING;
    case PIXEL_UNPACK_BUFFER: return GL_PIXEL_UNPACK_BUFFER_BINDING;
    case UNIFORM_BUFFER: return GL_UNIFORM_BUFFER_BINDING;
    case SHADER_STORAGE_BUFFER: return GL_SHADER_STORAGE_BUFFER_BINDING;
    case DRAW_INDIRECT_BUFFER: return GL_DRAW_INDIRECT_BUFFER_BINDING;
    default: IGL_ZERO;
    }
}
} // namespace glr