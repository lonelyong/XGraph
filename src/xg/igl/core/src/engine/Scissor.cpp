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

Scissor::Scissor() = default;

Scissor::Scissor(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : x_(x)
  , y_(y)
  , w_(w)
  , h_(h)
{}

Scissor::~Scissor() = default;

void Scissor::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglScissor(x_, y_, w_, h_);
}

#pragma endregion

#pragma region ScissorIndexed
V_OBJECT_META_IMPL(ScissorIndexed, StateAttribute);

ScissorIndexed::ScissorIndexed() = default;

ScissorIndexed::ScissorIndexed(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : index_(index)
  , x_(x)
  , y_(y)
  , w_(w)
  , h_(h)
{}

ScissorIndexed::~ScissorIndexed() = default;

void ScissorIndexed::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglScissorIndexed(index_, x_, y_, w_, h_);
}

#pragma endregion

#pragma region ScissorArray

V_OBJECT_META_IMPL(ScissorArray, StateAttribute);

ScissorArray::ScissorArray() = default;

ScissorArray::~ScissorArray() = default;

void ScissorArray::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglScissorArrayv(first_, count_, xywh_pairs_.data());
}

#pragma endregion

} // namespace glr
} // namespace xg