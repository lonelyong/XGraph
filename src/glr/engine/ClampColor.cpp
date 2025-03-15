#include <glr/engine/ClampColor.h>

namespace glr {

VI_OBJECT_META_IMPL(ClampColor, StateAttribute);

struct ClampColor::Data {};

ClampColor::ClampColor()
  : d(new Data()) {
}

ClampColor::~ClampColor() {
}

ClampColor::Type ClampColor::getType() const {
    return CLAMP_COLOR;
}

void ClampColor::apply(State& state) const {
}

} // namespace glr