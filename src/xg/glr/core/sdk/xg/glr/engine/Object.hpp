#pragma once

#include <xg/glr/glr_global.hpp>

#include <vine/Class.hpp>
#include <vine/RefObject.hpp>
#include <vine/Ptr.hpp>

namespace xg {
namespace glr {
class GLR_API Object : public vine::RefObject {
    V_OBJECT_META_DECL

  protected:
    Object() {};
};
} // namespace glr
} // namespace xg