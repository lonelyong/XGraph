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
    virtual Type getType() const override { return PATCH_PARAMETER; }

    virtual bool equals(const StateAttribute& other) const override;

    void setVertices(int vertices) { vertices_ = vertices; }
    int getVertices() const { return vertices_; }

    void setPatchDefaultInnerLevel(const Vec2f& level) { patch_def_inner_level_ = level; }
    const Vec2f& getPatchDefaultInnerLevel() const { return patch_def_inner_level_; }

    void setPatchDefaultOuterLevel(const Vec4f& level) { patch_def_outer_level_ = level; }
    const Vec4f& getPatchDefaultOuterLevel() const { return patch_def_outer_level_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    int   vertices_               = 3;
    Vec2f patch_def_inner_level_  = { 1.0f, 1.0f };
    Vec4f patch_def_outer_level_  = { 1.0f, 1.0f, 1.0f, 1.0f };
};

} // namespace glr
} // namespace xg