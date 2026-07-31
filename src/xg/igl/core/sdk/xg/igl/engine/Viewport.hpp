
#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/StateAttribute.hpp>

#include <vector>

namespace xg
{
namespace glr
{

/**
 * @brief glViewport
 */
class IGL_CORE_API Viewport : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    Viewport();
    Viewport(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    virtual ~Viewport();

  public:
    Type getType() const override { return VIEWPORT; }

    void set(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h) { x_ = x; y_ = y; w_ = w; h_ = h; }
    void get(GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h) { o_x = x_; o_y = y_; o_w = w_; o_h = h_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLint_t   x_ = 0;
    GLint_t   y_ = 0;
    GLsizei_t w_ = 1;
    GLsizei_t h_ = 1;
};

/**
 * @brief glViewportIndexed
 */
class IGL_CORE_API ViewportIndexed : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    ViewportIndexed();
    ViewportIndexed(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h);
    virtual ~ViewportIndexed();

  public:
    Type getType() const override { return VIEWPORT_INDEXED; }

    void set(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h) { index_ = index; x_ = x; y_ = y; w_ = w; h_ = h; }
    void get(GLuint_t& o_index, GLfloat_t& o_x, GLfloat_t& o_y, GLfloat_t& o_w, GLfloat_t& o_h) { o_index = index_; o_x = x_; o_y = y_; o_w = w_; o_h = h_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t  index_ = 0;
    GLfloat_t x_ = 0.f;
    GLfloat_t y_ = 0.f;
    GLfloat_t w_ = 1.f;
    GLfloat_t h_ = 1.f;
};

/**
 * @brief glViewportArray
 */
class IGL_CORE_API ViewportArray : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    ViewportArray();
    virtual ~ViewportArray();

  public:
    Type getType() const override { return VIEWPORT_ARRAY; }

    void     setFirst(GLuint_t first) { first_ = first; }
    GLuint_t getFirst() const { return first_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t                first_ = 0;
    GLsizei_t               count_ = 0;
    std::vector<GLfloat_t>  xywh_pairs_;
};

} // namespace glr
} // namespace xg