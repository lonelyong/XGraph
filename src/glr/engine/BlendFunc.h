#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API BlendFunc : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum Func
    {
        ZERO                     = IGL_ZERO,
        ONE                      = IGL_ONE,
        SRC_COLOR                = IGL_SRC_COLOR,
        ONE_MINUS_SRC_COLOR      = IGL_ONE_MINUS_SRC_COLOR,
        DST_COLOR                = IGL_DST_COLOR,
        ONE_MINUS_DST_COLOR      = IGL_ONE_MINUS_DST_COLOR,
        SRC_ALPHA                = IGL_ALPHA,
        ONE_MINUS_SRC_ALPHA      = IGL_ONE_MINUS_SRC_ALPHA,
        DST_ALPHA                = IGL_ONE_MINUS_DST_ALPHA,
        CONSTANT_COLOR           = IGL_CONSTANT_COLOR,
        ONE_MINUS_CONSTANT_COLOR = IGL_ONE_MINUS_CONSTANT_COLOR,
        CONSTANT_ALPHA           = IGL_CONSTANT_ALPHA,
        ONE_MINUS_CONSTANT_ALPHA = IGL_ONE_MINUS_CONSTANT_ALPHA,
        SRC_ALPHA_SATURATE       = IGL_SRC_ALPHA_SATURATE,
        SRC1_COLOR               = IGL_SRC1_COLOR,
        ONE_MINUS_SRC1_COLOR     = IGL_ONE_MINUS_SRC1_COLOR,
        SRC1_ALPHA               = IGL_SRC1_ALPHA,
        ONE_MINUS_SRC1_ALPHA     = IGL_ONE_MINUS_SRC1_ALPHA
    };

  public:
    BlendFunc();
    BlendFunc(Func source, Func dest);
    virtual ~BlendFunc();

  public:
    virtual Type getType() const override;

    void setSource(Func func) const;
    Func getSource() const;

    void setSourceRGB(Func func) const;
    Func getSourceRGB() const;

    void setSourceAlpha(Func func) const;
    Func getSourceAlpha() const;

    void setDestination(Func func) const;
    Func getDestination() const;

    void setDestinationRGB(Func func) const;
    Func getDestinationRGB() const;

    void setDestinationAlpha(Func func) const;
    Func getDestinationAlpha() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};

class GLR_API BlendFunci : public BlendFunc {
    V_OBJECT_META_DECL

  public:
    BlendFunci();
    BlendFunci(GLuint_t buf, Func source, Func dest);
    virtual ~BlendFunci();

  public:
    virtual Type getType() const override;

    GLuint_t getIndex() const;
    void     setIndex(GLuint_t index);

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr