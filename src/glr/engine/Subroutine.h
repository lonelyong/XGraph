#pragma once
#include <glr/glr_global.h>

#include <string>

#include <glr/engine/UniformBase.h>

namespace glr {
class GLR_API Subroutine : public UniformBase {
    VI_OBJECT_META;

  public:
    enum ShaderType
    {
        NO_TYPE         = 0,
        VERTEX_SHADER   = HGL_VERTEX_SHADER,
        FRAGMENT_SHADER = HGL_FRAGMENT_SHADER,
    };

  public:
    Subroutine(ShaderType type, const std::string name);

    virtual ~Subroutine();

  public:
    virtual Type getType() const override;


    virtual void apply(State& state) const override;

    virtual const std::string& getName() const override;

  private:
    VI_OBJECT_DATA;
};

} // namespace glr