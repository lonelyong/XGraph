#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/Object.hpp>

namespace xg
{
namespace glr
{

class Renderer;

class IGL_CORE_API RenderInfo : public Object {
    V_OBJECT_META_DECL

  public:
    RenderInfo(Renderer* master_renderer);
    virtual ~RenderInfo();

  public:
    Renderer* getMasterRenderer() const;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg