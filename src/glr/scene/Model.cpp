#include <glr/scene/Model.h>

#include <vector>
#include <vine/core/Ptr.h>
#include <vine/core/Exception.h>

#include <glr/engine/Callbacks.h>
#include <glr/scene/Drawable.h>
#include <glr/engine/Event.h>
#include <glr/engine/StateSet.h>

namespace glr {
VI_OBJECT_META_IMPL(Model, SceneNodeGroup);

struct Model::Data {

};

Model::Model()
  : d(new Data()) {
}

Model::~Model() {
    delete d;
}

void Model::addChild(SceneNode* node){
    if(!node)
    {
        return;
    }

    if(node->isKindOf(Drawable::desc())){
        SceneNodeGroup::addChild(node);
    }
    else{
        throw vine::Exception(vine::Exception::INVALID_OPERATION, U"Only drawable types are allowed to be added.");
    }
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