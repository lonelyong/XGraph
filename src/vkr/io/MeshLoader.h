#pragma once

#include <vkr/vkrenderer_global.h>

#include <string>
#include <vector>

namespace vkr {

class Model;
class VKR_API MeshLoader {
  public:
    Model* loadFile(const std::string& file);

    static bool isSupported(const std::string& file);
};
} // namespace vkr