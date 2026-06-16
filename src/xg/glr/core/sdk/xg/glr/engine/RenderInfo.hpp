#pragma once

#include <xg/glr/glr_global.h>

#include <xg/glr/engine/Object.h>

namespace xg {
namespace glr {

class Renderer;

class GLR_API RenderInfo : public Object {
    V_OBJECT_META_DECL

  public:
    RenderInfo(Renderer* master_renderer);
    virtual ~RenderInfo();

  public:
    Renderer* getMasterRenderer() const;

  private:
    struct Data; Data* const d;;
};
} // namespace glr
} // namespace xg