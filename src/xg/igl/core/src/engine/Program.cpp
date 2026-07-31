#include <xg/igl/engine/Program.hpp>

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include <glm/gtc/type_ptr.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Shader.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/engine/types.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Program, GLObject);

Program::Program() = default;

Program::Program(const std::string& vs_code, const std::string& gs_code, const std::string& fs_code)
{
    if (!vs_code.empty()) { shaders_.insert({ Shader::VERTEX, new Shader(Shader::VERTEX, vs_code) }); }
    if (!gs_code.empty()) { shaders_.insert({ Shader::GEOMETRY, new Shader(Shader::GEOMETRY, gs_code) }); }
    if (!fs_code.empty()) { shaders_.insert({ Shader::FRAGMENT, new Shader(Shader::FRAGMENT, fs_code) }); }
}

Program::~Program() = default;

void Program::use(State& state)
{
    if (!isCreated(state))
        GLObject::create(state);
    if (!isCreated(state))
        return;
    auto funcs = state.getContext()->getFuncs();
    funcs->oglUseProgram(getId(state));
}

void Program::unuse(State& state)
{
    auto id = getId(state);
    if (id) {
        auto    funcs = state.getContext()->getFuncs();
        GLint_t current_prog;
        funcs->oglGetIntegerv(IGL_CURRENT_PROGRAM, &current_prog);
        if (current_prog == id)
            funcs->oglUseProgram(0);
    }
}

void Program::attachShader(Shader* shader)
{
    if (shader) {
        if (shaders_.contains(shader->getType())) { shaders_[shader->getType()] = shader; }
        else {
            shaders_.insert({ shader->getType(), shader });
        }
    }
}

template <typename T>
void Program::set(State& state, GLuint_t loc, const T& val)
{
    auto funcs = state.getContext()->getFuncs();
    if constexpr (std::is_same<T, bool>::value) { funcs->oglUniform1i(loc, (int)val); }
    else if constexpr (std::is_same<T, Vec2b>::value) {
        funcs->oglUniform2i(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3b>::value) {
        funcs->oglUniform3i(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4b>::value) {
        funcs->oglUniform4i(loc, val.r, val.g, val.b, val.a);
    }

    else if constexpr (std::is_same<T, int>::value) {
        funcs->oglUniform1i(loc, val);
    }
    else if constexpr (std::is_same<T, unsigned int>::value) {
        funcs->oglUniform1ui(loc, val);
    }
    else if constexpr (std::is_same<T, Vec2i>::value) {
        funcs->oglUniform2i(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3i>::value) {
        funcs->oglUniform3i(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4i>::value) {
        funcs->oglUniform4i(loc, val.r, val.g, val.b, val.a);
    }

    else if constexpr (std::is_same<T, float>::value) {
        funcs->oglUniform1f(loc, val);
    }
    else if constexpr (std::is_same<T, Vec2f>::value) {
        funcs->oglUniform2f(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3f>::value) {
        funcs->oglUniform3f(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4f>::value) {
        funcs->oglUniform4f(loc, val.r, val.g, val.b, val.a);
    }
    else if constexpr (std::is_same<T, Mat3f>::value) {
        funcs->oglUniformMatrix3fv(loc, 1, IGL_FALSE, glm::value_ptr(val));
    }
    else if constexpr (std::is_same<T, Mat4f>::value) {
        funcs->oglUniformMatrix4fv(loc, 1, IGL_FALSE, glm::value_ptr(val));
    }

    else if constexpr (std::is_same<T, double>::value) {
        funcs->oglUniform1d(loc, val);
    }
    else if constexpr (std::is_same<T, Vec2d>::value) {
        funcs->oglUniform2d(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3d>::value) {
        funcs->oglUniform3d(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4d>::value) {
        funcs->oglUniform4d(loc, val.r, val.g, val.b, val.a);
    }
    else if constexpr (std::is_same<T, Mat3d>::value) {
        // glUniformMatrix3dv(loc, 1, GL_FALSE, glm::value_ptr(val));
        funcs->oglUniformMatrix3fv(loc, 1, IGL_FALSE, glm::value_ptr(Mat3f(val)));
    }
    else if constexpr (std::is_same<T, Mat4d>::value) {
        // glUniformMatrix4dv(loc, 1, GL_FALSE, glm::value_ptr(val));
        funcs->oglUniformMatrix4fv(loc, 1, IGL_FALSE, glm::value_ptr(Mat4f(val)));
    }
    else {
        static_assert("type not supported");
    }
}

template <typename T>
void Program::set(State& state, const std::string& name, const T& val)
{
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    auto loc   = funcs->oglGetUniformLocation(id, name.data());
    if (loc >= 0) { set<T>(state, loc, val); }
}

GLuint_t Program::onCreate(State& state)
{
    if (shaders_.empty()) { return 0; }
    auto funcs  = state.getContext()->getFuncs();
    auto app_id = funcs->oglCreateProgram();

    for (auto& kv : shaders_) {
        if (kv.second->create(state)) { funcs->oglAttachShader(app_id, kv.second->getId(state)); }
    }

    funcs->oglLinkProgram(app_id);

    GLint_t link_status;
    funcs->oglGetProgramiv(app_id, IGL_LINK_STATUS, &link_status);

    if (0 == link_status) {
        char msg[512];
        funcs->oglGetProgramInfoLog(app_id, sizeof(msg), NULL, msg);
        std::cerr << "ERROR: failed to link the shaders" << msg << std::endl;
        throw std::runtime_error("Link shaders failed.");
    }
    return app_id;
}

bool Program::onUpdate(State& state)
{ return false; }

bool Program::onRelease(State& state)
{
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->oglDeleteProgram(id);
    return true;
}

Program* Program::createFromFile(const std::string& vs_path, const std::string& gs_path, const std::string& fs_path)
{
    auto prog      = new Program();
    auto vs_shader = Shader::createFromFile(Shader::VERTEX, vs_path);
    if (vs_shader) { prog->attachShader(vs_shader); }
    auto gs_shader = Shader::createFromFile(Shader::GEOMETRY, gs_path);
    if (gs_shader) { prog->attachShader(gs_shader); }
    auto fs_shader = Shader::createFromFile(Shader::FRAGMENT, fs_path);
    if (fs_shader) { prog->attachShader(fs_shader); }
    return prog;
}

template void Program::set<bool>(State&, const std::string&, const bool&);
template void Program::set<Vec2b>(State&, const std::string&, const Vec2b&);
template void Program::set<Vec3b>(State&, const std::string&, const Vec3b&);
template void Program::set<Vec4b>(State&, const std::string&, const Vec4b&);
template void Program::set<int>(State&, const std::string&, const int&);
template void Program::set<unsigned int>(State&, const std::string&, const unsigned int&);
template void Program::set<Vec2i>(State&, const std::string&, const Vec2i&);
template void Program::set<Vec3i>(State&, const std::string&, const Vec3i&);
template void Program::set<Vec4i>(State&, const std::string&, const Vec4i&);
template void Program::set<float>(State&, const std::string&, const float&);
template void Program::set<Vec2f>(State&, const std::string&, const Vec2f&);
template void Program::set<Vec3f>(State&, const std::string&, const Vec3f&);
template void Program::set<Vec4f>(State&, const std::string&, const Vec4f&);
template void Program::set<double>(State&, const std::string&, const double&);
template void Program::set<Vec2d>(State&, const std::string&, const Vec2d&);
template void Program::set<Vec3d>(State&, const std::string&, const Vec3d&);
template void Program::set<Vec4d>(State&, const std::string&, const Vec4d&);
template void Program::set<Mat3f>(State&, const std::string&, const Mat3f&);
template void Program::set<Mat4f>(State&, const std::string&, const Mat4f&);
template void Program::set<Mat3d>(State&, const std::string&, const Mat3d&);
template void Program::set<Mat4d>(State&, const std::string&, const Mat4d&);

template void Program::set<bool>(State&, GLuint_t, const bool&);
template void Program::set<Vec2b>(State&, GLuint_t, const Vec2b&);
template void Program::set<Vec3b>(State&, GLuint_t, const Vec3b&);
template void Program::set<Vec4b>(State&, GLuint_t, const Vec4b&);
template void Program::set<int>(State&, GLuint_t, const int&);
template void Program::set<unsigned int>(State&, GLuint_t, const unsigned int&);
template void Program::set<Vec2i>(State&, GLuint_t, const Vec2i&);
template void Program::set<Vec3i>(State&, GLuint_t, const Vec3i&);
template void Program::set<Vec4i>(State&, GLuint_t, const Vec4i&);
template void Program::set<float>(State&, GLuint_t, const float&);
template void Program::set<Vec2f>(State&, GLuint_t, const Vec2f&);
template void Program::set<Vec3f>(State&, GLuint_t, const Vec3f&);
template void Program::set<Vec4f>(State&, GLuint_t, const Vec4f&);
template void Program::set<double>(State&, GLuint_t, const double&);
template void Program::set<Vec2d>(State&, GLuint_t, const Vec2d&);
template void Program::set<Vec3d>(State&, GLuint_t, const Vec3d&);
template void Program::set<Vec4d>(State&, GLuint_t, const Vec4d&);
template void Program::set<Mat3f>(State&, GLuint_t, const Mat3f&);
template void Program::set<Mat4f>(State&, GLuint_t, const Mat4f&);
template void Program::set<Mat3d>(State&, GLuint_t, const Mat3d&);
template void Program::set<Mat4d>(State&, GLuint_t, const Mat4d&);

} // namespace glr
} // namespace xg