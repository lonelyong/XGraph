#include <xg/glr/engine/Enable.h>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

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