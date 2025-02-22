#pragma once
#include <glr/glr_global.h>

#include <string>

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API UniformBase : public StateAttribute {
    VI_OBJECT_META;

  public:
    virtual const std::string& getName() const = 0;
};

} // namespace glr