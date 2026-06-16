#include <xg/glr/engine/FrontFace.h>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/State.h>
#include <xg/glr/igl/GLfuncs.h>

namespace glr {

V_OBJECT_META_IMPL(FrontFace, StateAttribute);

struct FrontFace::Data {
    Mode mode = CCW;
};

FrontFace::FrontFace()
  : d(new Data()) {
}

FrontFace::FrontFace(Mode mode)
  : d(new Data()) {
    setMode(mode);
}

FrontFace::~FrontFace() {
    delete d;
}

FrontFace::Mode FrontFace::getMode() const {
    return d->mode;
}

void FrontFace::setMode(Mode mode) {
    d->mode = mode;
}

FrontFace::Type FrontFace::getType() const {
    return FRONT_FACE;
}

void FrontFace::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglFrontFace(d->mode);
}

} // namespace glr