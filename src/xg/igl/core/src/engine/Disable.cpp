#include <xg/igl/engine/Disable.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Disable, StateAttribute);

struct Disable::Data {};

Disable::Disable()
  : d(new Data())
{}

Disable::~Disable()
{}

Disable::Type Disable::getType() const
{ return DISABLE; }

void Disable::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

} // namespace glr
} // namespace xg