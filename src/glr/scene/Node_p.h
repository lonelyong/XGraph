#pragma once

#include <glr/glr_global.h>

#include <vector>

#include <glr/engine/StateSet.h>
#include <glr/scene/BoundingBox.h>

namespace glr {

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