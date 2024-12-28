#pragma once

#include <glr/glrenderer_global.h>

namespace glr {
struct GLR_API GLVersionInfo {
    int major;
    int minor;

    bool glslSupported;
    bool fboSupported;
    bool drawBuffersSupported;

    bool npotSupported;
};

GLR_API bool queryCurrentGLVersion(GLVersionInfo& vi);

GLR_API bool queryDefaultGLVersion(GLVersionInfo& vi);
} // namespace glr