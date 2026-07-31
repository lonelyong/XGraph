#include <xg/igl/engine/Viewport.hpp>

#include <vector>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

#pragma region Viewport
V_OBJECT_META_IMPL(Viewport, StateAttribute);

Viewport::Viewport() = default;

Viewport::Viewport(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : x_(x)
  , y_(y)
  , w_(w)
  , h_(h)
{}

Viewport::~Viewport() = default;

void Viewport::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglViewport(x_, y_, w_, h_);
}

#pragma endregion

#pragma region ViewportIndexed
V_OBJECT_META_IMPL(ViewportIndexed, StateAttribute);

ViewportIndexed::ViewportIndexed() = default;

ViewportIndexed::ViewportIndexed(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h)
  : index_(index)
  , x_(x)
  , y_(y)
  , w_(w)
  , h_(h)
{}

ViewportIndexed::~ViewportIndexed() = default;

void ViewportIndexed::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglViewportIndexedf(index_, x_, y_, w_, h_);
}

#pragma endregion

#pragma region ViewportArray

V_OBJECT_META_IMPL(ViewportArray, StateAttribute);

ViewportArray::ViewportArray() = default;

ViewportArray::~ViewportArray() = default;

void ViewportArray::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglViewportArrayv(first_, count_, xywh_pairs_.data());
}

#pragma endregion

} // namespace glr
} // namespace xg