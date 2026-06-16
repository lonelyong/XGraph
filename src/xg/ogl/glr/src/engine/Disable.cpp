#include <xg/glr/engine/Disable.h>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(Disable, StateAttribute);

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
    auto funcs = state.getContext()->getFuncs();
}

} // namespace glr