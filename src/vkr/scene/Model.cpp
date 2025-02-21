#include <vkr/scene/Model.h>

#include <vector>
#include <vine/core/Exception.h>
#include <vine/core/Ptr.h>

#include <vkr/engine/Callbacks.h>
#include <vkr/engine/Event.h>
#include <vkr/engine/StateSet.h>
#include <vkr/scene/Drawable.h>

namespace vkr {
VI_OBJECT_META_IMPL(Model, Group);

struct Model::Data {};

Model::Model()
  : d(new Data()) {
}

Model::~Model() {
    delete d;
}

void Model::addDrawable(Drawable* drawable) {
    addChild(drawable);
}

void Model::removeDrawable(Drawable* drawable) {
    removeChild(drawable);
}

int Model::getNbDrawables() const {
    return getNbChildren();
}

Drawable* Model::getDrawableAt(int index) const {
    return getChildAt(index)->cast<Drawable>();
}

} // namespace vkr