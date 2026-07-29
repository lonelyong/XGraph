#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>

#include <xg/igl/engine/GLObject.hpp>

namespace xg
{
namespace glr
{

class Shader;

class IGL_CORE_API Program : public GLObject {
    V_OBJECT_META_DECL

  public:
    Program();
    Program(const std::string& vs_code, const std::string& gs_code, const std::string& fs_code);
    virtual ~Program();

  public:
    void use(State& state);
    void unuse(State& state);

    std::string getName() const;
    void        setName(const std::string& name);

    template <typename T>
    void set(State& state, const std::string& name, const T& val);
    template <typename T>
    void set(State& state, GLuint_t loc, const T& val);

    void attachShader(Shader* shader);

  public:
    /**
     * @brief Shader will not be created if file is not exist or empty.
     * @param vs_path
     * @param gs_path
     * @param fs_path
     * @return
     */
    static Program* createFromFile(const std::string& vs_path, const std::string& gs_path, const std::string& fs_path);

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