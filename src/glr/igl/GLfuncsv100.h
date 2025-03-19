#pragma once

#include <glr/glr_global.h>

#include <glr/igl/GLdefs.h>
#include <glr/igl/GLfuncs.h>

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#    define APIENTRY __stdcall
#endif

#ifndef APIENTRY
#    define APIENTRY
#endif

#ifndef APIENTRYP
#    define APIENTRYP APIENTRY*
#endif

#ifndef GLAPIENTRY
#    define GLAPIENTRY APIENTRY
#endif


namespace glr {

class GLR_API GLfuncsv100 : public GLfuncs {
  public:
    using GLenum     = GLenum_t;
    using GLuint     = GLuint_t;
    using GLfloat    = GLfloat_t;
    using GLsizei    = GLsizei_t;
    using GLchar     = GLchar_t;
    using GLint      = GLint_t;
    using GLbitfield = GLbitfield_t;
    using GLdouble   = GLdouble_t;
    using GLboolean  = GLboolean_t;
    using GLubyte    = GLubyte_t;

    typedef void(APIENTRYP PFNGLCULLFACEPROC)(GLenum mode);
    PFNGLCULLFACEPROC glCullFace;

    typedef void(APIENTRYP PFNGLFRONTFACEPROC)(GLenum mode);
    PFNGLFRONTFACEPROC glFrontFace;

    typedef void(APIENTRYP PFNGLHINTPROC)(GLenum target, GLenum mode);
    PFNGLHINTPROC glHint;

    typedef void(APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat width);
    PFNGLLINEWIDTHPROC glLineWidth;

    typedef void(APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat size);
    PFNGLPOINTSIZEPROC glPointSize;

    typedef void(APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum face, GLenum mode);
    PFNGLPOLYGONMODEPROC glPolygonMode;

    typedef void(APIENTRYP PFNGLSCISSORPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
    PFNGLSCISSORPROC glScissor;

    typedef void(APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum target, GLenum pname, GLfloat param);
    PFNGLTEXPARAMETERFPROC glTexParameterf;

    typedef void(APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum target, GLenum pname, const GLfloat* params);
    PFNGLTEXPARAMETERFVPROC glTexParameterfv;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum target, GLenum pname, GLint param);
    PFNGLTEXPARAMETERIPROC glTexParameteri;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum target, GLenum pname, const GLint* params);
    PFNGLTEXPARAMETERIVPROC glTexParameteriv;

    typedef void(APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum      target,
                                                GLint       level,
                                                GLint       internalformat,
                                                GLsizei     width,
                                                GLint       border,
                                                GLenum      format,
                                                GLenum      type,
                                                const void* pixels);
    PFNGLTEXIMAGE1DPROC glTexImage1D;

    typedef void(APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum      target,
                                                GLint       level,
                                                GLint       internalformat,
                                                GLsizei     width,
                                                GLsizei     height,
                                                GLint       border,
                                                GLenum      format,
                                                GLenum      type,
                                                const void* pixels);
    PFNGLTEXIMAGE2DPROC glTexImage2D;

    typedef void(APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum buf);
    PFNGLDRAWBUFFERPROC glDrawBuffer;

    typedef void(APIENTRYP PFNGLCLEARPROC)(GLbitfield mask);
    PFNGLCLEARPROC glClear;

    typedef void(APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
    PFNGLCLEARCOLORPROC glClearColor;

    typedef void(APIENTRYP PFNGLCLEARSTENCILPROC)(GLint s);
    PFNGLCLEARSTENCILPROC glClearStencil;

    typedef void(APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble depth);
    PFNGLCLEARDEPTHPROC glClearDepth;

    typedef void(APIENTRYP PFNGLSTENCILMASKPROC)(GLuint mask);
    PFNGLSTENCILMASKPROC glStencilMask;

    typedef void(APIENTRYP PFNGLCOLORMASKPROC)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
    PFNGLCOLORMASKPROC glColorMask;

    typedef void(APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean flag);
    PFNGLDEPTHMASKPROC glDepthMask;

    typedef void(APIENTRYP PFNGLDISABLEPROC)(GLenum cap);
    PFNGLDISABLEPROC glDisable;

    typedef void(APIENTRYP PFNGLENABLEPROC)(GLenum cap);
    PFNGLENABLEPROC glEnable;

    typedef void(APIENTRYP PFNGLFINISHPROC)(void);
    PFNGLFINISHPROC glFinish;

    typedef void(APIENTRYP PFNGLFLUSHPROC)(void);
    PFNGLFLUSHPROC glFlush;

    typedef void(APIENTRYP PFNGLBLENDFUNCPROC)(GLenum sfactor, GLenum dfactor);
    PFNGLBLENDFUNCPROC glBlendFunc;

    typedef void(APIENTRYP PFNGLLOGICOPPROC)(GLenum opcode);
    PFNGLLOGICOPPROC glLogicOp;

    typedef void(APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum func, GLint ref, GLuint mask);
    PFNGLSTENCILFUNCPROC glStencilFunc;

    typedef void(APIENTRYP PFNGLSTENCILOPPROC)(GLenum fail, GLenum zfail, GLenum zpass);
    PFNGLSTENCILOPPROC glStencilOp;

    typedef void(APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum func);
    PFNGLDEPTHFUNCPROC glDepthFunc;

    typedef void(APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum pname, GLfloat param);
    PFNGLPIXELSTOREFPROC glPixelStoref;

    typedef void(APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum pname, GLint param);
    PFNGLPIXELSTOREIPROC glPixelStorei;

    typedef void(APIENTRYP PFNGLREADBUFFERPROC)(GLenum src);
    PFNGLREADBUFFERPROC glReadBuffer;

    typedef void(APIENTRYP PFNGLREADPIXELSPROC)(GLint   x,
                                                GLint   y,
                                                GLsizei width,
                                                GLsizei height,
                                                GLenum  format,
                                                GLenum  type,
                                                void*   pixels);
    PFNGLREADPIXELSPROC glReadPixels;

    typedef void(APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum pname, GLboolean* data);
    PFNGLGETBOOLEANVPROC glGetBooleanv;

    typedef void(APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum pname, GLdouble* data);
    PFNGLGETDOUBLEVPROC glGetDoublev;

    typedef GLenum(APIENTRYP PFNGLGETERRORPROC)(void);
    PFNGLGETERRORPROC glGetError;

    typedef void(APIENTRYP PFNGLGETFLOATVPROC)(GLenum pname, GLfloat* data);
    PFNGLGETFLOATVPROC glGetFloatv;

    typedef void(APIENTRYP PFNGLGETINTEGERVPROC)(GLenum pname, GLint* data);
    PFNGLGETINTEGERVPROC glGetIntegerv;

    typedef const GLubyte*(APIENTRYP PFNGLGETSTRINGPROC)(GLenum name);
    PFNGLGETSTRINGPROC glGetString;

    typedef void(APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum target, GLint level, GLenum format, GLenum type, void* pixels);
    PFNGLGETTEXIMAGEPROC glGetTexImage;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum target, GLenum pname, GLfloat* params);
    PFNGLGETTEXPARAMETERFVPROC glGetTexParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
    PFNGLGETTEXPARAMETERIVPROC glGetTexParameteriv;

    typedef void(APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum target, GLint level, GLenum pname, GLfloat* params);
    PFNGLGETTEXLEVELPARAMETERFVPROC glGetTexLevelParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum target, GLint level, GLenum pname, GLint* params);
    PFNGLGETTEXLEVELPARAMETERIVPROC glGetTexLevelParameteriv;

    typedef GLboolean(APIENTRYP PFNGLISENABLEDPROC)(GLenum cap);
    PFNGLISENABLEDPROC glIsEnabled;

    typedef void(APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble n, GLdouble f);
    PFNGLDEPTHRANGEPROC glDepthRange;

    typedef void(APIENTRYP PFNGLVIEWPORTPROC)(GLint x, GLint y, GLsizei width, GLsizei height);
    PFNGLVIEWPORTPROC glViewport;

  public:
    GLfuncsv100();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr