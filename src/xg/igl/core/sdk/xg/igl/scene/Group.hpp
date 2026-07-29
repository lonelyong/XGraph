
#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/scene/Node.hpp>

namespace xg
{
namespace glr
{

class StateSet;

class IGL_CORE_API Group : public Node {
    V_OBJECT_META_DECL

  protected:
    Group();

  public:
    ~Group();


  public:
    virtual bool handleEvent(Event* e) override;
    virtual void update(UpdateContext* ctx) override;

  protected:
    int          getNumChildren() const;
    Node*        getChildAt(int idx) const;
    virtual void addChild(Node* node);
    virtual void removeChild(Node* node);
    virtual void onComputeBoundingBox(BoundingBox& bb) const override;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg