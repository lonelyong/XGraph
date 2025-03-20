#include <glr/scene/PrimitiveSet.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {
using Mode = PrimitiveSet::Mode;

VI_OBJECT_META_IMPL(PrimitiveSet, Object);
VI_OBJECT_META_IMPL(DrawArrays, PrimitiveSet);
VI_OBJECT_META_IMPL(DrawElementsUInt, PrimitiveSet);

PrimitiveSet::PrimitiveSet() {
}

PrimitiveSet::PrimitiveSet(Mode mode, GLsizei_t insts)
  : mode_(mode)
  , instances_(insts) {
}

Mode PrimitiveSet::getMode() const {
    return mode_;
}

void PrimitiveSet::setMode(Mode mode) {
    mode_ = mode;
}

GLint_t PrimitiveSet::getInstances() const {
    return instances_;
}

void PrimitiveSet::setInstances(GLint_t insts) {
    instances_ = insts;
}

DrawArrays::DrawArrays() {
}

DrawArrays::DrawArrays(Mode mode, GLint_t offset, GLsizei_t count)
  : DrawArrays(mode, offset, count, 1) {
}

DrawArrays::DrawArrays(Mode mode, GLint_t offset, GLsizei_t count, GLsizei_t insts)
  : PrimitiveSet(mode, insts)
  , offset_(offset)
  , count_(count) {
}

GLint_t DrawArrays::getOffset() const {
    return offset_;
}

void DrawArrays::setOffset(GLint_t offset) {
    offset_ = offset;
}

GLsizei_t DrawArrays::getCount() const {
    return count_;
}

void DrawArrays::setCount(GLsizei_t count) {
    count = count;
}

void DrawArrays::draw(State& state) {
    auto funcs = state.getContext()->getFuncs();
    auto mode  = getMode();
    auto insts = getInstances();

    if (insts > 1) {
        funcs->iglDrawArraysInstanced(mode, offset_, count_, insts);
    }
    else {
        funcs->iglDrawArrays(mode, offset_, count_);
    }
}

DrawElementsUInt::DrawElementsUInt() {
}

DrawElementsUInt::DrawElementsUInt(Mode mode)
  : DrawElementsUInt(mode, 1) {
}

DrawElementsUInt::DrawElementsUInt(Mode mode, GLint_t insts)
  : PrimitiveSet(mode, insts) {
}

void DrawElementsUInt::setIndices(std::vector<GLuint_t> indices) {
    indices_ = std::move(indices);
}

std::vector<GLuint_t>& DrawElementsUInt::getIndices() {
    return indices_;
}

void DrawElementsUInt::draw(State& state) {
    auto funcs = state.getContext()->getFuncs();
    if (indices_.empty()) return;
    auto mode  = getMode();
    auto insts = getInstances();
    if (insts > 1) {
        funcs->iglDrawElementsInstanced(mode, indices_.size(), IGL_UNSIGNED_INT, (void*)indices_.data(), insts);
    }
    else {
        funcs->iglDrawElements(mode, indices_.size(), IGL_UNSIGNED_INT, (void*)indices_.data());
    }
}
} // namespace glr