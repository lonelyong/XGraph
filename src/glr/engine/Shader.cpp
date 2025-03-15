#include <glr/engine/Shader.h>

#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <sstream>

#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

namespace glr {
namespace {
std::string readCode(const std::string& path) {
    if (path.empty()) return {};
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

inline void compileShader(GLuint_t id, const std::string& source) {
    auto code_cstr = source.data();
    glShaderSource(id, 1, &code_cstr, NULL);
    glCompileShader(id);

    GLint status;
    char  msg[512];

    glGetShaderiv(id, GL_COMPILE_STATUS, &status);
    if (0 == status) {
        glGetShaderInfoLog(id, sizeof(msg), NULL, msg);
        std::cerr << "ERROR: failed to compile the shader" << msg << std::endl;
        throw std::exception("Compile shader failed.");
    }
}
} // namespace

VI_OBJECT_META_IMPL(Shader, GLObject);

struct Shader::Data {
    Type        type = (Type)0;
    std::string code;
};

Shader::Shader()
  : d(new Data()) {
}

Shader::Shader(Type type, const std::string& code)
  : d(new Data()) {
    d->type = type;
    d->code = code;
}

Shader::~Shader() {
    delete d;
}

Shader::Type Shader::getType() const {
    return d->type;
}

void Shader::setType(Type type) {
    if (type != d->type) {
        d->type = type;
        dirty();
    }
}

std::string Shader::getSource() const {
    return d->code;
}

void Shader::setSource(const std::string& source) {
    if (source != d->code) {
        d->code = source;
        dirty();
    }
}

GLuint_t Shader::onCreate(State& state) {
    if (d->type && !d->code.empty()) {
        auto id = glCreateShader(d->type);
        compileShader(id, d->code);
        return id;
    }
    return 0;
}

bool Shader::onUpdate(State& state) {
    if (d->type && !d->code.empty()) {
        auto id = getId(state);
        compileShader(id, d->code);
        return true;
    }
    else {
        release(state);
    }
    return false;
}

bool Shader::onRelease(State& state) {
    auto id = getId(state);
    glDeleteShader(id);
    return true;
}

Shader* Shader::createFromFile(Type type, const std::string& path) {
    auto code = readCode(path);

    if (code.empty()) return nullptr;

    return new Shader(type, code);
}
} // namespace glr