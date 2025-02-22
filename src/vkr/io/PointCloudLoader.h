#pragma once

#include <vkr/vkr_global.h>

#include <string>

namespace vkr {
class Model;
class VKR_API PointCloudLoader {
  public:
    Model* load(const std::string& file);

    static bool isSupported(const std::string& file);
};
} // namespace vkr