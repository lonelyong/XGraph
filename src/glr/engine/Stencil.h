#pragma once

#include <glr/glr_global.h>

#include <glr/engine/GL.h>
#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API Stencil : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Func
    {
        // always fails
        NEVER    = HGL_NEVER,
        // Passes if ( ref & mask ) < ( stencil & mask ).
        LESS     = HGL_LESS,
        // Passes if ( ref & mask ) <= ( stencil & mask ).
        LEQUAL   = HGL_LEQUAL,
        // Passes if ( ref & mask ) > ( stencil & mask ).
        GREATER  = HGL_GREATER,
        // Passes if ( ref & mask ) >= ( stencil & mask ).
        GEQUAL   = HGL_GEQUAL,
        // Passes if (ref & mask) = (stencil & mask).
        NOTEQUAL = HGL_NOTEQUAL,
        // def value
        // Always passes.
        ALWAYS   = HGL_ALWAYS,
    };

    enum Operation
    {
        // Keeps the current value.
        KEEP      = HGL_KEEP,
        // Sets the stencil buffer value to 0
        ZERO      = HGL_ZERO,
        // Sets the stencil buffer value to ref, as specified by glStencilFunc.
        REPLACE   = HGL_REPLACE,
        // Increments the current stencil buffer value.Clamps to the maximum representable unsigned value.
        INCR      = HGL_INCR,
        // Increments the current stencil buffer value. Wraps stencil buffer value to zero when incrementing the maximum
        // representable unsigned value.
        INCR_WRAP = HGL_INCR_WRAP,
        // Decrements the current stencil buffer value. Clamps to 0.
        DECR      = HGL_DECR,
        // Decrements the current stencil buffer value. Wraps stencil buffer value to the maximum representable unsigned
        // value when decrementing a stencil buffer value of zero.
        DECR_WRAP = HGL_DECR_WRAP,
        // Bitwise inverts the current stencil buffer value.
        INVERT    = HGL_INVERT,
    };

  public:
    Stencil();
    virtual ~Stencil();

  public:
    virtual Type getType() const override;

    virtual bool equals(const StateAttribute& other) const override;

    void setFunction(Func fn, GLint_t ref, GLuint_t mask);

    /**
     * @brief
     * @param sfail stencil test fails
     * @param zfail stencil test passes but depth test fails
     * @param zpass stencil test passes and depth test passes
     */
    void setOperation(Operation sfail, Operation zfail, Operation zpass);

    /**
     * @brief final_value=(new & mask)∣(old & ∼mask)
     * @param mask 0x00禁用写入，0xFF完全替换现有值
     */
    inline void setWriteMask(GLuint_t mask);

    inline GLuint_t getWriteMask() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr