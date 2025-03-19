#pragma once

#include <glr/igl/GLfuncsv140.h>

namespace glr {
class GLR_API GLfuncsv150 : public GLfuncsv140 {
    VI_OBJECT_META;

  public:
    using GLintptr   = GLintptr_t;
    using GLsizeiptr = GLsizeiptr_t;

  public:
    typedef void(APIENTRYP PFNGLGENQUERIESPROC)(GLsizei n, GLuint* ids);
    PFNGLGENQUERIESPROC glGenQueries;

    typedef void(APIENTRYP PFNGLDELETEQUERIESPROC)(GLsizei n, const GLuint* ids);
    PFNGLDELETEQUERIESPROC glDeleteQueries;

    typedef GLboolean(APIENTRYP PFNGLISQUERYPROC)(GLuint id);
    PFNGLISQUERYPROC glIsQuery;

    typedef void(APIENTRYP PFNGLBEGINQUERYPROC)(GLenum target, GLuint id);
    PFNGLBEGINQUERYPROC glBeginQuery;

    typedef void(APIENTRYP PFNGLENDQUERYPROC)(GLenum target);
    PFNGLENDQUERYPROC glEndQuery;

    typedef void(APIENTRYP PFNGLGETQUERYIVPROC)(GLenum target, GLenum pname, GLint* params);
    PFNGLGETQUERYIVPROC glGetQueryiv;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTIVPROC)(GLuint id, GLenum pname, GLint* params);
    PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;

    typedef void(APIENTRYP PFNGLGETQUERYOBJECTUIVPROC)(GLuint id, GLenum pname, GLuint* params);
    PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;

    typedef void(APIENTRYP PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
    PFNGLBINDBUFFERPROC glBindBuffer;

    typedef void(APIENTRYP PFNGLDELETEBUFFERSPROC)(GLsizei n, const GLuint* buffers);
    PFNGLDELETEBUFFERSPROC glDeleteBuffers;

    typedef void(APIENTRYP PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
    PFNGLGENBUFFERSPROC glGenBuffers;

    typedef GLboolean(APIENTRYP PFNGLISBUFFERPROC)(GLuint buffer);
    PFNGLISBUFFERPROC glIsBuffer;

    typedef void(APIENTRYP PFNGLBUFFERDATAPROC)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
    PFNGLBUFFERDATAPROC glBufferData;

    typedef void(APIENTRYP PFNGLBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
    PFNGLBUFFERSUBDATAPROC glBufferSubData;

    typedef void(APIENTRYP PFNGLGETBUFFERSUBDATAPROC)(GLenum target, GLintptr offset, GLsizeiptr size, void* data);
    PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;

    typedef void*(APIENTRYP PFNGLMAPBUFFERPROC)(GLenum target, GLenum access);
    PFNGLMAPBUFFERPROC glMapBuffer;

    typedef GLboolean(APIENTRYP PFNGLUNMAPBUFFERPROC)(GLenum target);
    PFNGLUNMAPBUFFERPROC glUnmapBuffer;

    typedef void(APIENTRYP PFNGLGETBUFFERPARAMETERIVPROC)(GLenum target, GLenum pname, GLint* params);
    PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;

    typedef void(APIENTRYP PFNGLGETBUFFERPOINTERVPROC)(GLenum target, GLenum pname, void** params);
    PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;

  public:
    GLfuncsv150();

  protected:
    virtual void loadFuncs(Loader loader) override;
};
} // namespace glr