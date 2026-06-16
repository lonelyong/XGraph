#include <xg/glr/scene/Model.h>

#include <vector>
#include <vine/Exception.hpp>
#include <vine/Ptr.hpp>

#include <xg/glr/engine/Callbacks.h>
#include <xg/glr/engine/Event.h>
#include <xg/glr/engine/StateSet.h>
#include <xg/glr/scene/Drawable.h>

namespace xg {
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

int Model::getNumDrawables() const {
    return getNumChildren();
}

Drawable* Model::getDrawableAt(int index) const {
    return vine::obj_cast<Drawable>(getChildAt(index));
}

} // namespace glr
} // namespace xg