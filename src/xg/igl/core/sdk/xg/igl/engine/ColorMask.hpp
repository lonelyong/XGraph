#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API ColorMask : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    ColorMask();
    ColorMask(bool red, bool green, bool blue, bool alpha);
    virtual ~ColorMask();

  public:
    virtual Type getType() const override { return COLOR_MASK; }

    void setMask(bool red, bool green, bool blue, bool alpha) { r_ = red; g_ = green; b_ = blue; a_ = alpha; }
    void getMask(bool& red, bool& green, bool& blue, bool& alpha) const { red = r_; green = g_; blue = b_; alpha = a_; }

    void setRed(bool mask) { r_ = mask; }
    bool getRed() const { return r_; }

    void setGreen(bool mask) { g_ = mask; }
    bool getGreen() const { return g_; }

    void setBlue(bool mask) { b_ = mask; }
    bool getBlue() const { return b_; }

    void setAlpha(bool mask) { a_ = mask; }
    bool getAlpha() const { return a_; }

  protected:
    virtual void apply(State& state) const override;

  protected:
    bool r_ = true;
    bool g_ = true;
    bool b_ = true;
    bool a_ = true;
};

class IGL_CORE_API ColorMaski : public ColorMask {
    V_OBJECT_META_DECL

  public:
    ColorMaski();
    ColorMaski(GLuint_t buf, bool red, bool green, bool blue, bool alpha);
    virtual ~ColorMaski();

  public:
    virtual Type getType() const override { return COLOR_MASK; }

    void     setIndex(GLuint_t index) { index_ = index; }
    GLuint_t getIndex() const { return index_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    GLuint_t index_ = 0;
};

} // namespace glr
} // namespace xg