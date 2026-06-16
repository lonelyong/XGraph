#pragma once

#include <xg/glr/igl/GLfuncsv140.h>

namespace xg {
namespace glr {
class GLR_API GLfuncsv150 : public GLfuncsv140 {

  public:
    using GLintptr   = GLintptr_t;
    using GLsizeiptr = GLsizeiptr_t;

  public:
    typedef void(APIENTRYP PFNGLGENQUERIESPROC)(GLsizei_t n, GLuint_t* ids);
    PFNGLGENQUERIESPROC iglGenQueries;

    typedef void(APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei_t n, const GLuint_t* ids);
    PFNGLDELETEQUERIESPROC iglDeleteQueries;

    typedef GLboolean_t(APIENTRYP PFNGLISQUERYPROC)(GLuint_t id);
    PFNGLISQUERYPROC iglIsQuery;

    typedef void(APIENTRYP PFNGLBEGINQUERYPROC)(GLenum_t target, GLuint_t id);
    PFNGLBEGINQUERYPROC iglBeginQuery;

    typedef void(APIENTRYP PFNGLENDQUERYPROC)(GLenum_t target);
    PFNGLENDQUERYPROC iglEndQuery;

    typedef void(APIENTRYP PFNGLGETQUERYIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETQUERYIVPROC iglGetQueryiv;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint_t id, GLenum_t pname, GLint_t* params);
    PFNGLGETQUERYOBJECTIVPROC iglGetQueryObjectiv;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint_t id, GLenum_t pname, GLuint_t* params);
    PFNGLGETQUERYOBJECTUIVPROC iglGetQueryObjectuiv;

    typedef void(APIENTRYP PFNGLBINDBUFFERPROC)(GLenum_t target, GLuint_t buffer);
    PFNGLBINDBUFFERPROC iglBindBuffer;

    typedef void(APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei_t n, const GLuint_t* buffers);
    PFNGLDELETEBUFFERSPROC iglDeleteBuffers;

    typedef void(APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei_t n, GLuint_t* buffers);
    PFNGLGENBUFFERSPROC iglGenBuffers;

    typedef GLboolean_t(APIENTRYP PFNGLISBUFFERPROC)(GLuint_t buffer);
    PFNGLISBUFFERPROC iglIsBuffer;

    typedef void(APIENTRYP PFNGLBUFFERDATAPROC)(GLenum_t target, GLsizeiptr size, const void* data, GLenum_t usage);
    PFNGLBUFFERDATAPROC iglBufferData;

    typedef void(APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum_t target, GLintptr offset, GLsizeiptr size, const void* data);
    PFNGLBUFFERSUBDATAPROC iglBufferSubData;

    typedef void(APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum_t target, GLintptr offset, GLsizeiptr size, void* data);
    PFNGLGETBUFFERSUBDATAPROC iglGetBufferSubData;

    typedef void*(APIENTRYP PFNGLMAPBUFFERPROC)(GLenum_t target, GLenum_t access);
    PFNGLMAPBUFFERPROC iglMapBuffer;

    typedef GLboolean_t(APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum_t target);
    PFNGLUNMAPBUFFERPROC iglUnmapBuffer;

    typedef void(APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum_t target, GLenum_t pname, GLint_t* params);
    PFNGLGETBUFFERPARAMETERIVPROC iglGetBufferParameteriv;

    typedef void(APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum_t target, GLenum_t pname, void** params);
    PFNGLGETBUFFERPOINTERVPROC iglGetBufferPointerv;

  public:
    GLfuncsv150();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr
} // namespace xg