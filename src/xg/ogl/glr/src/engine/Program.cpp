#include <xg/glr/engine/Program.h>

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <unordered_map>

#include <glm/gtc/type_ptr.hpp>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/Shader.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/engine/types.h>
#include <xg/glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(Program, GLObject);

struct Program::Data {
    std::string name;

    std::unordered_map<Shader::Type, vine::RefPtr<Shader>> shaders;
};

Program::Program()
  : d(new Data()) {
}

Program::Program(const std::string& vs_code, const std::string& gs_code, const std::string& fs_code)
  : d(new Data()) {

    if (!vs_code.empty()) {
        d->shaders.insert({ Shader::VERTEX, new Shader(Shader::VERTEX, vs_code) });
    }
    if (!gs_code.empty()) {
        d->shaders.insert({ Shader::GEOMETRY, new Shader(Shader::GEOMETRY, gs_code) });
    }
    if (!fs_code.empty()) {
        d->shaders.insert({ Shader::FRAGMENT, new Shader(Shader::FRAGMENT, fs_code) });
    }
}

Program::~Program() {
    delete d;
}

void Program::use(State& state) {
    if (!isCreated(state)) GLObject::create(state);
    if (!isCreated(state)) return;
    auto funcs = state.getContext()->getFuncs();
    funcs->iglUseProgram(getId(state));
}

void Program::unuse(State& state) {
    auto id = getId(state);
    if (id) {
        auto    funcs = state.getContext()->getFuncs();
        GLint_t current_prog;
        funcs->iglGetIntegerv(IGL_CURRENT_PROGRAM, &current_prog);
        if (current_prog == id) funcs->iglUseProgram(0);
    }
}

std::string Program::getName() const {
    return d->name;
}

void Program::setName(const std::string& name) {
    d->name = name;
}

void Program::attachShader(Shader* shader) {
    if (shader) {
        if (d->shaders.contains(shader->getType())) {
            d->shaders[shader->getType()] == shader;
        }
        else {
            d->shaders.insert({ shader->getType(), shader });
        }
    }
}

template <typename T> void Program::set(State& state, GLuint_t loc, const T& val) {
    auto funcs = state.getContext()->getFuncs();
    if constexpr (std::is_same<T, bool>::value) {
        funcs->iglUniform1i(loc, (int)val);
    }
    else if constexpr (std::is_same<T, Vec2b>::value) {
        funcs->iglUniform2i(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3b>::value) {
        funcs->iglUniform3i(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4b>::value) {
        funcs->iglUniform4i(loc, val.r, val.g, val.b, val.a);
    }

    else if constexpr (std::is_same<T, int>::value) {
        funcs->iglUniform1i(loc, val);
    }
    else if constexpr (std::is_same<T, unsigned int>::value) {
        funcs->iglUniform1ui(loc, val);
    }
    else if constexpr (std::is_same<T, Vec2i>::value) {
        funcs->iglUniform2i(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3i>::value) {
        funcs->iglUniform3i(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4i>::value) {
        funcs->iglUniform4i(loc, val.r, val.g, val.b, val.a);
    }

    else if constexpr (std::is_same<T, float>::value) {
        funcs->iglUniform1f(loc, val);
    }
    else if constexpr (std::is_same<T, Vec2f>::value) {
        funcs->iglUniform2f(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3f>::value) {
        funcs->iglUniform3f(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4f>::value) {
        funcs->iglUniform4f(loc, val.r, val.g, val.b, val.a);
    }
    else if constexpr (std::is_same<T, Mat3f>::value) {
        funcs->iglUniformMatrix3fv(loc, 1, IGL_FALSE, glm::value_ptr(val));
    }
    else if constexpr (std::is_same<T, Mat4f>::value) {
        funcs->iglUniformMatrix4fv(loc, 1, IGL_FALSE, glm::value_ptr(val));
    }

    else if constexpr (std::is_same<T, double>::value) {
        funcs->iglUniform1d(loc, val);
    }
    else if constexpr (std::is_same<T, Vec2d>::value) {
        funcs->iglUniform2d(loc, val.x, val.y);
    }
    else if constexpr (std::is_same<T, Vec3d>::value) {
        funcs->iglUniform3d(loc, val.x, val.y, val.z);
    }
    else if constexpr (std::is_same<T, Vec4d>::value) {
        funcs->iglUniform4d(loc, val.r, val.g, val.b, val.a);
    }
    else if constexpr (std::is_same<T, Mat3d>::value) {
        // glUniformMatrix3dv(loc, 1, GL_FALSE, glm::value_ptr(val));
        funcs->iglUniformMatrix3fv(loc, 1, IGL_FALSE, glm::value_ptr(Mat3f(val)));
    }
    else if constexpr (std::is_same<T, Mat4d>::value) {
        // glUniformMatrix4dv(loc, 1, GL_FALSE, glm::value_ptr(val));
        funcs->iglUniformMatrix4fv(loc, 1, IGL_FALSE, glm::value_ptr(Mat4f(val)));
    }
    else {
        static_assert("type not supported");
    }
}

template <typename T> void Program::set(State& state, const std::string& name, const T& val) {
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    auto loc   = funcs->iglGetUniformLocation(id, name.data());
    if (loc >= 0) {
        set<T>(state, loc, val);
    }
}

GLuint_t Program::onCreate(State& state) {
    if (d->shaders.empty()) {
        return 0;
    }
    auto funcs  = state.getContext()->getFuncs();
    auto app_id = funcs->iglCreateProgram();

    for (auto& kv : d->shaders) {
        if (kv.second->create(state)) {
            funcs->iglAttachShader(app_id, kv.second->getId(state));
        }
    }

    funcs->iglLinkProgram(app_id);

    GLint_t link_status;
    funcs->iglGetProgramiv(app_id, IGL_LINK_STATUS, &link_status);

    if (0 == link_status) {
        char msg[512];
        funcs->iglGetProgramInfoLog(app_id, sizeof(msg), NULL, msg);
        std::cerr << "ERROR: failed to link the shaders" << msg << std::endl;
        throw std::runtime_error("Link shaders failed.");
    }
    return app_id;
}

bool Program::onUpdate(State& state) {
    return false;
}

bool Program::onRelease(State& state) {
    auto funcs = state.getContext()->getFuncs();
    auto id    = getId(state);
    funcs->iglDeleteProgram(id);
    return true;
}

Program* Program::createFromFile(const std::string& vs_path, const std::string& gs_path, const std::string& fs_path) {
    auto prog      = new Program();
    auto vs_shader = Shader::createFromFile(Shader::VERTEX, vs_path);
    if (vs_shader) {
        prog->attachShader(vs_shader);
    }
    auto gs_shader = Shader::createFromFile(Shader::GEOMETRY, gs_path);
    if (gs_shader) {
        prog->attachShader(gs_shader);
    }
    auto fs_shader = Shader::createFromFile(Shader::FRAGMENT, fs_path);
    if (fs_shader) {
        prog->attachShader(fs_shader);
    }
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