#pragma once

namespace vkv {
struct AppInitializationParameters {};

class Application {
  public:
    Application(const AppInitializationParameters& params);

  public:
    const AppInitializationParameters& getInitializationParameters() const { return params_; }

  private:
    AppInitializationParameters params_;
};
} // namespace vkv