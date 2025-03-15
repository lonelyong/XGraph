#include <glr/engine/ColorMask.h>

namespace glr {

VI_OBJECT_META_IMPL(ColorMask, StateAttribute);

struct ColorMask::Data {};

ColorMask::ColorMask()
  : d(new Data()) {
}

ColorMask::~ColorMask() {
}

ColorMask::Type ColorMask::getType() const {
    return COLOR_MASK;
}

void ColorMask::apply(State& state) const {
}

} // namespace glr