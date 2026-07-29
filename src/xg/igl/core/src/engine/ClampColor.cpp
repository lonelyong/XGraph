#include <xg/igl/engine/ClampColor.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(ClampColor, StateAttribute);

struct ClampColor::Data {};

ClampColor::ClampColor()
  : d(new Data())
{}

ClampColor::~ClampColor()
{}

ClampColor::Type ClampColor::getType() const
{ return CLAMP_COLOR; }

void ClampColor::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

} // namespace glr
} // namespace xg