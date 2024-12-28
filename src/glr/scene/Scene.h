#pragma once

#include <glr/glrenderer_global.h>

#include <glr/scene/SceneNodeGroup.h>

namespace glr {
class Model;
class GLR_API Scene : public SceneNodeGroup {
    VI_OBJECT_META;

  public:
    Scene();
    virtual ~Scene();

  public:
  private:
    VI_OBJECT_DATA;
};
} // namespace glr