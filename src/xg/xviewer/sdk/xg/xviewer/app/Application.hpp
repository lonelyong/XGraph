#pragma once

#include <xg/xviewer/xviewer_global.hpp>

namespace xg {
namespace xviewer {
struct AppParameters {
    int    argc = 0;
    char** argv = nullptr;

    int  gl_ver_maj           = 3;
    int  gl_ver_min           = 3;
    bool gl_use_core_profile  = true;
    bool mesa_always_software = true;
};

class Application {
  public:
    Application(int argc, char** argv);
    virtual ~Application();

  public:
    const AppParameters& getParameters() const { return params_; }

  public:
    static Application* current();

  private:
    AppParameters params_;
};
} // namespace xviewer
} // namespace xg