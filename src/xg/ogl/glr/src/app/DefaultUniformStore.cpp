#include "DefaultUniformStore.h"

#include <xg/glr/engine/Uniform.h>

namespace glr {

namespace {
constexpr const char* LightingDisabled = "LightingDisabled";
constexpr const char* LightingEnabled  = "LightingEnabled";
} // namespace

V_OBJECT_META_IMPL(DefaultUniformStore, UniformStore);

DefaultUniformStore::DefaultUniformStore()
  : UniformStore("Default") {
    set(LightingEnabled, new Uniform("xg_is_lighting_enabled", true));
    set(LightingDisabled, new Uniform("xg_is_lighting_enabled", false));
}

UniformBase* DefaultUniformStore::getLightingDisabled() const {
    return get(LightingDisabled);
}

UniformBase* DefaultUniformStore::getLightingEnabled() const {
    return get(LightingEnabled);
}

DefaultUniformStore* DefaultUniformStore::instance() {
    static DefaultUniformStore us;
    return &us;
}
} // namespace glr