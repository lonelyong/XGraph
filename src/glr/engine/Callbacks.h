#pragma once

#include <glr/glrenderer_global.h>

#include <glr/engine/Object.h>

namespace glr {

class Renderer;

class GLR_API UpdateContext {
  public:
    virtual Renderer* getMasterRenderer() const = 0;
    virtual Renderer* getCurrentRenderer() const = 0;
};

class GLR_API UpdateCallback : public Object {
    VI_OBJECT_META;

  public:
    virtual void operator()(Object* obj, UpdateContext* ctx);
};
} // namespace glr