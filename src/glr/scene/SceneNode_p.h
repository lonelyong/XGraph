#pragma once

#include <glr/glrenderer_global.h>

#include <vector>

#include <glr/engine/StateSet.h>
#include <glr/scene/BoundingBox.h>

namespace glr {

class SceneNode;
class SceneNodePrivate {
    friend class SceneNode;

  private:
    std::vector<SceneNode*> parent_nodes;
    vine::RefPtr<StateSet>  state_set = nullptr;
    Mat4d                   matrix    = Mat4d(1.0);
    BoundingBox             bb;
    bool                    bound_is_dirty = true;

  public:
    void addParent(SceneNode* node);
    void removeParent(SceneNode* node);
};
} // namespace glr