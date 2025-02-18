#include <glr/scene/Scene.h>

#include <vector>

#include <glr/scene/Model.h>

namespace glr {
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

} // namespace glr