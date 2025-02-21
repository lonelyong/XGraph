#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/engine/Object.h>

namespace vkr {

class Renderer;

class VKR_API RenderInfo : public Object {
    VI_OBJECT_META;
    VI_DISABLE_COPY_MOVE(RenderInfo);

  public:
    RenderInfo(Renderer* master_renderer);
    virtual ~RenderInfo();

  public:
    Renderer* getMasterRenderer() const;

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr