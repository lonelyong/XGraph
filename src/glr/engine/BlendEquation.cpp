#include <glr/engine/BlendEquation.h>

namespace glr {

VI_OBJECT_META_IMPL(BlendEquation, StateAttribute);

struct BlendEquation::Data {};

BlendEquation::BlendEquation()
  : d(new Data()) {
}

BlendEquation::~BlendEquation() {
}

BlendEquation::Type BlendEquation::getType() const {
    return CLAMP_COLOR;
}

void BlendEquation::apply(State& state) const {
}

} // namespace glr