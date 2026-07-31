#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/StateAttribute.hpp>

#include <vector>

namespace xg
{
namespace glr
{

/**
 * @brief glScissor
 */
class IGL_CORE_API Scissor : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    Scissor();
    Scissor(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    virtual ~Scissor();

  public:
    Type getType() const override { return SCISSOR; }

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
 * @brief glScissorIndexed
 */
class IGL_CORE_API ScissorIndexed : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    ScissorIndexed();
    ScissorIndexed(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    virtual ~ScissorIndexed();

  public:
    Type getType() const override { return SCISSOR_INDEXED; }

    void set(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h) { index_ = index; x_ = x; y_ = y; w_ = w; h_ = h; }
    void get(GLuint_t& o_index, GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h) { o_index = index_; o_x = x_; o_y = y_; o_w = w_; o_h = h_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t  index_ = 0;
    GLint_t   x_ = 0;
    GLint_t   y_ = 0;
    GLsizei_t w_ = 1;
    GLsizei_t h_ = 1;
};

/**
 * @brief glScissorArray
 */
class IGL_CORE_API ScissorArray : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    ScissorArray();
    virtual ~ScissorArray();

  public:
    Type getType() const override { return SCISSOR_ARRAY; }

    void     setFirst(GLuint_t first) { first_ = first; }
    GLuint_t getFirst() const { return first_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t            first_ = 0;
    GLsizei_t           count_ = 0;
    std::vector<GLint_t> xywh_pairs_;
};

} // namespace glr
} // namespace xg