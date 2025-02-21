#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/engine/EventReceiver.h>
#include <vkr/scene/BoundingBox.h>

namespace vkr {
class StateSet;
class Group;
class NodePrivate;
class VKR_API Node : public EventReceiver {
    VI_OBJECT_META;
    friend class Group;

  public:
    Node();
    ~Node();

  public:
    Mat4d getMatrix() const;
    void  setMatrix(const Mat4d& mat);

    StateSet* getOrCreateStateSet();
    StateSet* getStateSet();

    int   getNbParents() const;
    Node* getParentAt(int idx) const;

    BoundingBox getBoundingBox() const;

    void setBoundingBox(const BoundingBox& bb);

    void dirtyBound();

  protected:
    virtual void onComputeBoundingBox(BoundingBox& bb) const;

  private:
    NodePrivate* const d;
};
} // namespace vkr