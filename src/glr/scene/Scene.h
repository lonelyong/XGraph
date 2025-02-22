#pragma once

#include <glr/glr_global.h>

#include <glr/scene/Group.h>

namespace glr {
class Model;
class GLR_API Scene : public Group {
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
} // namespace glr