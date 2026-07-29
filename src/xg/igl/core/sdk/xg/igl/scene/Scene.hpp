#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/scene/Group.hpp>

namespace xg
{
namespace glr
{

class Model;

class IGL_CORE_API Scene : public Group {
    V_OBJECT_META_DECL

  public:
    Scene();
    virtual ~Scene();

  public:
    void addModel(Model* drawable);
    void removeModel(Model* drawable);

    int    getNumModels() const;
    Model* getModelAt(int index) const;

  private:
    struct Data;
    Data* const d;
    ;
};

} // namespace glr
} // namespace xg