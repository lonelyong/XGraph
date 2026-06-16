#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/app/UniformStore.hpp>

namespace xg {
namespace glr {
class UniformBase;
class GLR_API DefaultUniformStore : public UniformStore {
    V_OBJECT_META_DECL

  private:
    DefaultUniformStore();

  public:
    UniformBase* getLightingDisabled() const;

    UniformBase* getLightingEnabled() const;

  public:
    static DefaultUniformStore* instance();
};
} // namespace glr
} // namespace xg
