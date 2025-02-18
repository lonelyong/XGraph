#pragma once

#include <glr/glrenderer_global.h>

namespace glr {
struct GLR_API AppInitializationParameters {
    int  gl_ver_maj          = 4;
    int  gl_ver_min          = 1;
    bool gl_use_core_profile = true;
};

class GLR_API AppInitializer {
  public:
    AppInitializer(const AppInitializationParameters& params);

  public:
    virtual bool initGlfw();

    virtual bool initGlad();

    virtual bool initQt();

    virtual bool isGlfwInitialized() const;

    virtual bool isGladInitialized() const;

    virtual bool isQtInitialized() const;

  private:
    AppInitializationParameters params_;
};
} // namespace glr