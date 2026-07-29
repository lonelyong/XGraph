#pragma once

#include <xg/igl/glr_global.hpp>

#include <vector>

#include <xg/igl/engine/StateSet.hpp>
#include <xg/igl/scene/BoundingBox.hpp>

namespace xg
{
namespace glr
{

class Node;

class NodePrivate {
    friend class Node;

  private:
    std::vector<Node*>     parent_nodes;
    vine::RefPtr<StateSet> state_set = nullptr;
    Mat4d                  matrix    = Mat4d(1.0);
    BoundingBox            bb;
    bool                   bound_is_dirty = true;

  public:
    void addParent(Node* node);
    void removeParent(Node* node);
};

} // namespace glr
} // namespace xg