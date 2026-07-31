#include <xg/igl/engine/ColorMask.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

#pragma region ColorMask

V_OBJECT_META_IMPL(ColorMask, StateAttribute);

ColorMask::ColorMask() = default;

ColorMask::ColorMask(bool red, bool green, bool blue, bool alpha)
{ setMask(red, green, blue, alpha); }

ColorMask::~ColorMask() = default;

void ColorMask::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglColorMask(r_, g_, b_, a_);
}

#pragma endregion

#pragma region ColorMaski

V_OBJECT_META_IMPL(ColorMaski, ColorMask);

ColorMaski::ColorMaski() = default;

ColorMaski::ColorMaski(GLuint_t buf, bool red, bool green, bool blue, bool alpha)
  : ColorMask(red, green, blue, alpha)
  , index_(buf)
{}

ColorMaski::~ColorMaski() = default;

void ColorMaski::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglColorMaski(index_, getRed(), getGreen(), getBlue(), getAlpha());
}

#pragma endregion

} // namespace glr
} // namespace xg