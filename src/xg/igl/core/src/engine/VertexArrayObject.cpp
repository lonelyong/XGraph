#include <xg/igl/engine/VertexArrayObject.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

V_OBJECT_META_IMPL(xg::glr::VertexArrayObject, xg::glr::BindableObject);
V_OBJECT_META_IMPL(xg::glr::VertexAttribPointer, xg::glr::Object);
V_OBJECT_META_IMPL(xg::glr::VertexAttribFormat, xg::glr::Object);
V_OBJECT_META_IMPL(xg::glr::VertexAttribBinding, xg::glr::Object);
V_OBJECT_META_IMPL(xg::glr::VertexAttribDivisor, xg::glr::Object);

namespace xg
{
namespace glr
{

VertexAttribPointer::VertexAttribPointer(GLuint_t index, GLint_t size, GLenum_t type, GLboolean_t normalized, GLsizei_t stride, const GLvoid_t* pointer)
  : index_(index)
  , size_(size)
  , type_(type)
  , normalized_(normalized)
  , stride_(stride)
  , pointer_(pointer)
{}

void VertexAttribPointer::apply(BufferObject* buffer)
{}

VertexAttribFormat::VertexAttribFormat(GLuint_t attribindex, GLint_t size, GLenum_t type, GLboolean_t normalized, GLuint_t relativeoffset)
{}

VertexAttribBinding::VertexAttribBinding() = default;

VertexAttribDivisor::VertexAttribDivisor() = default;

void VertexArrayObject::attachBufferObject(BufferObject* buffer)
{}

void VertexArrayObject::detachBufferObject(BufferObject* buffer)
{}

void VertexArrayObject::setAttribPointer(BufferObject* buffer, VertexAttribPointer* pointer)
{}

VertexAttribPointer* VertexArrayObject::getAttribPointer(BufferObject* buffer)
{ return nullptr; }

VertexArrayObject::VertexArrayObject() = default;

VertexArrayObject::~VertexArrayObject() = default;

GLuint_t VertexArrayObject::onCreate(State& state)
{
    auto     funcs = state.getContext()->getFuncs();
    GLuint_t vao;
    funcs->oglGenVertexArrays(1, &vao);
    return vao;
}

bool VertexArrayObject::onBind(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->oglBindVertexArray(id);
    return true;
}

bool VertexArrayObject::onUnbind(State& state)
{
    auto    funcs   = state.getContext()->getFuncs();
    GLint_t curr_id = 0;
    funcs->oglGetIntegerv(IGL_VERTEX_ARRAY_BINDING, &curr_id);
    if (curr_id == getId(state)) { funcs->oglBindVertexArray(0); }
    return true;
}

bool VertexArrayObject::onUpdate(State& state)
{ return false; }

bool VertexArrayObject::onRelease(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->oglDeleteVertexArrays(1, &id);
    return true;
}

} // namespace glr
} // namespace xg