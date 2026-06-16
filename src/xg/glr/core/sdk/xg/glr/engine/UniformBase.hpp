#pragma once
#include <xg/glr/glr_global.hpp>

#include <string>

#include <xg/glr/engine/StateAttribute.h>

namespace xg {
namespace glr {
class GLR_API UniformBase : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    virtual const std::string& getName() const = 0;
};

} // namespace glr
} // namespace xg