#pragma once

#include <xg/igl/glr_global.hpp>

#include <vector>

#include <xg/igl/engine/ArrayBuffer.hpp>

namespace xg
{
namespace glr
{

class State;

class IGL_CORE_API PrimitiveSet : public Object {
    V_OBJECT_META_DECL

  public:
    enum Mode
    {
        MODE_POINTS        = IGL_POINTS,
        MODE_LINES         = IGL_LINES,
        MODE_LINE_LOOP     = IGL_LINE_LOOP,
        MODE_LINE_STRIP    = IGL_LINE_STRIP,
        MODE_TRIANGLES     = IGL_TRIANGLES,
        MODE_TRIANGLE_TRIP = IGL_TRIANGLE_STRIP,
        MODE_TRIANGLE_FAN  = IGL_TRIANGLE_FAN,
        // no support in gl 3
        MODE_QUADS         = IGL_QUADS
    };

  public:
    PrimitiveSet();
    PrimitiveSet(Mode mode, GLint_t insts);

  public:
    Mode getMode() const;
    void setMode(Mode mode);

    GLint_t getInstances() const;
    void    setInstances(GLint_t insts);

  private:
    Mode      mode_      = MODE_TRIANGLES;
    GLsizei_t instances_ = 1;

  public:
    virtual void draw(State& state) = 0;
};

class IGL_CORE_API DrawArrays : public PrimitiveSet {
    V_OBJECT_META_DECL

  public:
    DrawArrays();
    DrawArrays(Mode mode, GLint_t offset, GLsizei_t count);
    DrawArrays(Mode mode, GLint_t offset, GLsizei_t count, GLsizei_t insts);

  public:
    GLint_t getOffset() const;
    void    setOffset(GLint_t offset);

    GLsizei_t getCount() const;
    void      setCount(GLsizei_t count);

    virtual void draw(State& state) override;

  private:
    GLint_t   offset_ = 0;
    GLsizei_t count_  = 0;
};

class IGL_CORE_API DrawElementsUInt : public PrimitiveSet {
    V_OBJECT_META_DECL

  public:
    DrawElementsUInt();
    DrawElementsUInt(Mode mode);
    DrawElementsUInt(Mode mode, GLsizei_t insts);

  public:
    void                   setIndices(std::vector<GLuint_t> indices);
    std::vector<GLuint_t>& getIndices();

    virtual void draw(State& state) override;

  private:
    std::vector<GLuint_t> indices_;
};

} // namespace glr
} // namespace xg