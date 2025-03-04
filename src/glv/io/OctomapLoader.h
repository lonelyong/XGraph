#pragma once

#include <string>

namespace osg {
class MatrixTransform;
}

namespace glv {

class OctomapLoader {
  public:
    enum Option
    {
        RENDER_AS_POINT,
        RENDER_AS_BOX_DIRECTLY,
        RENDER_AS_BOX_USE_GEOMETRY_SHADER
    };

  public:
    OctomapLoader();

  public:
    void   setOption(Option option);
    Option getOption();

    osg::MatrixTransform* loadFile(const std::string& file);

  public:
    static bool isSupported(const std::string& file);

  private:
    Option option_;
};
} // namespace glv