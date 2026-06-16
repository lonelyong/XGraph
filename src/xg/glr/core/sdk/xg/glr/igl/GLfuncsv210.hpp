#pragma once

#include <xg/glr/igl/GLfuncsv200.h>

namespace xg {
namespace glr {
class GLR_API GLfuncsv210 : public GLfuncsv200 {

  public:
    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint_t          location,
                                                        GLsizei_t        count,
                                                        GLboolean_t      transpose,
                                                        const GLfloat_t* value);
    PFNGLUNIFORMMATRIX2X3FVPROC iglUniformMatrix2x3fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint_t          location,
                                                        GLsizei_t        count,
                                                        GLboolean_t      transpose,
                                                        const GLfloat_t* value);
    PFNGLUNIFORMMATRIX3X2FVPROC iglUniformMatrix3x2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint_t          location,
                                                        GLsizei_t        count,
                                                        GLboolean_t      transpose,
                                                        const GLfloat_t* value);
    PFNGLUNIFORMMATRIX2X4FVPROC iglUniformMatrix2x4fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint_t          location,
                                                        GLsizei_t        count,
                                                        GLboolean_t      transpose,
                                                        const GLfloat_t* value);
    PFNGLUNIFORMMATRIX4X2FVPROC iglUniformMatrix4x2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint_t          location,
                                                        GLsizei_t        count,
                                                        GLboolean_t      transpose,
                                                        const GLfloat_t* value);
    PFNGLUNIFORMMATRIX3X4FVPROC iglUniformMatrix3x4fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint_t          location,
                                                        GLsizei_t        count,
                                                        GLboolean_t      transpose,
                                                        const GLfloat_t* value);
    PFNGLUNIFORMMATRIX4X3FVPROC iglUniformMatrix4x3fv;

  public:
    GLfuncsv210();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
} // namespace xg