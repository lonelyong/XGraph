#include "Viewport.h"

#include <vector>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {

#pragma region Viewport
V_OBJECT_META_IMPL(Viewport, StateAttribute);

struct Viewport::Data {
    GLint_t   x = 0, y = 0;
    GLsizei_t w = 1, h = 1;
};

Viewport::Viewport()
  : d(new Data()) {
}
Viewport::Viewport(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : d(new Data()) {

    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}
Viewport::~Viewport() {
    delete d;
}
Viewport::Type Viewport::getType() const {
    return VIEWPORT;
}
void Viewport::set(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h) {
    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}
void Viewport::get(GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h) {
    o_x = d->x;
    o_y = d->y;
    o_w = d->w;
    o_h = d->h;
}
void Viewport::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglViewport(d->x, d->y, d->w, d->h);
}

#pragma endregion

#pragma region ViewportIndexed
V_OBJECT_META_IMPL(ViewportIndexed, StateAttribute);

struct ViewportIndexed::Data {
    GLuint_t  index = 0;
    GLfloat_t x = 0.f, y = 0.f;
    GLfloat_t w = 1.f, h = 1.f;
};

ViewportIndexed::ViewportIndexed()
  : d(new Data()) {
}

ViewportIndexed::ViewportIndexed(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h)
  : d(new Data()) {

    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}
ViewportIndexed::~ViewportIndexed() {
    delete d;
}
ViewportIndexed::Type ViewportIndexed::getType() const {
    return VIEWPORT_INDEXED;
}
void ViewportIndexed::set(GLuint_t index, GLfloat_t x, GLfloat_t y, GLfloat_t w, GLfloat_t h) {
    d->index = index;
    d->x     = x;
    d->y     = y;
    d->w     = w;
    d->h     = h;
}
void ViewportIndexed::get(GLuint_t& o_index, GLfloat_t& o_x, GLfloat_t& o_y, GLfloat_t& o_w, GLfloat_t& o_h) {
    o_index = d->index;
    o_x     = d->x;
    o_y     = d->y;
    o_w     = d->w;
    o_h     = d->h;
}
void ViewportIndexed::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglViewportIndexedf(d->index, d->x, d->y, d->w, d->h);
}
#pragma endregion

#pragma region ViewportArray

V_OBJECT_META_IMPL(ViewportArray, StateAttribute);

struct ViewportArray::Data {
    GLuint_t               first = 0;
    GLsizei_t              count = 0;
    std::vector<GLfloat_t> xywh_pairs;
};

ViewportArray::ViewportArray()
  : d(new Data()) {
}

ViewportArray::~ViewportArray() {
    delete d;
}

ViewportArray::Type ViewportArray::getType() const {
    return VIEWPORT_ARRAY;
}

void ViewportArray::setFirst(GLuint_t first) {
    d->first = first;
}

GLuint_t ViewportArray::getFirst() const {
    return d->first;
}

void ViewportArray::apply(State& state) const {
    auto funcs = state.getContext()->getFuncs();
    funcs->iglViewportArrayv(d->first, d->count, d->xywh_pairs.data());
}
#pragma endregion

} // namespace glr