#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/EventReceiver.hpp>
#include <xg/igl/scene/BoundingBox.hpp>

namespace xg
{
namespace glr
{

class StateSet;
class Group;
class NodePrivate;

class IGL_CORE_API Node : public EventReceiver {
    V_OBJECT_META_DECL
    friend class Group;

  public:
    Node();
    ~Node();

  public:
    Mat4d getMatrix() const;
    void  setMatrix(const Mat4d& mat);

    StateSet* getOrCreateStateSet();
    StateSet* getStateSet();

    int   getNumParents() const;
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
} // namespace xg