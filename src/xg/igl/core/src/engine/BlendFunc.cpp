#include <xg/igl/engine/BlendFunc.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

#pragma region BlendFunc

V_OBJECT_META_IMPL(BlendFunc, StateAttribute);

BlendFunc::BlendFunc() = default;

BlendFunc::BlendFunc(Func source, Func dest)
{
    setSource(source);
    setDestination(dest);
}

BlendFunc::~BlendFunc() = default;

void BlendFunc::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    if (source_alpha_ != source_rgb_ || dest_alpha_ != dest_rgb_) {
        funcs->oglBlendFuncSeparate(source_rgb_, dest_rgb_, source_alpha_, dest_alpha_);
    }
    funcs->oglBlendFunc(source_rgb_, dest_rgb_);
}

#pragma endregion

#pragma region BlendFunci

V_OBJECT_META_IMPL(BlendFunci, BlendFunc);

BlendFunci::BlendFunci() = default;

BlendFunci::BlendFunci(GLuint_t buf, Func source, Func dest)
  : BlendFunc(source, dest)
  , index_(buf)
{}

BlendFunci::~BlendFunci() = default;

void BlendFunci::apply(State& state) const
{
    auto funcs        = state.getContext()->getFuncs();
    auto source_alpha = getSourceAlpha();
    auto source_rgb   = getSourceRGB();
    auto dest_alpha   = getDestinationAlpha();
    auto dest_rgb     = getDestinationRGB();

    if (source_alpha != source_rgb || dest_alpha != dest_rgb) { funcs->oglBlendFuncSeparatei(index_, source_rgb, dest_rgb, source_alpha, dest_alpha); }
    funcs->oglBlendFunci(index_, source_rgb, dest_rgb);
}

#pragma endregion

} // namespace glr
} // namespace xg