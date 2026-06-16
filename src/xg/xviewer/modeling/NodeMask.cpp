#include "NodeMask.h"

#include <osg/Node>

#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE

#    include <osgVerse/pipeline/Pipeline.h>

#endif // XG_XVIEWER_BUILD_WITH_OSGVERSE


namespace xviewer {

#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE
const int NODE_MASK_DEFERRED_SCENE = DEFERRED_SCENE_MASK;
const int NODE_MASK_FORWARD_SCENE  = FORWARD_SCENE_MASK;
const int NODE_MASK_SHADOW_CASTER  = SHADOW_CASTER_MASK;
const int NODE_MASK_CUSTOM_INPUT   = CUSTOM_INPUT_MASK;

static inline void clearMask(osg::Node::NodeMask& mask) {
    mask &= ~(NODE_MASK_DEFERRED_SCENE | NODE_MASK_FORWARD_SCENE | NODE_MASK_CUSTOM_INPUT);
}

void setAsDeferred(osg::Node* node) {
    auto mask = node->getNodeMask();
    clearMask(mask);
    mask &= NODE_MASK_DEFERRED_SCENE;
    node->setNodeMask(mask);
}

void setAsForward(osg::Node* node) {
    auto mask = node->getNodeMask();
    clearMask(mask);
    mask &= NODE_MASK_FORWARD_SCENE;
    node->setNodeMask(mask);
}

void setAsCustom(osg::Node* node) {
    auto mask = node->getNodeMask();
    clearMask(mask);
    mask &= NODE_MASK_CUSTOM_INPUT;
    node->setNodeMask(mask);
}

void setAsShadowCaster(osg::Node* node, bool val) {
    auto mask = node->getNodeMask();
    if (val) {
        mask |= NODE_MASK_SHADOW_CASTER;
    }
    else {
        mask &= ~NODE_MASK_SHADOW_CASTER;
    }
    node->setNodeMask(mask);
}
#endif // XG_XVIEWER_BUILD_WITH_OSGVERSE



} // namespace xviewer