#include <vkr/scene/PrimitiveSet.h>

namespace vkr {
using Mode = PrimitiveSet::Mode;

VI_OBJECT_META_IMPL(PrimitiveSet, Object);
VI_OBJECT_META_IMPL(DrawArrays, PrimitiveSet);
VI_OBJECT_META_IMPL(DrawElementsUInt, PrimitiveSet);

PrimitiveSet::PrimitiveSet() {
}

PrimitiveSet::PrimitiveSet(Mode mode, int insts)
  : mode_(mode)
  , instances_(insts) {
}

Mode PrimitiveSet::getMode() const {
    return mode_;
}

void PrimitiveSet::setMode(Mode mode) {
    mode_ = mode;
}

int PrimitiveSet::getInstances() const {
    return instances_;
}

void PrimitiveSet::setInstances(int insts) {
    instances_ = insts;
}

DrawArrays::DrawArrays() {
}

DrawArrays::DrawArrays(Mode mode, int offset, int count)
  : DrawArrays(mode, offset, count, 1) {
}

DrawArrays::DrawArrays(Mode mode, int offset, int count, int insts)
  : PrimitiveSet(mode, insts)
  , offset_(offset)
  , count_(count) {
}

int DrawArrays::getOffset() const {
    return offset_;
}

void DrawArrays::setOffset(int offset) {
    offset_ = offset;
}

int DrawArrays::getCount() const {
    return count_;
}

void DrawArrays::setCount(int count) {
    count = count;
}

void DrawArrays::draw() {
    auto mode  = getMode();
    auto insts = getInstances();
}

DrawElementsUInt::DrawElementsUInt() {
}

DrawElementsUInt::DrawElementsUInt(Mode mode)
  : DrawElementsUInt(mode, 1) {
}

DrawElementsUInt::DrawElementsUInt(Mode mode, int insts)
  : PrimitiveSet(mode, insts) {
}

void DrawElementsUInt::setIndices(std::vector<int> indices) {
    indices_ = std::move(indices);
}

std::vector<int>& DrawElementsUInt::getIndices() {
    return indices_;
}

void DrawElementsUInt::draw() {
    if (indices_.empty()) return;
    auto mode  = getMode();
    auto insts = getInstances();
}
} // namespace vkr