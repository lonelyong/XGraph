#include <xg/igl/engine/Scissor.hpp>

#include <vector>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

#pragma region Scissor
V_OBJECT_META_IMPL(Scissor, StateAttribute);

struct Scissor::Data {
    GLint_t   x = 0, y = 0;
    GLsizei_t w = 1, h = 1;
};

Scissor::Scissor()
  : d(new Data())
{}

Scissor::Scissor(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : d(new Data())
{

    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}

Scissor::~Scissor()
{ delete d; }

Scissor::Type Scissor::getType() const
{ return SCISSOR; }

void Scissor::set(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
{
    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}

void Scissor::get(GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h)
{
    o_x = d->x;
    o_y = d->y;
    o_w = d->w;
    o_h = d->h;
}

void Scissor::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglScissor(d->x, d->y, d->w, d->h);
}

#pragma endregion

#pragma region ScissorIndexed
V_OBJECT_META_IMPL(ScissorIndexed, StateAttribute);

struct ScissorIndexed::Data {
    GLuint_t  index = 0;
    GLint_t   x = 0, y = 0;
    GLsizei_t w = 1, h = 1;
};

ScissorIndexed::ScissorIndexed()
  : d(new Data())
{}

ScissorIndexed::ScissorIndexed(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : d(new Data())
{

    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}

ScissorIndexed::~ScissorIndexed()
{ delete d; }

ScissorIndexed::Type ScissorIndexed::getType() const
{ return SCISSOR_INDEXED; }

void ScissorIndexed::set(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
{
    d->index = index;
    d->x     = x;
    d->y     = y;
    d->w     = w;
    d->h     = h;
}

void ScissorIndexed::get(GLuint_t& o_index, GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h)
{
    o_index = d->index;
    o_x     = d->x;
    o_y     = d->y;
    o_w     = d->w;
    o_h     = d->h;
}

void ScissorIndexed::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglScissorIndexed(d->index, d->x, d->y, d->w, d->h);
}

#pragma endregion

#pragma region ScissorArray

V_OBJECT_META_IMPL(ScissorArray, StateAttribute);

struct ScissorArray::Data {
    GLuint_t             first = 0;
    GLsizei_t            count = 0;
    std::vector<GLint_t> xywh_pairs;
};

ScissorArray::ScissorArray()
  : d(new Data())
{}

ScissorArray::~ScissorArray()
{ delete d; }

ScissorArray::Type ScissorArray::getType() const
{ return SCISSOR_ARRAY; }

void ScissorArray::setFirst(GLuint_t first)
{ d->first = first; }

GLuint_t ScissorArray::getFirst() const
{ return d->first; }

void ScissorArray::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglScissorArrayv(d->first, d->count, d->xywh_pairs.data());
}

#pragma endregion

} // namespace glr
} // namespace xg