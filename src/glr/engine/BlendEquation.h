#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
/**
 * The blend equations determine how a new pixel (the ''source'' color) is combined with a pixel already in the
 * framebuffer (the ''destination'' color). glBlendEquation sets the blend equation for all draw buffers.
 */
class GLR_API BlendEquation : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Equation
    {
        FUNC_ADD              = HGL_FUNC_ADD,
        FUNC_SUBTRACT         = HGL_FUNC_SUBTRACT,
        FUNC_REVERSE_SUBTRACT = HGL_FUNC_REVERSE_SUBTRACT,
        MIN                   = HGL_MIN,
        MAX                   = HGL_MAX
    };

  public:
    BlendEquation();
    BlendEquation(Equation mode);
    virtual ~BlendEquation();

  public:
    virtual Type getType() const override;

    void     setEquation(Equation mode);
    Equation getEquation() const;

    Equation getEquationRGB() const;
    void     setEquationRGB(Equation equation);

    Equation getEquationAlpha() const;
    void     setEquationAlpha(Equation equation);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

class GLR_API BlendEquationi : public BlendEquation {
    VI_OBJECT_META;

  public:
    BlendEquationi();
    BlendEquationi(GLuint_t buf, Equation equation);
    virtual ~BlendEquationi();

  public:
    virtual Type getType() const override;

    void     setIndex(GLuint_t mode);
    GLuint_t getIndex() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

} // namespace glr