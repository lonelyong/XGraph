#include <glr/engine/ClipControl.h>

namespace glr {

VI_OBJECT_META_IMPL(ClipControl, StateAttribute);

struct ClipControl::Data {};

ClipControl::ClipControl()
  : d(new Data()) {
}

ClipControl::~ClipControl() {
}

ClipControl::Type ClipControl::getType() const {
    return CLIP_CONTROL;
}

void ClipControl::apply(State& state) const {
}

} // namespace glr