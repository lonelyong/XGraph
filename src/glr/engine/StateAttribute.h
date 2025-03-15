#pragma once

#include <glr/glr_global.h>

#include <glr/engine/GL.h>
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
        PHONG_MATERIAL,
        PHONG_LIGHTS,
        DEPTH,
        DEPTH_RANGE_INDEXED,
        DEPTH_RANGE_ARRAY,
        LIGHTING,
        SHADER,
        UNIFORM,
        SUBROUTINE,
        PATCH_PARAMETER,
        STENCIL
    };

  public:
    virtual Type getType() const = 0;

    virtual bool equals(const StateAttribute& other) const;

  protected:
    virtual void apply(State& state) const = 0;

    virtual void restore(State& state) const;
};
} // namespace glr