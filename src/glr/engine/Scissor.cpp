#include "Scissor.h"

#include <vector>

#include <glad/glad.h>

namespace glr {

#pragma region Scissor
VI_OBJECT_META_IMPL(Scissor, StateAttribute);

struct Scissor::Data {
    GLint   x = 0, y = 0;
    GLsizei w = 1, h = 1;
};

Scissor::Scissor()
  : d(new Data()) {
}
Scissor::Scissor(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : d(new Data()) {

    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}
Scissor::~Scissor() {
    delete d;
}
Scissor::Type Scissor::getType() const {
    return SCISSOR;
}
void Scissor::set(GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h) {
    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}
void Scissor::get(GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h) {
    o_x = d->x;
    o_y = d->y;
    o_w = d->w;
    o_h = d->h;
}
void Scissor::apply(State& state) const {
    glScissor(d->x, d->y, d->w, d->h);
}

#pragma endregion

#pragma region ScissorIndexed
VI_OBJECT_META_IMPL(ScissorIndexed, StateAttribute);

struct ScissorIndexed::Data {
    GLuint  index = 0;
    GLint   x = 0, y = 0;
    GLsizei w = 1, h = 1;
};

ScissorIndexed::ScissorIndexed()
  : d(new Data()) {
}

ScissorIndexed::ScissorIndexed(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h)
  : d(new Data()) {

    d->x = x;
    d->y = y;
    d->w = w;
    d->h = h;
}
ScissorIndexed::~ScissorIndexed() {
    delete d;
}
ScissorIndexed::Type ScissorIndexed::getType() const {
    return SCISSOR_INDEXED;
}
void ScissorIndexed::set(GLuint_t index, GLint_t x, GLint_t y, GLsizei_t w, GLsizei_t h) {
    d->index = index;
    d->x     = x;
    d->y     = y;
    d->w     = w;
    d->h     = h;
}
void ScissorIndexed::get(GLuint_t& o_index, GLint_t& o_x, GLint_t& o_y, GLsizei_t& o_w, GLsizei_t& o_h) {
    o_index = d->index;
    o_x     = d->x;
    o_y     = d->y;
    o_w     = d->w;
    o_h     = d->h;
}
void ScissorIndexed::apply(State& state) const {
    glScissorIndexed(d->index, d->x, d->y, d->w, d->h);
}
#pragma endregion

#pragma region ScissorArray

VI_OBJECT_META_IMPL(ScissorArray, StateAttribute);

struct ScissorArray::Data {
    GLuint             first = 0;
    GLsizei            count = 0;
    std::vector<GLint> xywh_pairs;
};

ScissorArray::ScissorArray()
  : d(new Data()) {
}

ScissorArray::~ScissorArray() {
    delete d;
}

ScissorArray::Type ScissorArray::getType() const {
    return SCISSOR_ARRAY;
}

void ScissorArray::setFirst(GLuint_t first) {
    d->first = first;
}

GLuint_t ScissorArray::getFirst() const {
    return d->first;
}

void ScissorArray::apply(State& state) const {
    glScissorArrayv(d->first, d->count, d->xywh_pairs.data());
}
#pragma endregion

} // namespace glr