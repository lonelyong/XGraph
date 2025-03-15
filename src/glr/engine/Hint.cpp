#include <glr/engine/Hint.h>

namespace glr {

VI_OBJECT_META_IMPL(Hint, StateAttribute);

struct Hint::Data {};

Hint::Hint()
  : d(new Data()) {
}

Hint::~Hint() {
}

Hint::Type Hint::getType() const {
    return HINT;
}

void Hint::apply(State& state) const {
}

} // namespace glr