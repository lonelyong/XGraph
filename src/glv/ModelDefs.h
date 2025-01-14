#pragma once

namespace osg {
class Node;
}

namespace glv {

enum PipelineMask
{
    DEFERRED_SCENE_MASK = 0xff000000,
    FORWARD_SCENE_MASK  = 0x000000ff,
    SHADOW_CASTER_MASK  = 0x00100000,
    CUSTOM_INPUT_MASK   = 0x00010000
};

void setPipelineMask(osg::Node* node, int mask);

void applyDefaultMaterial(osg::Node* node);
} // namespace glv