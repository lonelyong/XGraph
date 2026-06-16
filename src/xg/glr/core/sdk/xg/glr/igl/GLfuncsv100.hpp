#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/igl/GLdefs.hpp>


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


namespace xg {
namespace glr {

class GLR_API GLfuncsv100 {

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

  public:
    typedef void* (*Loader)(const char* fn);

  public:
    typedef void(APIENTRYP PFNGLCULLFACEPROC)(GLenum_t mode);
    PFNGLCULLFACEPROC iglCullFace;

    typedef void(APIENTRYP PFNGLFRONTFACEPROC)(GLenum_t mode);
    PFNGLFRONTFACEPROC iglFrontFace;

    typedef void(APIENTRYP PFNGLHINTPROC)(GLenum_t target, GLenum_t mode);
    PFNGLHINTPROC iglHint;

    typedef void(APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat_t width);
    PFNGLLINEWIDTHPROC iglLineWidth;

    typedef void(APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat_t size);
    PFNGLPOINTSIZEPROC iglPointSize;

    typedef void(APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum_t face, GLenum_t mode);
    PFNGLPOLYGONMODEPROC iglPolygonMode;

    typedef void(APIENTRYP PFNGLSCISSORPROC)(GLint_t x, GLint_t y, GLsizei_t width, GLsizei_t height);
    PFNGLSCISSORPROC iglScissor;

    typedef void(APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum_t target, GLenum_t pname, GLfloat_t param);
    PFNGLTEXPARAMETERFPROC iglTexParameterf;

    typedef void(APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum_t target, GLenum_t pname, const GLfloat_t* params);
    PFNGLTEXPARAMETERFVPROC iglTexParameterfv;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum_t target, GLenum_t pname, GLint_t param);
    PFNGLTEXPARAMETERIPROC iglTexParameteri;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, const GLint_t* params);
    PFNGLTEXPARAMETERIVPROC iglTexParameteriv;

    typedef void(APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum_t    target,
                                                GLint_t     level,
                                                GLint_t     internalformat,
                                                GLsizei_t   width,
                                                GLint_t     border,
                                                GLenum_t    format,
                                                GLenum_t    type,
                                                const void* pixels);
    PFNGLTEXIMAGE1DPROC iglTexImage1D;

    typedef void(APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum_t    target,
                                                GLint_t     level,
                                                GLint_t     internalformat,
                                                GLsizei_t   width,
                                                GLsizei_t   height,
                                                GLint_t     border,
                                                GLenum_t    format,
                                                GLenum_t    type,
                                                const void* pixels);
    PFNGLTEXIMAGE2DPROC iglTexImage2D;

    typedef void(APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum_t buf);
    PFNGLDRAWBUFFERPROC iglDrawBuffer;

    typedef void(APIENTRYP PFNGLCLEARPROC)(GLbitfield_t mask);
    PFNGLCLEARPROC iglClear;

    typedef void(APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat_t red, GLfloat_t green, GLfloat_t blue, GLfloat_t alpha);
    PFNGLCLEARCOLORPROC iglClearColor;

    typedef void(APIENTRYP PFNGLCLEARSTENCILPROC)(GLint_t s);
    PFNGLCLEARSTENCILPROC iglClearStencil;

    typedef void(APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble_t depth);
    PFNGLCLEARDEPTHPROC iglClearDepth;

    typedef void(APIENTRYP PFNGLSTENCILMASKPROC)(GLuint_t mask);
    PFNGLSTENCILMASKPROC iglStencilMask;

    typedef void(APIENTRYP PFNGLCOLORMASKPROC)(GLboolean_t red, GLboolean_t green, GLboolean_t blue, GLboolean_t alpha);
    PFNGLCOLORMASKPROC iglColorMask;

    typedef void(APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean_t flag);
    PFNGLDEPTHMASKPROC iglDepthMask;

    typedef void(APIENTRYP PFNGLDISABLEPROC)(GLenum_t cap);
    PFNGLDISABLEPROC iglDisable;

    typedef void(APIENTRYP PFNGLENABLEPROC)(GLenum_t cap);
    PFNGLENABLEPROC iglEnable;

    typedef void(APIENTRYP PFNGLFINISHPROC)(void);
    PFNGLFINISHPROC iglFinish;

    typedef void(APIENTRYP PFNGLFLUSHPROC)(void);
    PFNGLFLUSHPROC iglFlush;

    typedef void(APIENTRYP PFNGLBLENDFUNCPROC)(GLenum_t sfactor, GLenum_t dfactor);
    PFNGLBLENDFUNCPROC iglBlendFunc;

    typedef void(APIENTRYP PFNGLLOGICOPPROC)(GLenum_t opcode);
    PFNGLLOGICOPPROC iglLogicOp;

    typedef void(APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum_t func, GLint_t ref, GLuint_t mask);
    PFNGLSTENCILFUNCPROC iglStencilFunc;

    typedef void(APIENTRYP PFNGLSTENCILOPPROC)(GLenum_t fail, GLenum_t zfail, GLenum_t zpass);
    PFNGLSTENCILOPPROC iglStencilOp;

    typedef void(APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum_t func);
    PFNGLDEPTHFUNCPROC iglDepthFunc;

    typedef void(APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum_t pname, GLfloat_t param);
    PFNGLPIXELSTOREFPROC iglPixelStoref;

    typedef void(APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum_t pname, GLint_t param);
    PFNGLPIXELSTOREIPROC iglPixelStorei;

    typedef void(APIENTRYP PFNGLREADBUFFERPROC)(GLenum_t src);
    PFNGLREADBUFFERPROC iglReadBuffer;

    typedef void(APIENTRYP PFNGLREADPIXELSPROC)(GLint_t   x,
                                                GLint_t   y,
                                                GLsizei_t width,
                                                GLsizei_t height,
                                                GLenum_t  format,
                                                GLenum_t  type,
                                                void*     pixels);
    PFNGLREADPIXELSPROC iglReadPixels;

    typedef void(APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum_t pname, GLboolean_t* data);
    PFNGLGETBOOLEANVPROC iglGetBooleanv;

    typedef void(APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum_t pname, GLdouble_t* data);
    PFNGLGETDOUBLEVPROC iglGetDoublev;

    typedef GLenum_t(APIENTRYP PFNGLGETERRORPROC)(void);
    PFNGLGETERRORPROC iglGetError;

    typedef void(APIENTRYP PFNGLGETFLOATVPROC)(GLenum_t pname, GLfloat_t* data);
    PFNGLGETFLOATVPROC iglGetFloatv;

    typedef void(APIENTRYP PFNGLGETINTEGERVPROC)(GLenum_t pname, GLint_t* data);
    PFNGLGETINTEGERVPROC iglGetIntegerv;

    typedef const GLubyte*(APIENTRYP PFNGLGETSTRINGPROC)(GLenum_t name);
    PFNGLGETSTRINGPROC iglGetString;

    typedef void(
        APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum_t target, GLint_t level, GLenum_t format, GLenum_t type, void* pixels);
    PFNGLGETTEXIMAGEPROC iglGetTexImage;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum_t target, GLenum_t pname, GLfloat_t* params);
    PFNGLGETTEXPARAMETERFVPROC iglGetTexParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXPARAMETERIVPROC iglGetTexParameteriv;

    typedef void(APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum_t   target,
                                                            GLint_t    level,
                                                            GLenum_t   pname,
                                                            GLfloat_t* params);
    PFNGLGETTEXLEVELPARAMETERFVPROC iglGetTexLevelParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum_t target,
                                                            GLint_t  level,
                                                            GLenum_t pname,
                                                            GLint_t* params);
    PFNGLGETTEXLEVELPARAMETERIVPROC iglGetTexLevelParameteriv;

    typedef GLboolean_t(APIENTRYP PFNGLISENABLEDPROC)(GLenum_t cap);
    PFNGLISENABLEDPROC iglIsEnabled;

    typedef void(APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble_t n, GLdouble_t f);
    PFNGLDEPTHRANGEPROC iglDepthRange;

    typedef void(APIENTRYP PFNGLVIEWPORTPROC)(GLint_t x, GLint_t y, GLsizei_t width, GLsizei_t height);
    PFNGLVIEWPORTPROC iglViewport;

  public:
    GLfuncsv100();

  protected:
    virtual void loadFuncs(Loader loader);
};

} // namespace glr
} // namespace xg