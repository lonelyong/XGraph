#include <glr/scene/Scene.h>

#include <vector>

#include <glr/scene/Model.h>

namespace glr {
VI_OBJECT_META_IMPL(Scene, EventReceiver);

struct Scene::Data { 
};

Scene::Scene()
  : d(new Data()) {
}

Scene::~Scene() {
    delete d;
}

} // namespace glr