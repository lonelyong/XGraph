#include <xg/glr/engine/StateAttribute.hpp>

namespace xg {
namespace glr {
V_OBJECT_META_IMPL(StateAttribute, Object);

 bool StateAttribute::equals(const StateAttribute& other) const {
    return false;
 }

void StateAttribute::restore(State& state) const {
}
} // namespace glr
} // namespace xg