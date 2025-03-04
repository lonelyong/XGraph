#pragma once

#include <vkr/vkr_global.h>

namespace vkr {
struct VKR_API AppParameters {

};

class VKR_API Application {
  public:
    Application(const AppParameters& params);

  public:
    virtual bool initGlfw();

    virtual bool initQt();

    virtual bool isGlfwInitialized() const;

    virtual bool isQtInitialized() const;

  public:
    const AppParameters& getParameters() const { return params_; }

  private:
    AppParameters params_;
};
} // namespace vkr