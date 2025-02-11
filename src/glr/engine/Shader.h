#pragma once

#include <glr/glrenderer_global.h>

#include <string>

#include <glr/engine/GLObject.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API Shader : public GLObject {
    VI_OBJECT_META;

  public:
    Shader(const std::string& vs_code, const std::string& gs_code, const std::string& fs_code);
    virtual ~Shader();

  public:
    void use(State& state);
    void unuse(State& state);

    std::string getName() const;
    void        setName(const std::string& name);

    template <typename T> void set(State& state, const std::string& name, const T& val) {
        auto id  = getId(state);
        auto loc = glGetUniformLocation(id, name.data());
        if (loc >= 0) {
            set<T>(state, loc, val);
        }
    }

    template <typename T> void set(State& state, GLuint loc, const T& val);

  public:
    static Shader* create(const std::string& vs_path, const std::string& gs_path, const std::string& fs_path);

  protected:
    GLuint onCreate(State& state) override;
    void   onRelease(State& state) override;

  private:
    struct Data;
    Data* const d;
};
} // namespace glr