#pragma once

#include <xg/igl/glr_global.hpp>

#include <vine/Class.hpp>
#include <vine/Ptr.hpp>
#include <vine/RefObject.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API Object : public vine::RefObject {
    V_OBJECT_META_DECL

  protected:
    Object() {};
};

} // namespace glr
} // namespace xg