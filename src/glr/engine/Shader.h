#pragma once

#include <glr/glr_global.h>

#include <string>

#include <glr/engine/GLObject.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API Shader : public GLObject {
    VI_OBJECT_META

  public:
    enum Type
    {
        VERTEX          = GL_VERTEX_SHADER,
        TESS_CONTROL    = GL_TESS_CONTROL_SHADER,
        TESS_EVALUATION = GL_TESS_EVALUATION_SHADER,
        GEOMETRY        = GL_GEOMETRY_SHADER,
        FRAGMENT        = GL_FRAGMENT_SHADER,
        COMPUTE         = GL_COMPUTE_SHADER
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
    GLuint onCreate(State& state) override;
    bool   onUpdate(State& state) override;
    bool   onRelease(State& state) override;

  private:
    VI_OBJECT_DATA
};
} // namespace glr