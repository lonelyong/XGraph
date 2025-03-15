#include <glr/engine/BlendColor.h>

namespace glr {

VI_OBJECT_META_IMPL(BlendColor, StateAttribute);

struct BlendColor::Data {};

BlendColor::BlendColor()
  : d(new Data()) {
}

BlendColor::~BlendColor() {
}

BlendColor::Type BlendColor::getType() const {
    return CLAMP_COLOR;
}

void BlendColor::apply(State& state) const {
}

} // namespace glr