#pragma once

#include <glr/glr_global.h>

namespace glr {
class GLR_API Capabilities {
  public:
    int MAJOR_VERSION;
    int MINOR_VERSION;


};

bool GLR_API queryCapabilities(Capabilities& caps);
} // namespace glr