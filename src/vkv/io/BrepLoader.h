#pragma once
#include <string>

namespace vsg {
class MatrixTransform;
}

namespace vkv {

class BrepLoader {
  public:
    vsg::MatrixTransform* loadFile(const std::string& path);

    static bool isSupported(const std::string& path);
};
} // namespace vkv