#include <glr/scene/Model.h>

#include <vector>
#include <vine/core/Exception.h>
#include <vine/core/Ptr.h>

#include <glr/engine/Callbacks.h>
#include <glr/engine/Event.h>
#include <glr/engine/StateSet.h>
#include <glr/scene/Drawable.h>

namespace glr {
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

} // namespace glr