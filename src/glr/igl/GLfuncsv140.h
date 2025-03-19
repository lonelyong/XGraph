#pragma once

#include <glr/igl/GLfuncsv130.h>

namespace glr {
class GLR_API GLfuncsv140 : public GLfuncsv130 {
  public:
    typedef void(APIENTRYP PFNGLBLENDFUNCSEPARATEPROC)(GLenum sfactorRGB,
                                                       GLenum dfactorRGB,
                                                       GLenum sfactorAlpha,
                                                       GLenum dfactorAlpha);
    PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;

    typedef void(APIENTRYP PFNGLMULTIDRAWARRAYSPROC)(GLenum         mode,
                                                     const GLint*   first,
                                                     const GLsizei* count,
                                                     GLsizei        drawcount);
    PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;

    typedef void(APIENTRYP PFNGLMULTIDRAWELEMENTSPROC)(GLenum             mode,
                                                       const GLsizei*     count,
                                                       GLenum             type,
                                                       const void* const* indices,
                                                       GLsizei            drawcount);
    PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERFPROC)(GLenum pname, GLfloat param);
    PFNGLPOINTPARAMETERFPROC glPointParameterf;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERFVPROC)(GLenum pname, const GLfloat* params);
    PFNGLPOINTPARAMETERFVPROC glPointParameterfv;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERIPROC)(GLenum pname, GLint param);
    PFNGLPOINTPARAMETERIPROC glPointParameteri;

    typedef void(APIENTRYP PFNGLPOINTPARAMETERIVPROC)(GLenum pname, const GLint* params);
    PFNGLPOINTPARAMETERIVPROC glPointParameteriv;

    typedef void(APIENTRYP PFNGLBLENDCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    PFNGLBLENDCOLORPROC glBlendColor;

    typedef void(APIENTRYP PFNGLBLENDEQUATIONPROC)(GLenum mode);
    PFNGLBLENDEQUATIONPROC glBlendEquation;

  public:
    GLfuncsv140();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr