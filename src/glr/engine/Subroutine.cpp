#include <glr/engine/Subroutine.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/Program.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {
V_OBJECT_META_IMPL(Subroutine, UniformBase);

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
    auto funcs  = state.getContext()->getFuncs();
    auto shader = state.getCurrentProgram();
    if (shader && d->type != NO_TYPE) {
        if (!d->name.empty()) {
            auto loc = funcs->iglGetSubroutineIndex(shader->getId(state), d->type, d->name.data());
            if (loc != IGL_INVALID_INDEX) {
                funcs->iglUniformSubroutinesuiv(d->type, 1, &loc);
            }
        }
    }
}

const std::string& Subroutine::getName() const {
    return d->name;
}
} // namespace glr