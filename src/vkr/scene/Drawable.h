#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/scene/Node.h>

namespace vkr {
class State;
class VKR_API Drawable : public Node {
    VI_OBJECT_META;

  public:
    virtual void draw(State& ctx) = 0;
};
} // namespace vkr