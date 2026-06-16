#include "Node_p.h"

#include <algorithm>

namespace glr {

void NodePrivate::addParent(Node* node) {
    auto iter = std::find(parent_nodes.begin(), parent_nodes.end(), node);
    if (iter == parent_nodes.end()) {
        parent_nodes.push_back(node);
    }
}

void NodePrivate::removeParent(Node* node) {
    auto iter = std::find(parent_nodes.begin(), parent_nodes.end(), node);
    if (iter != parent_nodes.end()) {
        parent_nodes.erase(iter);
    }
}
} // namespace glr