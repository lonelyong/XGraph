#pragma once

#include <xg/glr/glr_global.h>

#include <string>
#include <vector>

namespace xg {
namespace glr {

class Model;
class GLR_API MeshLoader {
  public:
    Model* loadFile(const std::string& file);

    static bool isSupported(const std::string& file);
};
} // namespace glr
} // namespace xg