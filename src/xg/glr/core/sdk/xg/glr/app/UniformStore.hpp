#pragma once

#include <xg/glr/glr_global.h>

#include <string>

#include <xg/glr/engine/Object.h>

namespace xg {
namespace glr {
class UniformBase;
class GLR_API UniformStore : public Object {
    V_OBJECT_META_DECL

    UniformStore();
    UniformStore(const std::string& name);

  public:
    UniformBase* get(const std::string& name) const;

    void set(const std::string& name, UniformBase* uniform);

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg
