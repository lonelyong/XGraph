#pragma once

#include <glr/glr_global.h>

#include <vector>

#include <glr/engine/ArrayBuffer.h>

namespace glr {
class GLR_API PrimitiveSet : public Object {
    VI_OBJECT_META;

  public:
    enum Mode
    {
        MODE_POINTS        = HGL_POINTS,
        MODE_LINES         = HGL_LINES,
        MODE_LINE_LOOP     = HGL_LINE_LOOP,
        MODE_LINE_STRIP    = HGL_LINE_STRIP,
        MODE_TRIANGLES     = HGL_TRIANGLES,
        MODE_TRIANGLE_TRIP = HGL_TRIANGLE_STRIP,
        MODE_TRIANGLE_FAN  = HGL_TRIANGLE_FAN,
        // no support in gl 3
        MODE_QUADS         = HGL_QUADS
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
    virtual void draw() = 0;
};

class GLR_API DrawArrays : public PrimitiveSet {
    VI_OBJECT_META;

  public:
    DrawArrays();
    DrawArrays(Mode mode, GLint_t offset, GLsizei_t count);
    DrawArrays(Mode mode, GLint_t offset, GLsizei_t count, GLsizei_t insts);

  public:
    GLint_t getOffset() const;
    void    setOffset(GLint_t offset);

    GLsizei_t getCount() const;
    void      setCount(GLsizei_t count);

    virtual void draw() override;

  private:
    GLint_t   offset_ = 0;
    GLsizei_t count_  = 0;
};

class GLR_API DrawElementsUInt : public PrimitiveSet {
    VI_OBJECT_META;

  public:
    DrawElementsUInt();
    DrawElementsUInt(Mode mode);
    DrawElementsUInt(Mode mode, GLsizei_t insts);

  public:
    void                   setIndices(std::vector<GLuint_t> indices);
    std::vector<GLuint_t>& getIndices();

    virtual void draw() override;

  private:
    std::vector<GLuint_t> indices_;
};
}; // namespace glr