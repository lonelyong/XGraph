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

class BrepLoader {
  public:
    /**
     * @brief Loads a boundary representation (B-rep) model file and returns the
     *        corresponding transform node in the scene graph.
     *
     * Supports STEP (.stp / .step) and IGES (.igs / .iges) CAD model formats.
     * Internally parses the geometry and topology data, builds an OSG scene graph,
     * and attaches it under a MatrixTransform node so callers can easily apply
     * translation, rotation, scaling and other transformations.
     *
     * @param path Absolute path to the model file (UTF-8 encoded),
     *             e.g. "D:/models/part.step"
     * @return osg::MatrixTransform* A pointer to the transform node containing
     *         the model scene on success.
     * @return nullptr load failed.
     */
    osg::MatrixTransform* loadFile(const std::string& path);

    /**
     * @brief Checks whether the given file path corresponds to a supported
     *        B-rep model format.
     *
     * The check is based solely on the file extension (case-insensitive) and
     * does not read the file contents. Currently supported formats include
     * STEP (.stp / .step) and IGES (.igs / .iges).
     *
     * @param path Absolute path to the file (UTF-8 encoded),
     *             e.g. "D:/models/part.stp"
     * @return true  The file extension is .stp, .step, .igs or .iges
     *               (case-insensitive)
     * @return false The file extension is not among the supported formats
     */
    static bool isSupported(const std::string& path);
};

} // namespace xviewer
} // namespace xg