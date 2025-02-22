#pragma once

#include <glr/glr_global.h>

#include <glr/engine/EventReceiver.h>
#include <glr/scene/BoundingBox.h>

namespace glr {
class StateSet;
class Group;
class NodePrivate;
class GLR_API Node : public EventReceiver {
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
} // namespace glr