#pragma once

#include <xg/igl/ogl/GLfuncsv200.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv210 : public GLfuncsv200 {

  public:
    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X3FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX2X3FVPROC oglUniformMatrix2x3fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X2FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX3X2FVPROC oglUniformMatrix3x2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX2X4FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX2X4FVPROC oglUniformMatrix2x4fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X2FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX4X2FVPROC oglUniformMatrix4x2fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX3X4FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX3X4FVPROC oglUniformMatrix3x4fv;

    typedef void(APIENTRYP PFNGLUNIFORMMATRIX4X3FVPROC)(GLint_t location, GLsizei_t count, GLboolean_t transpose, const GLfloat_t* value);
    PFNGLUNIFORMMATRIX4X3FVPROC oglUniformMatrix4x3fv;

  public:
    GLfuncsv210();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg