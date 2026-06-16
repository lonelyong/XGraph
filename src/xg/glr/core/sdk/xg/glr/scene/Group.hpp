
#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/scene/Node.h>

namespace xg {
namespace glr {
class StateSet;

class GLR_API Group : public Node {
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
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg