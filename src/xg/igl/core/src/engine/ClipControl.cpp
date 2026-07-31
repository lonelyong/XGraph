#include <xg/igl/engine/ClipControl.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(ClipControl, StateAttribute);

ClipControl::ClipControl() = default;

ClipControl::~ClipControl() = default;

void ClipControl::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglClipControl(origin_, depth_);
}

} // namespace glr
} // namespace xg