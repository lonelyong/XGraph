#include <vkr/scene/Scene.h>

#include <vector>

#include <vkr/scene/Model.h>

namespace vkr {
VI_OBJECT_META_IMPL(Scene, Group);

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

int Scene::getNbModels() const {
    return getNbChildren();
}
Model* Scene::getModelAt(int index) const {
    return getChildAt(index)->cast<Model>();
}

} // namespace vkr