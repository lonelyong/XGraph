#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API Scissor : public StateAttribute {
    VI_OBJECT_META;

  public:
    Scissor();
    Scissor();

  private:
    VI_OBJECT_DATA;
};
} // namespace glr