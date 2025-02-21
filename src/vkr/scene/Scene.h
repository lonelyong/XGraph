#pragma once

#include <vkr/vkrenderer_global.h>

#include <vkr/scene/Group.h>

namespace vkr {
class Model;
class VKR_API Scene : public Group {
    VI_OBJECT_META;

  public:
    Scene();
    virtual ~Scene();

  public:
    void addModel(Model* drawable);
    void removeModel(Model* drawable);

    int    getNbModels() const;
    Model* getModelAt(int index) const;

  private:
    VI_OBJECT_DATA;
};
} // namespace vkr