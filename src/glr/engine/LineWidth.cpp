#include <glr/engine/LineWidth.h>

namespace glr {

VI_OBJECT_META_IMPL(LineWidth, StateAttribute);

struct LineWidth::Data {};

LineWidth::LineWidth()
  : d(new Data()) {
}

LineWidth::~LineWidth() {
}

LineWidth::Type LineWidth::getType() const {
    return LINE_WIDTH;
}

void LineWidth::apply(State& state) const {
}

} // namespace glr