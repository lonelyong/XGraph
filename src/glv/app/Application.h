#pragma once

#include <glv/glv_global.h>

namespace glv {
struct AppParameters {
    int  gl_ver_maj           = 3;
    int  gl_ver_min           = 3;
    bool gl_use_core_profile  = true;
    bool mesa_always_software = true;
};

class Application {
  public:
    Application(const AppParameters& params);
    virtual ~Application();

  public:
    const AppParameters& getParameters() const { return params_; }


  public:
    static Application* current();

  private:
    AppParameters params_;
};
} // namespace glv