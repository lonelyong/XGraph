#pragma once

#include <glr/glrenderer_global.h>

#include <string>
#include <vector>

namespace glr {

class Model;
class GLR_API MeshLoader {
  public:
    Model* loadFile(const std::string& file);

    static bool isSupported(const std::string& file);
};
} // namespace glr