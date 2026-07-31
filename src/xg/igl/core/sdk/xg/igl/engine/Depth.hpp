#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/StateAttribute.hpp>

#include <vector>

namespace xg
{
namespace glr
{

/**
 * @brief glDepthFunc, glDepthRange, glDepthMask
 */
class IGL_CORE_API Depth : public StateAttribute {
    V_OBJECT_META_DECL

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
    virtual Type getType() const override { return DEPTH; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLdouble_t  near_ = 0.0;
    GLdouble_t  far_  = 1.0;
    GLint_t     func_ = LESS;
    GLboolean_t mask_ = true;
};

/**
 * @brief glDepthRangeIndexed
 */
class IGL_CORE_API DepthRangeIndexed : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    DepthRangeIndexed(GLuint_t index, GLdouble_t near, GLdouble_t far);
    virtual ~DepthRangeIndexed();

  public:
    virtual Type getType() const override { return DEPTH_RANGE_INDEXED; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t   index_ = 0;
    GLdouble_t near_  = 0.0;
    GLdouble_t far_   = 1.0;
};

/**
 * @brief glDepthRangeIndexed
 */
class IGL_CORE_API DepthRangeArray : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    DepthRangeArray();
    virtual ~DepthRangeArray();

  public:
    virtual Type getType() const override { return DEPTH_RANGE_ARRAY; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t                  first_ = 0;
    GLsizei_t                 count_ = 0;
    std::vector<GLdouble_t>   near_far_pairs_;
};

} // namespace glr
} // namespace xg