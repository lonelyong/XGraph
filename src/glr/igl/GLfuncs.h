#pragma once

#include <glr/glr_global.h>

#include <glr/igl/GLdefs.h>
#include <glr/igl/GLfuncsArb.h>
#include <glr/igl/GLfuncsv460.h>

namespace glr {

class GLR_API GLfuncs : public GLfuncsv460, public GLfuncsArb {

  public:
    GLfuncs();
    virtual ~GLfuncs();

  public:
    enum Extension
    {
        GL_ARB_ES2_COMPATIBILITY,
        GL_ARB_ES3_COMPATIBILITY,
        GL_ARB_ES3_1_COMPATIBILITY,
        GL_ARB_ES3_2_COMPATIBILITY,

        GL_ARB_ARRAYS_OF_ARRAYS,
        GL_ARB_BINDLESS_TEXTURE,
        GL_ARB_CL_EVENT,

        /**
         * 稀疏纹理
         */
        GL_ARB_SPARSE_TEXTURE,
        GL_ARB_SPARSE_BUFFER,
        GL_ARB_SHADING_LANGUAGE_INCLUDE,
        GL_ARB_SAMPLE_SHADING,
        GL_ARB_SAMPLE_LOCATIONS,
        GL_ARB_ROBUSTNESS,
        GL_ARB_PARALLEL_SHADER_COMPILE
    };

    typedef void* (*Loader)(const char* fn);

  public:
    const GLint_t major_version;
    const GLint_t minor_version;

  public:
    bool hasExtension(Extension ext) const;

    bool hasExtension(const char* ext) const;

  public:
    static GLfuncs* loadGLLoader(Loader loader);

    static GLfuncs* load();

  private:
    struct Data;
    Data* const d;
};

} // namespace glr