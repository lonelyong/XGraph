#pragma once

#include <glr/glr_global.h>

#include <vine/core/Object.h>


#include <glr/igl/GLdefs.h>

namespace glr {

class GLR_API GLfuncs : public vine::Object {
    VI_OBJECT_META;

  public:
    typedef void* (*Loader)(const char* fn);

  public:
    const int major_version;
    const int minor_version;

  public:
    static GLfuncs* loadGLLoader(Loader loader);

    static GLfuncs* load();

  protected:
    virtual void loadFuncs(Loader loader) {}
};

} // namespace glr