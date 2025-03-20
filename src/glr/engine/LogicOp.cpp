#include <glr/engine/LogicOp.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

VI_OBJECT_META_IMPL(LogicOp, StateAttribute);

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