#include <xg/igl/engine/LogicOp.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(LogicOp, StateAttribute);

LogicOp::LogicOp() = default;

LogicOp::~LogicOp() = default;

void LogicOp::apply(State& state) const
{ auto funcs = state.getContext()->getFuncs(); }

} // namespace glr
} // namespace xg