#pragma once

#include <string>

namespace osg {
class MatrixTransform;
}

namespace xg {
namespace xviewer {

class OctomapLoader {
  public:
    /**
     * @brief Render options for octree visualization.
     */
    enum RenderOption
    {
        RENDER_AS_POINT,                      ///< Render each occupied node as a point.
        RENDER_AS_BOX,                        ///< Render each occupied node as a cube.
        RENDER_AS_BOX_USE_GEOMETRY_SHADER     ///< Render cubes using geometry shader for better performance.
    };

  public:
    /**
     * @brief Constructs an OctomapLoader with the default render option
     *        (RENDER_AS_POINT).
     */
    OctomapLoader();

  public:
    /**
     * @brief Sets the render option for octree visualization.
     * @param option The render option to use (see RenderOption enum).
     */
    void setRenderOption(RenderOption option);

    /**
     * @brief Returns the current render option.
     * @return The current RenderOption value.
     */
    RenderOption getRenderOption() const;

    /**
     * @brief Loads an octomap file and returns the corresponding transform
     *        node in the scene graph.
     *
     * Supports octomap formats such as .bt (binary octomap) and .ot (octree).
     * Internally parses the octree structure and builds an OSG scene graph
     * attached under a MatrixTransform node, rendered according to the current
     * RenderOption.
     *
     * @param file Absolute path to the octomap file (UTF-8 encoded),
     *             e.g. "D:/maps/room.bt"
     * @return osg::MatrixTransform* A pointer to the transform node containing
     *         the octree scene on success.
     * @return nullptr load failed.
     */
    osg::MatrixTransform* loadFile(const std::string& file);

  public:
    /**
     * @brief Checks whether the given file path corresponds to a supported
     *        octomap format.
     *
     * The check is based solely on the file extension (case-insensitive) and
     * does not read the file contents. Supported extensions include .bt and .ot.
     *
     * @param file Absolute path to the file (UTF-8 encoded),
     *             e.g. "D:/maps/room.bt"
     * @return true  The file extension matches a supported octomap format.
     * @return false The file extension is not among the supported formats.
     */
    static bool isSupported(const std::string& file);

  private:
    RenderOption render_option_;  ///< Current rendering option for octree visualization.
};
} // namespace xviewer
} // namespace xg