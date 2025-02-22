#pragma once

#include <vkr/vkr_global.h>

namespace vkr {
struct VKR_API AppInitializationParameters {

};

class VKR_API Application {
  public:
    Application(const AppInitializationParameters& params);

  public:
    virtual bool initGlfw();

    virtual bool initQt();

    virtual bool isGlfwInitialized() const;

    virtual bool isQtInitialized() const;

  public:
    const AppInitializationParameters& getInitializationParameters() const { return params_; }

  private:
    AppInitializationParameters params_;
};
} // namespace vkr