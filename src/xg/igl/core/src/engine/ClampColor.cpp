#include <xg/igl/engine/ClampColor.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(ClampColor, StateAttribute);

ClampColor::ClampColor() = default;

ClampColor::~ClampColor() = default;

void ClampColor::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

} // namespace glr
} // namespace xg