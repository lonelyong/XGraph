#pragma once

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API ClipControl : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    enum Origin
    {
        LOWER_LEFT = IGL_LOWER_LEFT,
        UPPER_LEFT = IGL_UPPER_LEFT
    };

    enum Depth
    {
        NEGATIVE_ONE_TO_ONE = IGL_NEGATIVE_ONE_TO_ONE,
        ZERO_TO_ONE         = IGL_ZERO_TO_ONE
    };

  public:
    ClipControl();
    ClipControl(Origin origin, Depth depth);
    virtual ~ClipControl();

  public:
    virtual Type getType() const override { return CLIP_CONTROL; }

    void   setOrigin(Origin origin) { origin_ = origin; }
    Origin getOrigin() const { return origin_; }

    void  setDepth(Depth depth) { depth_ = depth; }
    Depth getDepth() const { return depth_; }

  protected:
    virtual void apply(State& state) const override;

  private:
    Origin origin_ = LOWER_LEFT;
    Depth  depth_  = NEGATIVE_ONE_TO_ONE;
};

} // namespace glr
} // namespace xg