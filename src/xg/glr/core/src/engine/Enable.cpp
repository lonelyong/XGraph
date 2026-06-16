#include <xg/glr/engine/Enable.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

namespace xg {
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
} // namespace xg