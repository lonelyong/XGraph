#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/engine/GLObject.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API BindableObject : public GLObject {
    V_OBJECT_META_DECL

  public:
    BindableObject();

  public:
    bool bind(State& state);
    bool unbind(State& state);

  protected:
    virtual bool onBind(State& state)   = 0;
    virtual bool onUnbind(State& state) = 0;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg