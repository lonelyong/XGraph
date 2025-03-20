#pragma once

#include <glr/glr_global.h>

#include <vine/core/Class.h>
#include <vine/core/Object.h>

namespace glr {
class GLR_API Object : public vine::Object {
    VI_OBJECT_META;
    VI_DISABLE_COPY_MOVE(Object);

  protected:
    Object() {};
};
} // namespace glr