#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/StateAttribute.hpp>

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
    Type getType() const override;

    void set(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    void get(GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h);

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data;
    Data* const d;
    ;
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
    Type getType() const override;

    void set(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h);
    void get(GLuint_t& o_index, GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h);

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data;
    Data* const d;
    ;
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
    Type getType() const override;

    void     setFirst(GLuint_t first);
    GLuint_t getFirst() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg