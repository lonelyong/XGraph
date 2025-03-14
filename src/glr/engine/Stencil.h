#pragma once

#include <glr/glr_global.h>

#include <glad/glad.h>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API Stencil : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Func
    {
        // always fails
        FN_NEVER    = GL_NEVER,
        // Passes if ( ref & mask ) < ( stencil & mask ).
        FN_LESS     = GL_LESS,
        // Passes if ( ref & mask ) <= ( stencil & mask ).
        FN_LEQUAL   = GL_LEQUAL,
        // Passes if ( ref & mask ) > ( stencil & mask ).
        FN_GREATER  = GL_GREATER,
        // Passes if ( ref & mask ) >= ( stencil & mask ).
        FN_GEQUAL   = GL_GEQUAL,
        // Passes if (ref & mask) = (stencil & mask).
        FN_NOTEQUAL = GL_NOTEQUAL,
        // def value
        // Always passes.
        FN_ALWAYS   = GL_ALWAYS,
    };

    enum Operation
    {
        // Keeps the current value.
        OP_KEEP      = GL_KEEP,
        // Sets the stencil buffer value to 0
        OP_ZERO      = GL_ZERO,
        // Sets the stencil buffer value to ref, as specified by glStencilFunc.
        OP_REPLACE   = GL_REPLACE,
        // Increments the current stencil buffer value.Clamps to the maximum representable unsigned value.
        OP_INCR      = GL_INCR,
        // Increments the current stencil buffer value. Wraps stencil buffer value to zero when incrementing the maximum representable unsigned value.
        OP_INCR_WRAP = GL_INCR_WRAP,
        // Decrements the current stencil buffer value. Clamps to 0.
        OP_DECR      = GL_DECR,
        // Decrements the current stencil buffer value. Wraps stencil buffer value to the maximum representable unsigned value when decrementing a stencil buffer value of zero.
        OP_DECR_WRAP = GL_DECR_WRAP,
        // Bitwise inverts the current stencil buffer value.
        OP_INVERT = GL_INVERT,
    };

  public:
    Stencil();
    virtual ~Stencil();

  public:
    virtual Type getType() const override;

    virtual bool equals(const StateAttribute& other) const override;

    void setFunction(Func fn, int ref, unsigned int mask);

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
    inline void setWriteMask(unsigned int mask);

    inline unsigned int getWriteMask() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr