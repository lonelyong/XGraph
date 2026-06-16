#include <xg/glr/scene/Scene.h>

#include <vector>

#include <xg/glr/scene/Model.h>

namespace xg {
namespace glr {
V_OBJECT_META_IMPL(Scene, Group);

struct Scene::Data {};

Scene::Scene()
  : d(new Data()) {
}

Scene::~Scene() {
    delete d;
}

void Scene::addModel(Model* model) {
    addChild(model);
}
void Scene::removeModel(Model* model) {
    removeChild(model);
}

int Scene::getNumModels() const {
    return getNumChildren();
}
Model* Scene::getModelAt(int index) const {
    return vine::obj_cast<Model>(getChildAt(index));
}

} // namespace glr
} // namespace xg