#include <xg/glr/engine/Hint.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

namespace xg {
namespace glr {

V_OBJECT_META_IMPL(Hint, StateAttribute);

struct Hint::Data {
    HintType  type = HintType(0);
    HintValue val  = DONT_CARE;
};

Hint::Hint()
  : d(new Data()) {
}

Hint::Hint(HintType type, HintValue val)
  : d(new Data) {
}

Hint::~Hint() {
    delete d;
}

Hint::Type Hint::getType() const {
    return HINT;
}

void Hint::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    if (d->type) {
        funcs->iglHint(d->type, d->val);
    }
}

} // namespace glr
} // namespace xg