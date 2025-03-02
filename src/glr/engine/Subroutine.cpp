#include <glr/engine/Subroutine.h>

#include <glr/engine/Shader.h>
#include <glr/engine/State.h>

namespace glr {
VI_OBJECT_META_IMPL(Subroutine, UniformBase);

struct Subroutine::Data {
    ShaderType  type = UNDEFINED;
    std::string name;
};

Subroutine::Subroutine(ShaderType type, const std::string name)
  : d(new Data()) {
    d->type = type;
    d->name = name;
}

Subroutine::~Subroutine() {
    delete d;
}

StateAttribute::Type Subroutine::getType() const {
    return ATTR_SUBROUTINE;
}

void Subroutine::apply(State& state) const {
    auto shader = state.getCurrentShader();
    if (shader && d->type != UNDEFINED) {
        if (!d->name.empty()) {
            auto loc = glGetSubroutineIndex(shader->getId(state), d->type, d->name.data());
            if (loc != GL_INVALID_INDEX) {
                glUniformSubroutinesuiv(d->type, 1, &loc);
            }
        }
    }
}

const std::string& Subroutine::getName() const {
    return d->name;
}
} // namespace glr