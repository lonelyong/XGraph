#pragma once

#include <xg/igl/glr_global.hpp>

#include <string>
#include <vector>

namespace xg
{
namespace glr
{

class Model;

class IGL_CORE_API MeshLoader {
  public:
    Model* loadFile(const std::string& file);

    static bool isSupported(const std::string& file);
};

} // namespace glr
} // namespace xg