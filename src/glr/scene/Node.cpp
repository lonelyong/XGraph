#include <glr/scene/Node.h>

#include <vector>

#include <glr/engine/StateSet.h>

#include "Node_p.h"

namespace glr {

V_OBJECT_META_IMPL(Node, EventReceiver);

Node::Node()
  : d(new NodePrivate()) {
}

Node::~Node() {
    delete d;
}

Mat4d Node::getMatrix() const {
    return d->matrix;
}

void Node::setMatrix(const Mat4d& mat) {
    d->matrix = mat;
}

StateSet* Node::getOrCreateStateSet() {
    if (!d->state_set.get()) {
        d->state_set = new StateSet();
    }
    return d->state_set.get();
}

StateSet* Node::getStateSet() {
    return d->state_set.get();
}

BoundingBox Node::getBoundingBox() const {
    if (d->bound_is_dirty) {
        onComputeBoundingBox(d->bb);
    }
    return d->bb;
}

void Node::setBoundingBox(const BoundingBox& bb) {
    d->bb             = bb;
    d->bound_is_dirty = false;
}

int Node::getNumParents() const {
    return d->parent_nodes.size();
}

Node* Node::getParentAt(int idx) const {
    return d->parent_nodes.at(idx);
}

void Node::dirtyBound() {
    d->bound_is_dirty = true;
    int nparents      = getNumParents();
    for (int i = 0; i < nparents; ++i) {
        getParentAt(i)->dirtyBound();
    }
}

void Node::onComputeBoundingBox(BoundingBox& bb) const {
    bb.set(0, 0, 0, 0, 0, 0);
}

} // namespace glr