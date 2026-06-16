#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/engine/Object.h>

namespace xg {
namespace glr {

class Renderer;

class GLR_API UpdateContext {
  public:
    virtual Renderer* getMasterRenderer() const = 0;
    virtual Renderer* getCurrentRenderer() const = 0;
};

class GLR_API UpdateCallback : public Object {
    V_OBJECT_META_DECL

  public:
    virtual void operator()(Object* obj, UpdateContext* ctx);
};
} // namespace glr
} // namespace xg