#pragma once

#include <glr/glr_global.h>

#include <vine/core/Object.h>


#include <glr/igl/GLdefs.h>

namespace glr {

class GLR_API GLfuncs : public vine::Object {
    VI_OBJECT_META;

  public:
    typedef GLubyte_t* (*Loader)(const char* fn);

  public:
    static GLfuncs* load(Loader loader);

  protected:
    virtual void loadFuncs(Loader loader) {}
};

} // namespace glr