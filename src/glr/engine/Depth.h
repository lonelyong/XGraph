#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>

namespace glr {
/**
 * @brief glDepthFunc, glDepthRange, glDepthMask
 */
class GLR_API Depth : public StateAttribute {
    VI_OBJECT_META;

  public:
    enum Func
    {
        NEVER    = IGL_NEVER,
        LESS     = IGL_LESS,
        EQUAL    = IGL_EQUAL,
        LEQUAL   = IGL_LEQUAL,
        GREATER  = IGL_GREATER,
        NOTEQUAL = IGL_NOTEQUAL,
        GEQUAL   = IGL_GEQUAL,
        ALWAYS   = IGL_ALWAYS
    };

  public:
    Depth(GLdouble_t near, GLdouble_t far, Func func = LESS, GLboolean_t mask = true);
    virtual ~Depth();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

/**
 * @brief glDepthRangeIndexed
 */
class GLR_API DepthRangeIndexed : public StateAttribute {
    VI_OBJECT_META;

  public:
    DepthRangeIndexed(GLuint_t index, GLdouble_t near, GLdouble_t far);
    virtual ~DepthRangeIndexed();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

/**
 * @brief glDepthRangeIndexed
 */
class GLR_API DepthRangeArray : public StateAttribute {
    VI_OBJECT_META;

  public:
    DepthRangeArray();
    virtual ~DepthRangeArray();

  public:
    virtual Type getType() const override;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr