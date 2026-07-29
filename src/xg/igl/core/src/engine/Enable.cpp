#include <xg/igl/engine/Enable.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Enable, StateAttribute);

struct Enable::Data {};

Enable::Enable()
  : d(new Data())
{}

Enable::~Enable()
{}

Enable::Type Enable::getType() const
{ return ENABLE; }

void Enable::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

} // namespace glr
} // namespace xg