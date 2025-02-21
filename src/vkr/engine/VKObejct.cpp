#include <vkr/engine/VKObject.h>

#include <map>

#include <vkr/engine/GraphicContext.h>
#include <vkr/engine/State.h>

namespace vkr {
VI_OBJECT_META_IMPL(VKObject, Object);

struct VKObject::Data {
    std::map<int, int> ids;
};

VKObject::VKObject()
  : d(new Data()) {
}
VKObject::~VKObject() {
    delete d;
}
int VKObject::getId(State& state) const {
    auto ctx_id = state.getContext()->getId();
    if (d->ids.contains(ctx_id)) {
        return d->ids[ctx_id];
    }
    return 0;
}

bool VKObject::isCreated(State& state) const {
    auto ctx_id = state.getContext()->getId();
    return d->ids.contains(ctx_id);
}

int VKObject::getNbInstances() const {
    return d->ids.size();
}

void VKObject::create(State& state) {
    if (isCreated(state)) return;
    auto id = onCreate(state);
    d->ids.insert({ state.getContext()->getId(), id });
    state.attachGLObject(this);
}

void VKObject::release(State& state) {
    if (isCreated(state)) {
        onRelease(state);
        d->ids.erase(state.getContext()->getId());
        state.detachGLObject(this);
    }
}

} // namespace vkr