#pragma once

#include <glr/glr_global.h>

#include <glr/engine/GLObject.h>

namespace glr {
class GLR_API BindableObject : public GLObject {
    VI_OBJECT_META;

  public:
    BindableObject();

  public:
    bool isDirty(State& state) const;
    void dirty();

    void bind(State& state);
    void unbind(State& state);
    void update(State& state);

  protected:
    virtual bool onUpdate(State& state) = 0;
    virtual void onBind(State& state)   = 0;
    virtual void onUnbind(State& state) = 0;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr