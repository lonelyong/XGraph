#include <glr/scene/Group.h>

#include <vector>
#include <algorithm>

#include <glr/scene/Node.h>

#include "Node_p.h"

namespace glr {
V_OBJECT_META_IMPL(Group, Node);

struct Group::Data {

    std::vector<vine::RefPtr<Node>> child_nodes;
};

Group::Group()
  : d(new Data()) {
}

Group::~Group() {
    delete d;
}

int Group::getNumChildren() const {
    return d->child_nodes.size();
}

Node* Group::getChildAt(int idx) const {
    return d->child_nodes.at(idx).get();
}

bool Group::handleEvent(Event* e) {
    auto handled = EventReceiver::handleEvent(e);
    for (auto& child : d->child_nodes) {
        handled |= child->handleEvent(e);
        if (handled) {
            break;
        }
    }
    return handled;
}

void Group::update(UpdateContext* ctx) {
    EventReceiver::update(ctx);
    for (auto& child : d->child_nodes) {
        child->update(ctx);
    }
}

void Group::onComputeBoundingBox(BoundingBox& bb) const {
    bb.set(0, 0, 0, 0, 0, 0);
    for (auto& child : d->child_nodes) {
        bb.combine(child->getBoundingBox());
    }
}

void Group::addChild(Node* node) {
    if (!node) {
        return;
    }

    auto iter = std::find(d->child_nodes.begin(), d->child_nodes.end(), node);
    if (iter == d->child_nodes.end()) {
        d->child_nodes.push_back(node);
        node->d->addParent(this);
        dirtyBound();
    }
}

void Group::removeChild(Node* node) {
    auto iter = std::find(d->child_nodes.begin(), d->child_nodes.end(), node);
    if (iter != d->child_nodes.end()) {
        d->child_nodes.erase(iter);
        node->d->removeParent(this);
    }
}
} // namespace glr