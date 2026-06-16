#pragma once

#include <string>

namespace osg {
class MatrixTransform;
}

namespace glv {

class OctomapLoader {
  public:
    enum RenderOption
    {
        RENDER_AS_POINT,
        RENDER_AS_BOX,
        RENDER_AS_BOX_USE_GEOMETRY_SHADER
    };

  public:
    OctomapLoader();

  public:
    void         setRenderOption(RenderOption option);
    RenderOption getRenderOption();

    osg::MatrixTransform* loadFile(const std::string& file);

  public:
    static bool isSupported(const std::string& file);

  private:
    RenderOption render_option_;
};
} // namespace glv