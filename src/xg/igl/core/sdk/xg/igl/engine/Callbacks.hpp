#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/Object.hpp>

namespace xg
{
namespace glr
{

class Renderer;

class IGL_CORE_API UpdateContext {
  public:
    virtual Renderer* getMasterRenderer() const  = 0;
    virtual Renderer* getCurrentRenderer() const = 0;
};

class IGL_CORE_API UpdateCallback : public Object {
    V_OBJECT_META_DECL

  public:
    virtual void operator()(Object* obj, UpdateContext* ctx);
};

} // namespace glr
} // namespace xg