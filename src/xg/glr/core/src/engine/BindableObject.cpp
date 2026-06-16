
#include <xg/glr/engine/BindableObject.hpp>

#include <unordered_set>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>

namespace xg {
namespace glr {
V_OBJECT_META_IMPL(BindableObject, GLObject);

struct BindableObject::Data {

};

BindableObject::BindableObject()
  : d(new Data()) {
}

bool BindableObject::bind(State& state) {
    if (!isCreated(state)) create(state);
    if (!isCreated(state)) return false;
    if (isDirty(state)) update(state);
    return onBind(state);
}

bool BindableObject::unbind(State& state) {
    if (!isCreated(state)) return true;
    return onUnbind(state);
}
} // namespace glr
} // namespace xg