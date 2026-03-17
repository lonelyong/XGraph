#include <glr/engine/Enable.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(Enable, StateAttribute);

struct Enable::Data {};

Enable::Enable()
  : d(new Data()) {
}

Enable::~Enable() {
}

Enable::Type Enable::getType() const {
    return ENABLE;
}

void Enable::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
}

} // namespace glr