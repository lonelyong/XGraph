#pragma once

#include <glr/glr_global.h>

#include <glr/engine/GLObject.h>

namespace glr {
class GLR_API BindableObject : public GLObject {
    V_OBJECT_META_DECL

  public:
    BindableObject();

  public:
    bool bind(State& state);
    bool unbind(State& state);

  protected:
    virtual bool onBind(State& state)   = 0;
    virtual bool onUnbind(State& state) = 0;

  private:
    struct Data; Data* const d;;
};
} // namespace glr