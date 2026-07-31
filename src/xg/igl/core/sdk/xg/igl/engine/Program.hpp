#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>
#include <unordered_map>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/GLObject.hpp>
#include <xg/igl/engine/Shader.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API Program : public GLObject {
    V_OBJECT_META_DECL

  public:
    Program();
    Program(const std::string& vs_code, const std::string& gs_code, const std::string& fs_code);
    virtual ~Program();

  public:
    void use(State& state);
    void unuse(State& state);

    std::string getName() const { return name_; }
    void        setName(const std::string& name) { name_ = name; }

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
    std::string                                        name_;
    std::unordered_map<Shader::Type, vine::RefPtr<Shader>> shaders_;
};

} // namespace glr
} // namespace xg