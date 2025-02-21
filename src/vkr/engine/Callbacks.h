#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/engine/Object.h>

namespace vkr {

class Renderer;

class VKR_API UpdateContext {
  public:
    virtual Renderer* getMasterRenderer() const = 0;
    virtual Renderer* getCurrentRenderer() const = 0;
};

class VKR_API UpdateCallback : public Object {
    VI_OBJECT_META;

  public:
    virtual void operator()(Object* obj, UpdateContext* ctx);
};
} // namespace vkr