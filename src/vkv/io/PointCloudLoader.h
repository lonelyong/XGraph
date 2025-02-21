#pragma once 
#include <string>

namespace vsg {
class MatrixTransform;
}
namespace vkv {
class PointCloudLoader {
  public:
    vsg::MatrixTransform* loadFile(const std::string& file);

    static bool isSupported(const std::string& file);
};
} // namespace vkv