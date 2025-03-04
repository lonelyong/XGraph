#pragma once

#include <glr/glr_global.h>

namespace glr {
struct GLR_API AppParameters {
    int  gl_ver_maj           = 4;
    int  gl_ver_min           = 2;
    bool gl_use_core_profile  = true;
    bool mesa_always_software = true;
};

class GLR_API Application {
  public:
    Application(const AppParameters& params);

  public:
    virtual bool initGlfw();

    virtual bool initGlad();

    virtual bool initQt();

    virtual bool isGlfwInitialized() const;

    virtual bool isGladInitialized() const;

    virtual bool isQtInitialized() const;

  public:
    const AppParameters& getParameters() const { return params_; }

  public:
    static Application* current();

  private:
    AppParameters params_;
};
} // namespace glr