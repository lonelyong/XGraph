#include <xg/igl/engine/Shader.hpp>

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <sstream>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>


#include <glm/gtc/type_ptr.hpp>

namespace xg
{
namespace glr
{

namespace
{

std::string readCode(const std::string& path)
{
    if (path.empty())
        return {};
    std::string   code;
    std::ifstream fs;
    // fs.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fs.open(path);
    if (!fs.is_open()) {
        std::cerr << "Failed to read shader file:" << path << ".(" << std::strerror(errno) << ")" << std::endl;
        return code;
    }
    std::stringstream ss;
    ss << fs.rdbuf();
    fs.close();
    code = ss.str();
    return code;
}

inline void compileShader(GLfuncs* funcs, GLuint_t id, const std::string& source)
{

    auto code_cstr = source.data();
    funcs->oglShaderSource(id, 1, &code_cstr, NULL);
    funcs->oglCompileShader(id);

    GLint_t status;
    char    msg[512];

    funcs->oglGetShaderiv(id, IGL_COMPILE_STATUS, &status);
    if (0 == status) {
        funcs->oglGetShaderInfoLog(id, sizeof(msg), NULL, msg);
        std::cerr << "ERROR: failed to compile the shader" << msg << std::endl;
        throw std::runtime_error("Compile shader failed.");
    }
}

} // namespace

V_OBJECT_META_IMPL(Shader, GLObject);

Shader::Shader() = default;

Shader::Shader(Type type, const std::string& code)
  : type_(type)
  , code_(code)
{}

Shader::~Shader() = default;

void Shader::setType(Type type)
{
    if (type != type_) {
        type_ = type;
        dirty();
    }
}

void Shader::setSource(const std::string& source)
{
    if (source != code_) {
        code_ = source;
        dirty();
    }
}

GLuint_t Shader::onCreate(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    if (type_ && !code_.empty()) {
        auto id = funcs->oglCreateShader(type_);
        compileShader(funcs, id, code_);
        return id;
    }
    return 0;
}

bool Shader::onUpdate(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    if (type_ && !code_.empty()) {
        auto id = getId(state);
        compileShader(funcs, id, code_);
        return true;
    }
    else {
        release(state);
    }
    return false;
}

bool Shader::onRelease(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->oglDeleteShader(id);
    return true;
}

Shader* Shader::createFromFile(Type type, const std::string& path)
{
    auto code = readCode(path);

    if (code.empty())
        return nullptr;

    return new Shader(type, code);
}

} // namespace glr
} // namespace xg