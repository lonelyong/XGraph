#include <glr/engine/BlendEquation.h>

#include <glad/glad.h>

namespace glr {

#pragma region BlendEquation
VI_OBJECT_META_IMPL(BlendEquation, StateAttribute);

struct BlendEquation::Data {
    Equation equation_rdb   = FUNC_ADD;
    Equation equation_alpha = FUNC_ADD;
};

BlendEquation::BlendEquation()
  : d(new Data()) {
}

BlendEquation::BlendEquation(Equation equation)
  : d(new Data()) {
    setEquation(equation);
}

BlendEquation::~BlendEquation() {
    delete d;
}

BlendEquation::Type BlendEquation::getType() const {
    return BLEND_EQUATION;
}

void BlendEquation::setEquation(Equation equation) {
    d->equation_alpha = d->equation_rdb = equation;
}

BlendEquation::Equation BlendEquation::getEquation() const {
    return d->equation_rdb;
}

BlendEquation::Equation BlendEquation::getEquationRGB() const {
    return d->equation_rdb;
}

void BlendEquation::setEquationRGB(Equation equation) {
    d->equation_rdb = equation;
}

BlendEquation::Equation BlendEquation::getEquationAlpha() const {
    return d->equation_alpha;
}

void BlendEquation::setEquationAlpha(Equation equation) {
    d->equation_alpha = equation;
}

void BlendEquation::apply(State& state) const {
    if (d->equation_alpha == d->equation_rdb) {
        glBlendEquation(d->equation_rdb);
    }
    else {
        glBlendEquationSeparate(d->equation_rdb, d->equation_alpha);
    }
}
#pragma endregion

#pragma region BlendEquationi
VI_OBJECT_META_IMPL(BlendEquationi, StateAttribute);

struct BlendEquationi::Data {
    GLuint_t index = 0;
};

BlendEquationi::BlendEquationi()
  : d(new Data()) {
}

BlendEquationi::BlendEquationi(GLuint_t buf, Equation equation)
  : BlendEquation(equation)
  , d(new Data()) {
    d->index = buf;
}

BlendEquationi::~BlendEquationi() {
    delete d;
}

BlendEquationi::Type BlendEquationi::getType() const {
    return BLEND_EQUATION;
}

void BlendEquationi::setIndex(GLuint_t index) {
    d->index = index;
}

GLuint_t BlendEquationi::getIndex() const {
    return d->index;
}

void BlendEquationi::apply(State& state) const {
    auto equation_rgb   = getEquationRGB();
    auto equation_alpha = getEquationAlpha();
    if (equation_rgb == equation_alpha) {
        glBlendEquationi(d->index, equation_rgb);
    }
    else {
        glBlendEquationSeparatei(d->index, equation_rgb, equation_alpha);
    }
}
#pragma endregion

} // namespace glr