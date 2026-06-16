#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/GLObject.h>

namespace xg {
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
} // namespace xg