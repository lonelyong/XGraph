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

class PointCloudLoader {
  public:
    /**
     * @brief Loads a point cloud file and returns the corresponding transform
     *        node in the scene graph.
     *
     * Supports common point cloud formats such as PLY (.ply), PCD (.pcd),
     * XYZ (.xyz), LAS (.las) and others. Internally parses the point data
     * (positions, colors, normals) and builds an OSG scene graph attached
     * under a MatrixTransform node.
     *
     * @param file Absolute path to the point cloud file (UTF-8 encoded),
     *             e.g. "D:/scans/room.ply"
     * @return osg::MatrixTransform* A pointer to the transform node containing
     *         the point cloud scene on success.
     * @return nullptr load failed.
     */
    osg::MatrixTransform* loadFile(const std::string& file);

    /**
     * @brief Checks whether the given file path corresponds to a supported
     *        point cloud format.
     *
     * The check is based solely on the file extension (case-insensitive) and
     * does not read the file contents. Supported extensions include .ply, .pcd,
     * .xyz, .las and other common point cloud formats.
     *
     * @param file Absolute path to the file (UTF-8 encoded),
     *             e.g. "D:/scans/room.ply"
     * @return true  The file extension matches a supported point cloud format.
     * @return false The file extension is not among the supported formats.
     */
    static bool isSupported(const std::string& file);
};

} // namespace xviewer
} // namespace xg