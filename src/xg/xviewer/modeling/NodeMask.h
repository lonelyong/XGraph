#pragma once

namespace osg {
class Node;
};

namespace xviewer {

#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE

extern const int NODE_MASK_DEFERRED_SCENE;
extern const int NODE_MASK_FORWARD_SCENE;
extern const int NODE_MASK_SHADOW_CASTER;
extern const int NODE_MASK_CUSTOM_INPUT;

void setAsDeferred(osg::Node* node);
void setAsForward(osg::Node* node);
void setAsCustom(osg::Node* node);
void setAsShadowCaster(osg::Node* node, bool val);

#endif
} // namespace xviewer