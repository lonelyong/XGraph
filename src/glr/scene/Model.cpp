#include <glr/scene/Model.h>

#include <vector>
#include <vine/Exception.hpp>
#include <vine/Ptr.hpp>

#include <glr/engine/Callbacks.h>
#include <glr/engine/Event.h>
#include <glr/engine/StateSet.h>
#include <glr/scene/Drawable.h>

namespace glr {
V_OBJECT_META_IMPL(Model, Group);

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
    return vine::obj_cast<Drawable>(getChildAt(index));
}

} // namespace glr