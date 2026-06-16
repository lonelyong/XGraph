#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/igl/GLdefs.h>
#include <xg/glr/engine/StateAttribute.h>
#include <xg/glr/engine/types.h>

namespace xg {
namespace glr {
class GLR_API Stencil : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum Func
    {
        // always fails
        NEVER    = IGL_NEVER,
        // Passes if ( ref & mask ) < ( stencil & mask ).
        LESS     = IGL_LESS,
        // Passes if ( ref & mask ) <= ( stencil & mask ).
        LEQUAL   = IGL_LEQUAL,
        // Passes if ( ref & mask ) > ( stencil & mask ).
        GREATER  = IGL_GREATER,
        // Passes if ( ref & mask ) >= ( stencil & mask ).
        GEQUAL   = IGL_GEQUAL,
        // Passes if (ref & mask) = (stencil & mask).
        NOTEQUAL = IGL_NOTEQUAL,
        // def value
        // Always passes.
        ALWAYS   = IGL_ALWAYS,
    };

    enum Operation
    {
        // Keeps the current value.
        KEEP      = IGL_KEEP,
        // Sets the stencil buffer value to 0
        ZERO      = IGL_ZERO,
        // Sets the stencil buffer value to ref, as specified by glStencilFunc.
        REPLACE   = IGL_REPLACE,
        // Increments the current stencil buffer value.Clamps to the maximum representable unsigned value.
        INCR      = IGL_INCR,
        // Increments the current stencil buffer value. Wraps stencil buffer value to zero when incrementing the maximum
        // representable unsigned value.
        INCR_WRAP = IGL_INCR_WRAP,
        // Decrements the current stencil buffer value. Clamps to 0.
        DECR      = IGL_DECR,
        // Decrements the current stencil buffer value. Wraps stencil buffer value to the maximum representable unsigned
        // value when decrementing a stencil buffer value of zero.
        DECR_WRAP = IGL_DECR_WRAP,
        // Bitwise inverts the current stencil buffer value.
        INVERT    = IGL_INVERT,
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
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg