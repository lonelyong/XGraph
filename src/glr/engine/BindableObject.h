#pragma once

#include <glr/glr_global.h>

#include <glr/engine/GLObject.h>

namespace glr {
class GLR_API BindableObject : public GLObject {
    VI_OBJECT_META;

  public:
    BindableObject();

  public:
    bool bind(State& state);
    bool unbind(State& state);

  protected:
    virtual bool onBind(State& state)   = 0;
    virtual bool onUnbind(State& state) = 0;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr