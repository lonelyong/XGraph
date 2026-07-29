#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/StateAttribute.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API PatchParameter : public StateAttribute {
    V_OBJECT_META_DECL

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
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg