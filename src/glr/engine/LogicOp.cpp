#include <glr/engine/LogicOp.h>

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
}

} // namespace glr