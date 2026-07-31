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

Depth::Depth(GLdouble_t near, GLdouble_t far, Func func, GLboolean_t mask)
  : near_(near)
  , far_(far)
  , func_(func)
  , mask_(mask)
{}

Depth::~Depth() = default;

void Depth::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglDepthFunc(func_);
    funcs->oglDepthMask(mask_);
    funcs->oglDepthRange(near_, far_);
}

#pragma endregion

#pragma region DepthRangeIndexed
V_OBJECT_META_IMPL(DepthRangeIndexed, StateAttribute);

DepthRangeIndexed::DepthRangeIndexed(GLuint_t index, GLdouble_t near, GLdouble_t far)
  : index_(index)
  , near_(near)
  , far_(far)
{}

DepthRangeIndexed::~DepthRangeIndexed() = default;

void DepthRangeIndexed::apply(State& state) const
{
    auto funcs = state.getContext()->getFuncs();
    funcs->oglDepthRangeIndexed(index_, near_, far_);
}

#pragma endregion

#pragma region DepthRangeArray
V_OBJECT_META_IMPL(DepthRangeArray, StateAttribute);

DepthRangeArray::DepthRangeArray() = default;

DepthRangeArray::~DepthRangeArray() = default;

void DepthRangeArray::apply(State& state) const
{
    if (count_ > 0) {
        auto funcs = state.getContext()->getFuncs();
        funcs->oglDepthRangeArrayv(first_, count_, near_far_pairs_.data());
    }
}

#pragma endregion

} // namespace glr
} // namespace xg