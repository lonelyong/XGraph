#pragma once

#include <glr/glr_global.h>

#include <glr/scene/Group.h>

namespace glr {
class Model;
class GLR_API Scene : public Group {
    V_OBJECT_META_DECL

  public:
    Scene();
    virtual ~Scene();

  public:
    void addModel(Model* drawable);
    void removeModel(Model* drawable);

    int    getNbModels() const;
    Model* getModelAt(int index) const;

  private:
    struct Data; Data* const d;;
};
} // namespace glr