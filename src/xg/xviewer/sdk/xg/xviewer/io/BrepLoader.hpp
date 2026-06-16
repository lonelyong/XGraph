#pragma once
#include <string>

namespace osg {
class MatrixTransform;
}

namespace xg {
namespace xviewer {

class BrepLoader {
  public:
    osg::MatrixTransform* loadFile(const std::string& path);

    static bool isSupported(const std::string& path);
};
} // namespace xviewer
} // namespace xg