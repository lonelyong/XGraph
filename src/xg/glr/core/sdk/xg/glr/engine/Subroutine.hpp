#pragma once
#include <xg/glr/glr_global.hpp>

#include <string>

#include <xg/glr/engine/UniformBase.h>

namespace xg {
namespace glr {
class GLR_API Subroutine : public UniformBase {
    V_OBJECT_META_DECL

  public:
    enum ShaderType
    {
        NO_TYPE         = 0,
        VERTEX_SHADER   = IGL_VERTEX_SHADER,
        FRAGMENT_SHADER = IGL_FRAGMENT_SHADER,
    };

  public:
    Subroutine(ShaderType type, const std::string name);

    virtual ~Subroutine();

  public:
    virtual Type getType() const override;


    virtual void apply(State& state) const override;

    virtual const std::string& getName() const override;

  private:
    struct Data; Data* const d;;
};

} // namespace glr
} // namespace xg