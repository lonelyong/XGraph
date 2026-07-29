#pragma once

#include <xg/igl/ogl/GLfuncsv140.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv150 : public GLfuncsv140 {

  public:
    using GLintptr   = GLintptr_t;
    using GLsizeiptr = GLsizeiptr_t;

  public:
    typedef void(APIENTRYP PFNGLGENQUERIESPROC)(GLsizei_t n, GLuint_t* ids);
    PFNGLGENQUERIESPROC oglGenQueries;

    typedef void(APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei_t n, const GLuint_t* ids);
    PFNGLDELETEQUERIESPROC oglDeleteQueries;

    typedef GLboolean_t(APIENTRYP PFNGLISQUERYPROC)(GLuint_t id);
    PFNGLISQUERYPROC oglIsQuery;

    typedef void(APIENTRYP PFNGLBEGINQUERYPROC)(GLenum_t target, GLuint_t id);
    PFNGLBEGINQUERYPROC oglBeginQuery;

    typedef void(APIENTRYP PFNGLENDQUERYPROC)(GLenum_t target);
    PFNGLENDQUERYPROC oglEndQuery;

    typedef void(APIENTRYP PFNGLGETQUERYIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETQUERYIVPROC oglGetQueryiv;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint_t id, GLenum_t pname, GLint_t* params);
    PFNGLGETQUERYOBJECTIVPROC oglGetQueryObjectiv;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint_t id, GLenum_t pname, GLuint_t* params);
    PFNGLGETQUERYOBJECTUIVPROC oglGetQueryObjectuiv;

    typedef void(APIENTRYP PFNGLBINDBUFFERPROC)(GLenum_t target, GLuint_t buffer);
    PFNGLBINDBUFFERPROC oglBindBuffer;

    typedef void(APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei_t n, const GLuint_t* buffers);
    PFNGLDELETEBUFFERSPROC oglDeleteBuffers;

    typedef void(APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei_t n, GLuint_t* buffers);
    PFNGLGENBUFFERSPROC oglGenBuffers;

    typedef GLboolean_t(APIENTRYP PFNGLISBUFFERPROC)(GLuint_t buffer);
    PFNGLISBUFFERPROC oglIsBuffer;

    typedef void(APIENTRYP PFNGLBUFFERDATAPROC)(GLenum_t target, GLsizeiptr size, const void* data, GLenum_t usage);
    PFNGLBUFFERDATAPROC oglBufferData;

    typedef void(APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum_t target, GLintptr offset, GLsizeiptr size, const void* data);
    PFNGLBUFFERSUBDATAPROC oglBufferSubData;

    typedef void(APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum_t target, GLintptr offset, GLsizeiptr size, void* data);
    PFNGLGETBUFFERSUBDATAPROC oglGetBufferSubData;

    typedef void*(APIENTRYP PFNGLMAPBUFFERPROC)(GLenum_t target, GLenum_t access);
    PFNGLMAPBUFFERPROC oglMapBuffer;

    typedef GLboolean_t(APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum_t target);
    PFNGLUNMAPBUFFERPROC oglUnmapBuffer;

    typedef void(APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETBUFFERPARAMETERIVPROC oglGetBufferParameteriv;

    typedef void(APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum_t target, GLenum_t pname, void** params);
    PFNGLGETBUFFERPOINTERVPROC oglGetBufferPointerv;

  public:
    GLfuncsv150();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg