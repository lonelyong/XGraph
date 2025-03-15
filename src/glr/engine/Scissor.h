#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>

namespace glr {
/**
 * @brief glScissor
 */
class GLR_API Scissor : public StateAttribute {
    VI_OBJECT_META;

  public:
    Scissor();
    Scissor(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    virtual ~Scissor();

  public:
    Type getType() const override;

    void set(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    void get(GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

/**
 * @brief glScissorIndexed
 */
class GLR_API ScissorIndexed : public StateAttribute {
    VI_OBJECT_META;

  public:
    ScissorIndexed();
    ScissorIndexed(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    virtual ~ScissorIndexed();

  public:
    Type getType() const;

    void set(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    void get(GLuint_t& o_index, GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

/**
 * @brief glScissorArray
 */
class GLR_API ScissorArray : public StateAttribute {
    VI_OBJECT_META;

  public:
    ScissorArray();
    virtual ~ScissorArray();

  public:
    Type getType() const;

    void setFirst(GLuint_t first);
    GLuint_t getFirst() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr