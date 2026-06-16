#pragma once

#include <xg/glr/igl/GLfuncsv130.h>

namespace xg {
namespace glr {
class GLR_API GLfuncsv140 : public GLfuncsv130 {

  public:
    typedef void(APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum_t sfactorRGB,
                                                       GLenum_t dfactorRGB,
                                                       GLenum_t sfactorAlpha,
                                                       GLenum_t dfactorAlpha);
    PFNGLBLENDFUNCSEPARATEPROC iglBlendFuncSeparate;

    typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum_t         mode,
                                                     const GLint_t*   first,
                                                     const GLsizei_t* count,
                                                     GLsizei_t        drawcount);
    PFNGLMULTIDRAWARRAYSPROC iglMultiDrawArrays;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum_t             mode,
                                                       const GLsizei_t*     count,
                                                       GLenum_t             type,
                                                       const void* const* indices,
                                                       GLsizei_t            drawcount);
    PFNGLMULTIDRAWELEMENTSPROC iglMultiDrawElements;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum_t pname, GLfloat_t param);
    PFNGLPOINTPARAMETERFPROC iglPointParameterf;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum_t pname, const GLfloat_t* params);
    PFNGLPOINTPARAMETERFVPROC iglPointParameterfv;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum_t pname, GLint_t param);
    PFNGLPOINTPARAMETERIPROC iglPointParameteri;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum_t pname, const GLint_t* params);
    PFNGLPOINTPARAMETERIVPROC iglPointParameteriv;

    typedef void(APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat_t red, GLfloat_t green, GLfloat_t blue, GLfloat_t alpha);
    PFNGLBLENDCOLORPROC iglBlendColor;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum_t mode);
    PFNGLBLENDEQUATIONPROC iglBlendEquation;

  public:
    GLfuncsv140();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
} // namespace xg