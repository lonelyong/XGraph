
#pragma once

#include <glr/glr_global.h>

#include <glr/scene/Node.h>

namespace glr {
class StateSet;

class GLR_API Group : public Node {
    VI_OBJECT_META;

  protected:
    Group();

  public:
    ~Group();


  public:
    virtual bool handleEvent(Event* e) override;
    virtual void update(UpdateContext* ctx) override;

  protected:
    int          getNbChildren() const;
    Node*        getChildAt(int idx) const;
    virtual void addChild(Node* node);
    virtual void removeChild(Node* node);
    virtual void onComputeBoundingBox(BoundingBox& bb) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace glr