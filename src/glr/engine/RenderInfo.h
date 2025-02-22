#pragma once

#include <glr/glr_global.h>

#include <glr/engine/Object.h>

namespace glr {

class Renderer;

class GLR_API RenderInfo : public Object {
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
} // namespace glr