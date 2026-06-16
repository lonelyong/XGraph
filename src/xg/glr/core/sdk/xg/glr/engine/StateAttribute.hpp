#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/igl/GLdefs.hpp>

#include <xg/glr/engine/Object.hpp>

namespace xg {
namespace glr {
class StateSet;
class State;
class GLR_API StateAttribute : public Object {
    V_OBJECT_META_DECL

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
        STENCIL,
        SCISSOR,
        SCISSOR_INDEXED,
        SCISSOR_ARRAY,
        VIEWPORT,
        VIEWPORT_INDEXED,
        VIEWPORT_ARRAY,
        HINT,
        DISABLE,
        ENABLE,
        LINE_WIDTH,
        LOGICOP,
        CULL_FACE,
        COLOR_MASK,
        CLIP_CONTROL,
        CLAMP_COLOR,
        BLEND_FUNC,
        BLEND_EQUATION,
        BLEND_COLOR,
        FRONT_FACE,
        POLYGON_OFFSET,
        POLYGON_MODE,
        POINT_PARAMETER,
        SAMPLE_MASK,
        SAMPLE_COVERAGE,
        SAMPLER
    };

  public:
    virtual Type getType() const = 0;

    virtual bool equals(const StateAttribute& other) const;

  protected:
    virtual void apply(State& state) const = 0;

    virtual void restore(State& state) const;
};
} // namespace glr
} // namespace xg