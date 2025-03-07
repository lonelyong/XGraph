#include <glr/engine/VertexArrayObject.h>

VI_OBJECT_META_IMPL(glr::VertexArrayObject, glr::BindableObject);
VI_OBJECT_META_IMPL(glr::VertexAttribPointer, glr::Object);
VI_OBJECT_META_IMPL(glr::VertexAttribFormat, glr::Object);
VI_OBJECT_META_IMPL(glr::VertexAttribBinding, glr::Object);
VI_OBJECT_META_IMPL(glr::VertexAttribDivisor, glr::Object);

namespace glr {

struct VertexAttribPointer::Data {
    GLuint        index;
    GLint         size;
    GLenum        type;
    GLboolean     normalized;
    GLsizei       stride;
    const GLvoid* pointer;
};
VertexAttribPointer::VertexAttribPointer(GLuint        index,
                                         GLint         size,
                                         GLenum        type,
                                         GLboolean     normalized,
                                         GLsizei       stride,
                                         const GLvoid* pointer)
  : d(new Data({ index, size, type, normalized, stride, pointer })) {
}

void VertexAttribPointer::apply(BufferObject* buffer) {
}


struct VertexAttribFormat::Data {};
VertexAttribFormat::VertexAttribFormat(GLuint    attribindex,
                                       GLint     size,
                                       GLenum    type,
                                       GLboolean normalized,
                                       GLuint    relativeoffset)
  : d(new Data()) {
}
struct VertexAttribBinding::Data {};
VertexAttribBinding::VertexAttribBinding()
  : d(new Data()) {
}

struct VertexAttribDivisor::Data {};
VertexAttribDivisor::VertexAttribDivisor()
  : d(new Data()) {
}

struct VertexArrayObject::Data {};
void VertexArrayObject::attachBufferObject(BufferObject* buffer) {
}
void VertexArrayObject::detachBufferObject(BufferObject* buffer) {
}
void VertexArrayObject::setAttribPointer(BufferObject* buffer, VertexAttribPointer* pointer) {
}
VertexAttribPointer* VertexArrayObject::getAttribPointer(BufferObject* buffer) {
    return nullptr;
}
VertexArrayObject::VertexArrayObject()
  : d(new Data()) {
}
VertexArrayObject::~VertexArrayObject() {
    delete d;
}
GLuint VertexArrayObject::onCreate(State& state) {
    GLuint vao;
    glGenVertexArrays(1, &vao);
    return vao;
}
bool VertexArrayObject::onBind(State& state) {
    auto id = getId(state);
    glBindVertexArray(id);
    return true;
}
bool VertexArrayObject::onUnbind(State& state) {
    GLint curr_id = 0;
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &curr_id);
    if (curr_id == getId(state)) {
        glBindVertexArray(0);
    }
    return true;
}
bool VertexArrayObject::onUpdate(State& state) {
    return false;
}
bool VertexArrayObject::onRelease(State& state) {
    auto id = getId(state);
    glDeleteVertexArrays(1, &id);
    return true;
}
} // namespace glr