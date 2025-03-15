
#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>

namespace glr {
/**
 * @brief glViewport
 */
class GLR_API Viewport : public StateAttribute {
    VI_OBJECT_META;

  public:
    Viewport();
    Viewport(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    virtual ~Viewport();

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
 * @brief glViewportIndexed
 */
class GLR_API ViewportIndexed : public StateAttribute {
    VI_OBJECT_META;

  public:
    ViewportIndexed();
    ViewportIndexed(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h);
    virtual ~ViewportIndexed();

  public:
    Type getType() const;

    void set(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h);
    void get(GLuint_t& o_index, GLfloat_t& o_x, GLfloat_t& o_y, GLfloat_t& o_w, GLfloat_t& o_h);

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};

/**
 * @brief glViewportArray
 */
class GLR_API ViewportArray : public StateAttribute {
    VI_OBJECT_META;

  public:
    ViewportArray();
    virtual ~ViewportArray();

  public:
    Type getType() const;

    void     setFirst(GLuint_t first);
    GLuint_t getFirst() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr