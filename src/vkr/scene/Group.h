
#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/scene/Node.h>

namespace vkr {
class StateSet;

class VKR_API Group : public Node {
    VI_OBJECT_META;

  protected:
    Group();

  public:
    ~Group();


  public:
    int        getNbChildren() const;
    Node* getChildAt(int idx) const;

    virtual bool handleEvent(Event* e) override;
    virtual void update(UpdateContext* ctx) override;

  protected:
    virtual void addChild(Node* node);
    virtual void removeChild(Node* node);
    virtual void onComputeBoundingBox(BoundingBox& bb) const override;

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr