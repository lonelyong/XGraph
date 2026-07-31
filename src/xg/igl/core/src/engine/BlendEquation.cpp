#include <xg/igl/engine/BlendEquation.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

#pragma region BlendEquation
V_OBJECT_META_IMPL(BlendEquation, StateAttribute);

BlendEquation::BlendEquation() = default;

BlendEquation::BlendEquation(Equation equation)
{ setEquation(equation); }

BlendEquation::~BlendEquation() = default;

void BlendEquation::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    if (equation_alpha_ == equation_rgb_) { funcs->oglBlendEquation(equation_rgb_); }
    else {
        // funcs->oglBlendEquationSeparate(equation_rgb_, equation_alpha_);
    }
}

#pragma endregion

#pragma region BlendEquationi
V_OBJECT_META_IMPL(BlendEquationi, BlendEquation);

BlendEquationi::BlendEquationi() = default;

BlendEquationi::BlendEquationi(GLuint_t buf, Equation equation)
  : BlendEquation(equation)
  , index_(buf)
{}

BlendEquationi::~BlendEquationi() = default;


void BlendEquationi::apply(State& state) const
{
    auto funcs          = state.getContext()->getFuncs();
    auto equation_rgb   = getEquationRGB();
    auto equation_alpha = getEquationAlpha();
    if (equation_rgb == equation_alpha) { funcs->oglBlendEquationi(index_, equation_rgb); }
    else {
        funcs->oglBlendEquationSeparatei(index_, equation_rgb, equation_alpha);
    }
}

#pragma endregion

} // namespace glr
} // namespace xg