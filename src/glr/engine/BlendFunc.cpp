#include <glr/engine/BlendFunc.h>

namespace glr {

VI_OBJECT_META_IMPL(BlendFunc, StateAttribute);

struct BlendFunc::Data {};

BlendFunc::BlendFunc()
  : d(new Data()) {
}

BlendFunc::~BlendFunc() {
}

BlendFunc::Type BlendFunc::getType() const {
    return BLEND_FUNC;
}

void BlendFunc::apply(State& state) const {
}

} // namespace glr