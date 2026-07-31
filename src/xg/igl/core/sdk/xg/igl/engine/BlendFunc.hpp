#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API BlendFunc : public StateAttribute {
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
    virtual Type getType() const override { return BLEND_FUNC; }

    void setSource(Func func) { source_rgb_ = source_alpha_ = func; }
    Func getSource() const { return source_rgb_; }

    void setSourceRGB(Func func) { source_rgb_ = func; }
    Func getSourceRGB() const { return source_rgb_; }

    void setSourceAlpha(Func func) { source_alpha_ = func; }
    Func getSourceAlpha() const { return source_alpha_; }

    void setDestination(Func func) { dest_rgb_ = dest_alpha_ = func; }
    Func getDestination() const { return dest_rgb_; }

    void setDestinationRGB(Func func) { dest_rgb_ = func; }
    Func getDestinationRGB() const { return dest_rgb_; }

    void setDestinationAlpha(Func func) { dest_alpha_ = func; }
    Func getDestinationAlpha() const { return dest_alpha_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Func source_rgb_   = SRC_ALPHA;
    Func source_alpha_ = SRC_ALPHA;
    Func dest_rgb_     = ONE_MINUS_SRC_ALPHA;
    Func dest_alpha_   = ONE_MINUS_SRC_ALPHA;
};

class IGL_CORE_API BlendFunci : public BlendFunc {
    V_OBJECT_META_DECL

  public:
    BlendFunci();
    BlendFunci(GLuint_t buf, Func source, Func dest);
    virtual ~BlendFunci();

  public:
    virtual Type getType() const override { return BLEND_FUNC; }

    GLuint_t getIndex() const { return index_; }
    void     setIndex(GLuint_t index) { index_ = index; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t index_ = 0;
};

} // namespace glr
} // namespace xg