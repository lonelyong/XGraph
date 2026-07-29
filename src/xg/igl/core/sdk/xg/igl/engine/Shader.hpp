#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>

#include <xg/igl/engine/GLObject.hpp>
#include <xg/igl/engine/types.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API Shader : public GLObject {
    V_OBJECT_META_DECL

  public:
    enum Type
    {
        VERTEX          = IGL_VERTEX_SHADER,
        TESS_CONTROL    = IGL_TESS_CONTROL_SHADER,
        TESS_EVALUATION = IGL_TESS_EVALUATION_SHADER,
        GEOMETRY        = IGL_GEOMETRY_SHADER,
        FRAGMENT        = IGL_FRAGMENT_SHADER,
        COMPUTE         = IGL_COMPUTE_SHADER
    };

  public:
    Shader();
    Shader(Type type, const std::string& code);
    virtual ~Shader();

  public:
    Type getType() const;
    void setType(Type type);

    std::string getSource() const;
    void        setSource(const std::string& source);

  public:
    static Shader* createFromFile(Type type, const std::string& path);

  protected:
    GLuint_t onCreate(State& state) override;
    bool     onUpdate(State& state) override;
    bool     onRelease(State& state) override;

  private:
    struct Data;
    Data* const d;
};

} // namespace glr
} // namespace xg