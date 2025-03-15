#include <glr/engine/Depth.h>

#include <glad/glad.h>

#include <vector>

namespace glr {

#pragma region Depth

VI_OBJECT_META_IMPL(Depth, StateAttribute);

struct Depth::Data {
    GLdouble  near = 0.0;
    GLdouble  far  = 1.0;
    GLint     func = LESS;
    GLboolean mask = true;
};

Depth::Depth(GLdouble_t near, GLdouble_t far, Func func, GLboolean_t mask)
  : d(new Data()) {
    d->near = near;
    d->far  = far;
    d->func = func;
    d->mask = mask;
}

Depth::~Depth() {
    delete d;
}

Depth::Type Depth::getType() const {
    return DEPTH;
}

void Depth::apply(State& state) const {
    // glGetDoublev(GL_DEPTH_RANGE, d->prev_near_far);
    // glGetBooleanv(GL_DEPTH_WRITEMASK, &d->prev_mask);
    // glGetIntegerv(GL_DEPTH_FUNC, &d->prev_func);

    glDepthFunc(d->func);
    glDepthMask(d->mask);
    glDepthRange(d->near, d->far);
}
#pragma endregion

#pragma region DepthRangeIndexed
VI_OBJECT_META_IMPL(DepthRangeIndexed, StateAttribute);

struct DepthRangeIndexed::Data {
    GLuint_t index = 0;
    GLdouble near  = 0.0;
    GLdouble far   = 1.0;
};

DepthRangeIndexed::DepthRangeIndexed(GLuint_t index, GLdouble_t near, GLdouble_t far)
  : d(new Data()) {
    d->index = index;
    d->near  = near;
    d->far   = far;
}

DepthRangeIndexed::~DepthRangeIndexed() {
    delete d;
}

DepthRangeIndexed::Type DepthRangeIndexed::getType() const {
    return DEPTH_RANGE_INDEXED;
}

void DepthRangeIndexed::apply(State& state) const {
    glDepthRangeIndexed(d->index, d->near, d->far);
}
#pragma endregion

#pragma region DepthRangeArray
VI_OBJECT_META_IMPL(DepthRangeArray, StateAttribute);

struct DepthRangeArray::Data {
    GLuint_t                first = 0;
    GLsizei                 count = 0;
    std::vector<GLdouble_t> near_far_pairs;
};

DepthRangeArray::DepthRangeArray()
  : d(new Data()) {
}

DepthRangeArray::~DepthRangeArray() {
    delete d;
}

DepthRangeArray::Type DepthRangeArray::getType() const {
    return DEPTH_RANGE_ARRAY;
}

void DepthRangeArray::apply(State& state) const {
    if (d->count > 0) {
        glDepthRangeArrayv(d->first, d->count, d->near_far_pairs.data());
    }
}
#pragma endregion

} // namespace glr