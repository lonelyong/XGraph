#include <xg/igl/engine/BlendColor.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(BlendColor, StateAttribute);

BlendColor::BlendColor() = default;

BlendColor::~BlendColor() = default;

void BlendColor::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglBlendColor(color_.r, color_.g, color_.b, color_.a);
}

} // namespace glr
} // namespace xg