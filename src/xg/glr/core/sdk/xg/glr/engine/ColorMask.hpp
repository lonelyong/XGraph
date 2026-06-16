#pragma once

#include <xg/glr/engine/StateAttribute.hpp>

namespace xg {
namespace glr {
class GLR_API ColorMask : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    ColorMask();
    ColorMask(bool red, bool green, bool blue, bool alpha);
    virtual ~ColorMask();

  public:
    virtual Type getType() const override;

    void setMask(bool red, bool green, bool blue, bool alpha);
    void getMask(bool& red, bool& green, bool& blue, bool& alpha) const;

    void setRed(bool mask);
    bool getRed() const;

    void setGreen(bool mask);
    bool getGreen() const;

    void setBlue(bool mask);
    bool getBlue() const;

    void setAlpha(bool mask);
    bool getAlpha() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};

class GLR_API ColorMaski : public ColorMask {
    V_OBJECT_META_DECL

  public:
    ColorMaski();
    ColorMaski(GLuint_t buf, bool red, bool green, bool blue, bool alpha);
    virtual ~ColorMaski();

  public:
    virtual Type getType() const override;

    void     setIndex(GLuint_t);
    GLuint_t getIndex() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg