#include <glr/engine/Hint.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

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
    auto funcs = state.getContext()->getFuncs();
}

} // namespace glr