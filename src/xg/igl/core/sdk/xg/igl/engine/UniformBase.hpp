#pragma once
#include <xg/igl/glr_global.hpp>

#include <string>

#include <xg/igl/engine/StateAttribute.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API UniformBase : public StateAttribute {
    V_OBJECT_META_DECL

  public:
    virtual const std::string& getName() const = 0;
};

} // namespace glr
} // namespace xg