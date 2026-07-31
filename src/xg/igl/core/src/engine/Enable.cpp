#include <xg/igl/engine/Enable.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Enable, StateAttribute);

Enable::Enable() = default;

Enable::~Enable() = default;

void Enable::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

} // namespace glr
} // namespace xg