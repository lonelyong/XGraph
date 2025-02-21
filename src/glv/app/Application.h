#pragma once

namespace glv {
struct AppInitializationParameters {
    int  gl_ver_maj          = 3;
    int  gl_ver_min          = 3;
    bool gl_use_core_profile = true;
};

class Application {
  public:
    Application(const AppInitializationParameters& params);
    virtual ~Application();

  public:
    const AppInitializationParameters& getInitializationParameters() const { return params_; }

  private:
    AppInitializationParameters params_;
};
} // namespace glv