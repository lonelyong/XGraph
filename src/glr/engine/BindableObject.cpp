
#include <glr/engine/BindableObject.h>

#include <map>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>

namespace glr {
VI_OBJECT_META_IMPL(BindableObject, GLObject);

struct BindableObject::Data {
    std::map<int, bool> dirties;
};

BindableObject::BindableObject()
  : d(new Data()) {
}

void BindableObject::update(State& state) {
    auto ctx_id = state.getContext()->getId();
    if (isDirty(state)) {
        auto status        = onUpdate(state);
        d->dirties[ctx_id] = status;
    }
}

void BindableObject::bind(State& state) {
    if (!isCreated(state)) create(state);
    if (!isCreated(state)) return;
    if (isDirty(state)) update(state);
    onBind(state);
}

void BindableObject::unbind(State& state) {
    if (!isCreated(state)) return;
    onUnbind(state);
}

bool BindableObject::isDirty(State& state) const {
    auto ctx_id = state.getContext()->getId();
    if (d->dirties.contains(ctx_id)) {
        return d->dirties[ctx_id];
    }
    return false;
}

void BindableObject::dirty() {
    for (auto& kv : d->dirties) {
        kv.second = true;
    }
}
} // namespace glr