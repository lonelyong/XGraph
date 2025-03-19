#pragma once

#include <glr/igl/GLfuncsv200.h>

namespace glr {
class GLR_API GLfuncsv210 : public GLfuncsv200 {
    VI_OBJECT_META;

  public:
    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint          location,
                                                        GLsizei        count,
                                                        GLboolean      transpose,
                                                        const GLfloat* value);
    PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint          location,
                                                        GLsizei        count,
                                                        GLboolean      transpose,
                                                        const GLfloat* value);
    PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint          location,
                                                        GLsizei        count,
                                                        GLboolean      transpose,
                                                        const GLfloat* value);
    PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint          location,
                                                        GLsizei        count,
                                                        GLboolean      transpose,
                                                        const GLfloat* value);
    PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint          location,
                                                        GLsizei        count,
                                                        GLboolean      transpose,
                                                        const GLfloat* value);
    PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint          location,
                                                        GLsizei        count,
                                                        GLboolean      transpose,
                                                        const GLfloat* value);
    PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

  public:
    GLfuncsv210();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr