#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

/**
 * The blend equations determine how a new pixel (the ''source'' color) is combined with a pixel already in the
 * framebuffer (the ''destination'' color). glBlendEquation sets the blend equation for all draw buffers.
 */
class IGL_CORE_API BlendEquation : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum Equation
    {
        FUNC_ADD              = IGL_FUNC_ADD,
        FUNC_SUBTRACT         = IGL_FUNC_SUBTRACT,
        FUNC_REVERSE_SUBTRACT = IGL_FUNC_REVERSE_SUBTRACT,
        MIN                   = IGL_MIN,
        MAX                   = IGL_MAX
    };

  public:
    BlendEquation();
    BlendEquation(Equation mode);
    virtual ~BlendEquation();

  public:
    virtual Type getType() const override { return BLEND_EQUATION; }

    void     setEquation(Equation mode) { equation_alpha_ = equation_rgb_ = mode; }
    Equation getEquation() const { return equation_rgb_; }

    Equation getEquationRGB() const { return equation_rgb_; }
    void     setEquationRGB(Equation equation) { equation_rgb_ = equation; }

    Equation getEquationAlpha() const { return equation_alpha_; }
    void     setEquationAlpha(Equation equation) { equation_alpha_ = equation; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Equation equation_rgb_   = FUNC_ADD;
    Equation equation_alpha_ = FUNC_ADD;
};

class IGL_CORE_API BlendEquationi : public BlendEquation {
    V_OBJECT_META_DECL

  public:
    BlendEquationi();
    BlendEquationi(GLuint_t buf, Equation equation);
    virtual ~BlendEquationi();

  public:
    virtual Type getType() const override { return BLEND_EQUATION; }

    void     setIndex(GLuint_t index) { index_ = index; }
    GLuint_t getIndex() const { return index_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t index_ = 0;
};

} // namespace glr
} // namespace xg