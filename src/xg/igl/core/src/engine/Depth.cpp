#include <xg/igl/engine/Depth.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

#include <vector>

namespace xg
{
namespace glr
{

#pragma region Depth

V_OBJECT_META_IMPL(Depth, StateAttribute);

struct Depth::Data {
    GLdouble_t  near = 0.0;
    GLdouble_t  far  = 1.0;
    GLint_t     func = LESS;
    GLboolean_t mask = true;
};

Depth::Depth(GLdouble_t near, GLdouble_t far, Func func, GLboolean_t mask)
  : d(new Data())
{
    d->near = near;
    d->far  = far;
    d->func = func;
    d->mask = mask;
}

Depth::~Depth()
{ delete d; }

Depth::Type Depth::getType() const
{ return DEPTH; }

void Depth::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    // glGetDoublev(IGL_DEPTH_RANGE, d->prev_near_far);
    // glGetBooleanv(IGL_DEPTH_WRITEMASK, &d->prev_mask);
    // glGetIntegerv(IGL_DEPTH_FUNC, &d->prev_func);

    funcs->oglDepthFunc(d->func);
    funcs->oglDepthMask(d->mask);
    funcs->oglDepthRange(d->near, d->far);
}

#pragma endregion

#pragma region DepthRangeIndexed
V_OBJECT_META_IMPL(DepthRangeIndexed, StateAttribute);

struct DepthRangeIndexed::Data {
    GLuint_t   index = 0;
    GLdouble_t near  = 0.0;
    GLdouble_t far   = 1.0;
};

DepthRangeIndexed::DepthRangeIndexed(GLuint_t index, GLdouble_t near, GLdouble_t far)
  : d(new Data())
{
    d->index = index;
    d->near  = near;
    d->far   = far;
}

DepthRangeIndexed::~DepthRangeIndexed()
{ delete d; }

DepthRangeIndexed::Type DepthRangeIndexed::getType() const
{ return DEPTH_RANGE_INDEXED; }

void DepthRangeIndexed::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglDepthRangeIndexed(d->index, d->near, d->far);
}

#pragma endregion

#pragma region DepthRangeArray
V_OBJECT_META_IMPL(DepthRangeArray, StateAttribute);

struct DepthRangeArray::Data {
    GLuint_t                first = 0;
    GLsizei_t               count = 0;
    std::vector<GLdouble_t> near_far_pairs;
};

DepthRangeArray::DepthRangeArray()
  : d(new Data())
{}

DepthRangeArray::~DepthRangeArray()
{ delete d; }

DepthRangeArray::Type DepthRangeArray::getType() const
{ return DEPTH_RANGE_ARRAY; }

void DepthRangeArray::apply(State& state) const
{
    if (d->count > 0) {
        auto funcs = state.getContext()->getFuncs();
        funcs->oglDepthRangeArrayv(d->first, d->count, d->near_far_pairs.data());
    }
}

#pragma endregion

} // namespace glr
} // namespace xg