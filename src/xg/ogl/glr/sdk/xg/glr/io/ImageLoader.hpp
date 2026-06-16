#pragma once

#include <xg/glr/glr_global.h>

#include <string>
#include <vector>

namespace glr {

class Image;
class Model;
class GLR_API ImageLoader {

  public:
    ImageLoader();

  public:
    /**
     * @brief
     * @param file
     * @return Maybe return nullptr.
     */
    Image* loadFile(const std::string& file);

    void saveAsBmp(Image* img, const std::string& path);

    void setFlipVertically(bool val);

  public:
    static bool isSupported(const std::string& file);

  private:
    struct Data;
    Data* const d;
};
} // namespace glr