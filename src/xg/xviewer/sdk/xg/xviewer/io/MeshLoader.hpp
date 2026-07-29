#pragma once

#include <string>

namespace osg
{

class MatrixTransform;

}

namespace xg
{
namespace xviewer
{

class MeshLoader {
  public:
    /**
     * @brief Loads a mesh model file and returns the corresponding transform
     *        node in the scene graph.
     *
     * Supports common mesh formats such as OBJ (.obj), PLY (.ply), STL (.stl),
     * and others. Internally parses the geometry data (vertices, normals,
     * texture coordinates, faces) and builds an OSG scene graph attached under
     * a MatrixTransform node.
     *
     * @param file Absolute path to the mesh file (UTF-8 encoded),
     *             e.g. "D:/models/car.obj"
     * @return osg::MatrixTransform* A pointer to the transform node containing
     *         the mesh scene on success.
     * @return nullptr load failed.
     */
    osg::MatrixTransform* loadFile(const std::string& file);

    /**
     * @brief Checks whether the given file path corresponds to a supported
     *        mesh format.
     *
     * The check is based solely on the file extension (case-insensitive) and
     * does not read the file contents. Supported extensions include .obj, .ply,
     * .stl, and other common mesh formats.
     *
     * @param file Absolute path to the file (UTF-8 encoded),
     *             e.g. "D:/models/car.obj"
     * @return true  The file extension matches a supported mesh format.
     * @return false The file extension is not among the supported formats.
     */
    static bool isSupported(const std::string& file);
};

} // namespace xviewer
} // namespace xg