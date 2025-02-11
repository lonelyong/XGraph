#pragma once

#include <glr/glrenderer_global.h>

#include <glr/engine/EventReceiver.h>
#include <glr/scene/BoundingBox.h>

namespace glr {
class StateSet;
class SceneNodeGroup;
class SceneNodePrivate;
class GLR_API SceneNode : public EventReceiver {
    VI_OBJECT_META;
    friend class SceneNodeGroup;

  public:
    SceneNode();
    ~SceneNode();

  public:
    Mat4d getMatrix() const;
    void  setMatrix(const Mat4d& mat);

    StateSet* getOrCreateStateSet();
    StateSet* getStateSet();

    int        getNbParents() const;
    SceneNode* getParentAt(int idx) const;

    BoundingBox getBoundingBox() const;

    void setBoundingBox(const BoundingBox& bb);

    void dirtyBound();

  protected:
    virtual void onComputeBoundingBox(BoundingBox& bb) const;

  private:
    SceneNodePrivate* const d;
};
} // namespace glr