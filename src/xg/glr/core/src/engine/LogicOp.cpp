#include <xg/glr/engine/LogicOp.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

namespace xg {
namespace glr {

V_OBJECT_META_IMPL(LogicOp, StateAttribute);

struct LogicOp::Data {};

LogicOp::LogicOp()
  : d(new Data()) {
}

LogicOp::~LogicOp() {
}

LogicOp::Type LogicOp::getType() const {
    return LOGICOP;
}

void LogicOp::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
}

} // namespace glr
} // namespace xg