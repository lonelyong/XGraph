#pragma once

#include <xg/igl/glr_global.hpp>

#include <xg/igl/ogl/GLdefs.hpp>


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


namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv100 {

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
    PFNGLCULLFACEPROC oglCullFace;

    typedef void(APIENTRYP PFNGLFRONTFACEPROC)(GLenum_t mode);
    PFNGLFRONTFACEPROC oglFrontFace;

    typedef void(APIENTRYP PFNGLHINTPROC)(GLenum_t target, GLenum_t mode);
    PFNGLHINTPROC oglHint;

    typedef void(APIENTRYP PFNGLLINEWIDTHPROC)(GLfloat_t width);
    PFNGLLINEWIDTHPROC oglLineWidth;

    typedef void(APIENTRYP PFNGLPOINTSIZEPROC)(GLfloat_t size);
    PFNGLPOINTSIZEPROC oglPointSize;

    typedef void(APIENTRYP PFNGLPOLYGONMODEPROC)(GLenum_t face, GLenum_t mode);
    PFNGLPOLYGONMODEPROC oglPolygonMode;

    typedef void(APIENTRYP PFNGLSCISSORPROC)(GLint_t x, GLint_t y, GLsizei_t width, GLsizei_t height);
    PFNGLSCISSORPROC oglScissor;

    typedef void(APIENTRYP PFNGLTEXPARAMETERFPROC)(GLenum_t target, GLenum_t pname, GLfloat_t param);
    PFNGLTEXPARAMETERFPROC oglTexParameterf;

    typedef void(APIENTRYP PFNGLTEXPARAMETERFVPROC)(GLenum_t target, GLenum_t pname, const GLfloat_t* params);
    PFNGLTEXPARAMETERFVPROC oglTexParameterfv;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIPROC)(GLenum_t target, GLenum_t pname, GLint_t param);
    PFNGLTEXPARAMETERIPROC oglTexParameteri;

    typedef void(APIENTRYP PFNGLTEXPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, const GLint_t* params);
    PFNGLTEXPARAMETERIVPROC oglTexParameteriv;

    typedef void(APIENTRYP PFNGLTEXIMAGE1DPROC)(GLenum_t    target,
                                                GLint_t     level,
                                                GLint_t     internalformat,
                                                GLsizei_t   width,
                                                GLint_t     border,
                                                GLenum_t    format,
                                                GLenum_t    type,
                                                const void* pixels);
    PFNGLTEXIMAGE1DPROC oglTexImage1D;

    typedef void(APIENTRYP PFNGLTEXIMAGE2DPROC)(GLenum_t    target,
                                                GLint_t     level,
                                                GLint_t     internalformat,
                                                GLsizei_t   width,
                                                GLsizei_t   height,
                                                GLint_t     border,
                                                GLenum_t    format,
                                                GLenum_t    type,
                                                const void* pixels);
    PFNGLTEXIMAGE2DPROC oglTexImage2D;

    typedef void(APIENTRYP PFNGLDRAWBUFFERPROC)(GLenum_t buf);
    PFNGLDRAWBUFFERPROC oglDrawBuffer;

    typedef void(APIENTRYP PFNGLCLEARPROC)(GLbitfield_t mask);
    PFNGLCLEARPROC oglClear;

    typedef void(APIENTRYP PFNGLCLEARCOLORPROC)(GLfloat_t red, GLfloat_t green, GLfloat_t blue, GLfloat_t alpha);
    PFNGLCLEARCOLORPROC oglClearColor;

    typedef void(APIENTRYP PFNGLCLEARSTENCILPROC)(GLint_t s);
    PFNGLCLEARSTENCILPROC oglClearStencil;

    typedef void(APIENTRYP PFNGLCLEARDEPTHPROC)(GLdouble_t depth);
    PFNGLCLEARDEPTHPROC oglClearDepth;

    typedef void(APIENTRYP PFNGLSTENCILMASKPROC)(GLuint_t mask);
    PFNGLSTENCILMASKPROC oglStencilMask;

    typedef void(APIENTRYP PFNGLCOLORMASKPROC)(GLboolean_t red, GLboolean_t green, GLboolean_t blue, GLboolean_t alpha);
    PFNGLCOLORMASKPROC oglColorMask;

    typedef void(APIENTRYP PFNGLDEPTHMASKPROC)(GLboolean_t flag);
    PFNGLDEPTHMASKPROC oglDepthMask;

    typedef void(APIENTRYP PFNGLDISABLEPROC)(GLenum_t cap);
    PFNGLDISABLEPROC oglDisable;

    typedef void(APIENTRYP PFNGLENABLEPROC)(GLenum_t cap);
    PFNGLENABLEPROC oglEnable;

    typedef void(APIENTRYP PFNGLFINISHPROC)(void);
    PFNGLFINISHPROC oglFinish;

    typedef void(APIENTRYP PFNGLFLUSHPROC)(void);
    PFNGLFLUSHPROC oglFlush;

    typedef void(APIENTRYP PFNGLBLENDFUNCPROC)(GLenum_t sfactor, GLenum_t dfactor);
    PFNGLBLENDFUNCPROC oglBlendFunc;

    typedef void(APIENTRYP PFNGLLOGICOPPROC)(GLenum_t opcode);
    PFNGLLOGICOPPROC oglLogicOp;

    typedef void(APIENTRYP PFNGLSTENCILFUNCPROC)(GLenum_t func, GLint_t ref, GLuint_t mask);
    PFNGLSTENCILFUNCPROC oglStencilFunc;

    typedef void(APIENTRYP PFNGLSTENCILOPPROC)(GLenum_t fail, GLenum_t zfail, GLenum_t zpass);
    PFNGLSTENCILOPPROC oglStencilOp;

    typedef void(APIENTRYP PFNGLDEPTHFUNCPROC)(GLenum_t func);
    PFNGLDEPTHFUNCPROC oglDepthFunc;

    typedef void(APIENTRYP PFNGLPIXELSTOREFPROC)(GLenum_t pname, GLfloat_t param);
    PFNGLPIXELSTOREFPROC oglPixelStoref;

    typedef void(APIENTRYP PFNGLPIXELSTOREIPROC)(GLenum_t pname, GLint_t param);
    PFNGLPIXELSTOREIPROC oglPixelStorei;

    typedef void(APIENTRYP PFNGLREADBUFFERPROC)(GLenum_t src);
    PFNGLREADBUFFERPROC oglReadBuffer;

    typedef void(APIENTRYP PFNGLREADPIXELSPROC)(GLint_t x, GLint_t y, GLsizei_t width, GLsizei_t height, GLenum_t format, GLenum_t type, void* pixels);
    PFNGLREADPIXELSPROC oglReadPixels;

    typedef void(APIENTRYP PFNGLGETBOOLEANVPROC)(GLenum_t pname, GLboolean_t* data);
    PFNGLGETBOOLEANVPROC oglGetBooleanv;

    typedef void(APIENTRYP PFNGLGETDOUBLEVPROC)(GLenum_t pname, GLdouble_t* data);
    PFNGLGETDOUBLEVPROC oglGetDoublev;

    typedef GLenum_t(APIENTRYP PFNGLGETERRORPROC)(void);
    PFNGLGETERRORPROC oglGetError;

    typedef void(APIENTRYP PFNGLGETFLOATVPROC)(GLenum_t pname, GLfloat_t* data);
    PFNGLGETFLOATVPROC oglGetFloatv;

    typedef void(APIENTRYP PFNGLGETINTEGERVPROC)(GLenum_t pname, GLint_t* data);
    PFNGLGETINTEGERVPROC oglGetIntegerv;

    typedef const GLubyte*(APIENTRYP PFNGLGETSTRINGPROC)(GLenum_t name);
    PFNGLGETSTRINGPROC oglGetString;

    typedef void(APIENTRYP PFNGLGETTEXIMAGEPROC)(GLenum_t target, GLint_t level, GLenum_t format, GLenum_t type, void* pixels);
    PFNGLGETTEXIMAGEPROC oglGetTexImage;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERFVPROC)(GLenum_t target, GLenum_t pname, GLfloat_t* params);
    PFNGLGETTEXPARAMETERFVPROC oglGetTexParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXPARAMETERIVPROC oglGetTexParameteriv;

    typedef void(APIENTRYP PFNGLGETTEXLEVELPARAMETERFVPROC)(GLenum_t target, GLint_t level, GLenum_t pname, GLfloat_t* params);
    PFNGLGETTEXLEVELPARAMETERFVPROC oglGetTexLevelParameterfv;

    typedef void(APIENTRYP PFNGLGETTEXLEVELPARAMETERIVPROC)(GLenum_t target, GLint_t level, GLenum_t pname, GLint_t* params);
    PFNGLGETTEXLEVELPARAMETERIVPROC oglGetTexLevelParameteriv;

    typedef GLboolean_t(APIENTRYP PFNGLISENABLEDPROC)(GLenum_t cap);
    PFNGLISENABLEDPROC oglIsEnabled;

    typedef void(APIENTRYP PFNGLDEPTHRANGEPROC)(GLdouble_t n, GLdouble_t f);
    PFNGLDEPTHRANGEPROC oglDepthRange;

    typedef void(APIENTRYP PFNGLVIEWPORTPROC)(GLint_t x, GLint_t y, GLsizei_t width, GLsizei_t height);
    PFNGLVIEWPORTPROC oglViewport;

  public:
    GLfuncsv100();

  protected:
    virtual void loadFuncs(Loader loader);
};

} // namespace glr
} // namespace xg