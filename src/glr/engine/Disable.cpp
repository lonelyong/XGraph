#include <glr/engine/Disable.h>

namespace glr {

VI_OBJECT_META_IMPL(Disable, StateAttribute);

struct Disable::Data {};

Disable::Disable()
  : d(new Data()) {
}

Disable::~Disable() {
}

Disable::Type Disable::getType() const {
    return DISABLE;
}

void Disable::apply(State& state) const {
}

} // namespace glr