#pragma once

#include <xg/glr/glr_global.h>

#include <vine/Class.hpp>
#include <vine/RefObject.hpp>
#include <vine/Ptr.hpp>

namespace glr {
class GLR_API Object : public vine::RefObject {
    V_OBJECT_META_DECL

  protected:
    Object() {};
};
} // namespace glr