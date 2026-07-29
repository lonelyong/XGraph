#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/app/UniformStore.hpp>

namespace xg
{
namespace glr
{

class UniformBase;

class IGL_CORE_API DefaultUniformStore : public UniformStore {
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
