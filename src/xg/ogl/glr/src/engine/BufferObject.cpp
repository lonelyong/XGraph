#include <xg/glr/engine/BufferObject.h>

#include <map>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

namespace glr {
V_OBJECT_META_IMPL(BufferObject, BindableObject);

struct BufferObject::Data {
    std::map<int, bool> dirties;
};

BufferObject::BufferObject()
  : d(new Data()) {
}

GLuint_t BufferObject::onCreate(State& state) {
    auto     funcs = state.getContext()->getFuncs();
    GLuint_t id    = 0;
    funcs->iglGenBuffers(1, &id);
    return id;
}

bool BufferObject::onRelease(State& state) {
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->iglDeleteBuffers(1, &id);
    return true;
}

bool BufferObject::onBind(State& state) {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglBindBuffer(getTarget(), getId(state));
    return true;
}

bool BufferObject::onUnbind(State& state) {
    auto    funcs   = state.getContext()->getFuncs();
    GLint_t curr_id = 0;

    funcs->iglGetIntegerv(getBindingOfTarget(getTarget()), &curr_id);

    if (curr_id == getId(state)) {
        funcs->iglBindBuffer(getTarget(), 0);
    }

    return true;
}

GLenum_t BufferObject::getBindingOfTarget(Target target) {
    switch (target) {
    case ARRAY_BUFFER: return IGL_ARRAY_BUFFER_BINDING;
    case ELEMENT_ARRAY_BUFFER: return IGL_ELEMENT_ARRAY_BUFFER_BINDING;
    case PIXEL_PACK_BUFFER: return IGL_PIXEL_PACK_BUFFER_BINDING;
    case PIXEL_UNPACK_BUFFER: return IGL_PIXEL_UNPACK_BUFFER_BINDING;
    case UNIFORM_BUFFER: return IGL_UNIFORM_BUFFER_BINDING;
    case SHADER_STORAGE_BUFFER: return IGL_SHADER_STORAGE_BUFFER_BINDING;
    case DRAW_INDIRECT_BUFFER: return IGL_DRAW_INDIRECT_BUFFER_BINDING;
    default: return IGL_ZERO;
    }
}
} // namespace glr