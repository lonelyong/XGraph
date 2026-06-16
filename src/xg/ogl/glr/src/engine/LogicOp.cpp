#include <xg/glr/engine/LogicOp.h>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

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