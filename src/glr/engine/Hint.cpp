#include <glr/engine/Hint.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

VI_OBJECT_META_IMPL(Hint, StateAttribute);

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