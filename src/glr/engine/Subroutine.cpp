#include <glr/engine/Subroutine.h>

#include <glad/glad.h>

#include <glr/engine/Program.h>
#include <glr/engine/State.h>

namespace glr {
VI_OBJECT_META_IMPL(Subroutine, UniformBase);

struct Subroutine::Data {
    ShaderType  type = NO_TYPE;
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
    return SUBROUTINE;
}

void Subroutine::apply(State& state) const {
    auto shader = state.getCurrentProgram();
    if (shader && d->type != NO_TYPE) {
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