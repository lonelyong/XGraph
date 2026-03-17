#pragma once

#include <glr/engine/StateAttribute.h>

namespace glr {
class GLR_API PolygonOffset : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    PolygonOffset();
    PolygonOffset(GLfloat_t factor, GLfloat_t units);
    virtual ~PolygonOffset();

  public:
    virtual Type getType() const override;

    GLfloat_t getFactor() const;
    void      setFactor(GLfloat_t val);

    GLfloat_t getUnits() const;
    void      setUnits(GLfloat_t val);

  protected:
    virtual void apply(State& state) const override;

  private:
    struct Data; Data* const d;;
};
} // namespace glr