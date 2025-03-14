#pragma once

#include <glr/glr_global.h>

#include <glr/engine/StateAttribute.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API PatchParameter : public StateAttribute {
    VI_OBJECT_META;

  public:
    PatchParameter();
    PatchParameter(int vertices);
    virtual ~PatchParameter();

  public:
    virtual Type getType() const override;

    virtual bool equals(const StateAttribute& other) const override;

    void setVertices(int vertices);

    int getVertices() const;

    void setPatchDefaultInnerLevel(const Vec2f& level);

    const Vec2f& getPatchDefaultInnerLevel() const;

    void setPatchDefaultOuterLevel(const Vec4f& level);

    const Vec4f& getPatchDefaultOuterLevel() const;

  protected:
    virtual void apply(State& state) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr