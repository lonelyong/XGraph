#pragma once

#include <xg/igl/ogl/GLfuncsv110.hpp>

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsv120 : public GLfuncsv110 {

  public:
    typedef void(APIENTRYP PFNGLDRAWRANGEELEMENTSPROC)(GLenum_t mode, GLuint_t start, GLuint_t end, GLsizei_t count, GLenum_t type, const void* indices);
    PFNGLDRAWRANGEELEMENTSPROC oglDrawRangeElements;

    typedef void(APIENTRYP PFNGLTEXIMAGE3DPROC)(GLenum_t    target,
                                                GLint_t     level,
                                                GLint_t     internalformat,
                                                GLsizei_t   width,
                                                GLsizei_t   height,
                                                GLsizei_t   depth,
                                                GLint_t     border,
                                                GLenum_t    format,
                                                GLenum_t    type,
                                                const void* pixels);
    PFNGLTEXIMAGE3DPROC oglTexImage3D;

    typedef void(APIENTRYP PFNGLTEXSUBIMAGE3DPROC)(GLenum_t    target,
                                                   GLint_t     level,
                                                   GLint_t     xoffset,
                                                   GLint_t     yoffset,
                                                   GLint_t     zoffset,
                                                   GLsizei_t   width,
                                                   GLsizei_t   height,
                                                   GLsizei_t   depth,
                                                   GLenum_t    format,
                                                   GLenum_t    type,
                                                   const void* pixels);
    PFNGLTEXSUBIMAGE3DPROC oglTexSubImage3D;

    typedef void(APIENTRYP PFNGLCOPYTEXSUBIMAGE3DPROC)(GLenum_t  target,
                                                       GLint_t   level,
                                                       GLint_t   xoffset,
                                                       GLint_t   yoffset,
                                                       GLint_t   zoffset,
                                                       GLint_t   x,
                                                       GLint_t   y,
                                                       GLsizei_t width,
                                                       GLsizei_t height);
    PFNGLCOPYTEXSUBIMAGE3DPROC oglCopyTexSubImage3D;

  public:
    GLfuncsv120();

  protected:
    virtual void loadFuncs(Loader loader) override;
};

} // namespace glr
} // namespace xg