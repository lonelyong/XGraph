#pragma once

namespace vkv {
struct AppParameters {};

class Application {
  public:
    Application(const AppParameters& params);

  public:
    const AppParameters& getParameters() const { return params_; }

  private:
    AppParameters params_;
};
} // namespace vkv