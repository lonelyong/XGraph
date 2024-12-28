#pragma once

#include <glr/glrenderer_global.h>

#include <glr/engine/Object.h>

namespace glr {
class StateSet;
class State;
class GLR_API StateAttribute : public Object {
    VI_OBJECT_META;

    friend class State;

  public:
    enum Type
    {
        ATTR_MATERIAL,
        ATTR_DEPTH,
        ATTR_LIGHTING,
        ATTR_SPOT_LIGHTS,
        ATTR_DIRECTIONAL_LIGHTS,
        ATTR_LIGHTS,
        ATTR_SHADER,
        ATTR_UNIFORM
    };

  public:
    virtual Type getType() const = 0;

  protected:
    virtual void apply(State& state) const = 0;

    virtual void restore(State& state) const;
};
} // namespace glr