#include <xg/glr/engine/BlendEquation.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

namespace xg {
namespace glr {

#pragma region BlendEquation
V_OBJECT_META_IMPL(BlendEquation, StateAttribute);

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
    auto funcs = state.getContext()->getFuncs();
    if (d->equation_alpha == d->equation_rdb) {
        funcs->iglBlendEquation(d->equation_rdb);
    }
    else {
        //funcs->iglBlendEquationSeparate(d->equation_rdb, d->equation_alpha);
    }
}
#pragma endregion

#pragma region BlendEquationi
V_OBJECT_META_IMPL(BlendEquationi, StateAttribute);

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
    auto funcs          = state.getContext()->getFuncs();
    auto equation_rgb   = getEquationRGB();
    auto equation_alpha = getEquationAlpha();
    if (equation_rgb == equation_alpha) {
        funcs->iglBlendEquationi(d->index, equation_rgb);
    }
    else {
        funcs->iglBlendEquationSeparatei(d->index, equation_rgb, equation_alpha);
    }
}
#pragma endregion

} // namespace glr
} // namespace xg