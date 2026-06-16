
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

#ifndef ENTRY
#    define ENTRY APIENTRY
#endif

namespace xg {
namespace glr {

class GLR_API GLfuncsArb {

  public:
    using GLenum      = GLenum_t;
    using GLuint      = GLuint_t;
    using GLfloat     = GLfloat_t;
    using GLsizei     = GLsizei_t;
    using GLchar      = GLchar_t;
    using GLint       = GLint_t;
    using GLbitfield  = GLbitfield_t;
    using GLdouble    = GLdouble_t;
    using GLboolean   = GLboolean_t;
    using GLubyte     = GLubyte_t;
    using GLuint64    = GLuint64_t;
    using GLuint64EXT = GLuint64EXT_t;
    using GLintptr    = GLintptr_t;
    using GLsizeiptr  = GLsizeiptr_t;
    using GLushort    = GLushort_t;

  public:
    typedef void* (*Loader)(const char* fn);

  public:
#pragma region GL_ARB_ES3_2_compatibility
    typedef void(APIENTRYP PFNGLPRIMITIVEBOUNDINGBOXARBPROC)(GLfloat minX,
                                                             GLfloat minY,
                                                             GLfloat minZ,
                                                             GLfloat minW,
                                                             GLfloat maxX,
                                                             GLfloat maxY,
                                                             GLfloat maxZ,
                                                             GLfloat maxW);
    PFNGLPRIMITIVEBOUNDINGBOXARBPROC iglPrimitiveBoundingBoxARB;
#pragma endregion

#pragma region GL_ARB_bindless_texture
    typedef GLuint64(APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC)(GLuint texture);
    PFNGLGETTEXTUREHANDLEARBPROC iglGetTextureHandleARB;

    typedef GLuint64(APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC)(GLuint texture, GLuint sampler);
    PFNGLGETTEXTURESAMPLERHANDLEARBPROC iglGetTextureSamplerHandleARB;

    typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
    PFNGLMAKETEXTUREHANDLERESIDENTARBPROC iglMakeTextureHandleResidentARB;

    typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)(GLuint64 handle);
    PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC iglMakeTextureHandleNonResidentARB;

    typedef GLuint64(APIENTRYP PFNGLGETIMAGEHANDLEARBPROC)(GLuint    texture,
                                                           GLint     level,
                                                           GLboolean layered,
                                                           GLint     layer,
                                                           GLenum    format);
    PFNGLGETIMAGEHANDLEARBPROC iglGetImageHandleARB;

    typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle, GLenum access);
    PFNGLMAKEIMAGEHANDLERESIDENTARBPROC iglMakeImageHandleResidentARB;

    typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)(GLuint64 handle);
    PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC iglMakeImageHandleNonResidentARB;

    typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC)(GLint location, GLuint64 value);
    PFNGLUNIFORMHANDLEUI64ARBPROC iglUniformHandleui64ARB;

    typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
    PFNGLUNIFORMHANDLEUI64VARBPROC iglUniformHandleui64vARB;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)(GLuint program, GLint location, GLuint64 value);
    PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC iglProgramUniformHandleui64ARB;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)(GLuint          program,
                                                                  GLint           location,
                                                                  GLsizei         count,
                                                                  const GLuint64* values);
    PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC iglProgramUniformHandleui64vARB;

    typedef GLboolean(APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
    PFNGLISTEXTUREHANDLERESIDENTARBPROC iglIsTextureHandleResidentARB;

    typedef GLboolean(APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle);
    PFNGLISIMAGEHANDLERESIDENTARBPROC iglIsImageHandleResidentARB;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC)(GLuint index, GLuint64EXT x);
    PFNGLVERTEXATTRIBL1UI64ARBPROC iglVertexAttribL1ui64ARB;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC)(GLuint index, const GLuint64EXT* v);
    PFNGLVERTEXATTRIBL1UI64VARBPROC iglVertexAttribL1ui64vARB;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC)(GLuint index, GLenum pname, GLuint64EXT* params);
    PFNGLGETVERTEXATTRIBLUI64VARBPROC iglGetVertexAttribLui64vARB;

#pragma endregion

#pragma region GL_ARB_cl_event
    typedef GLsync(APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context* context,
                                                                struct _cl_event*   event,
                                                                GLbitfield          flags);
    PFNGLCREATESYNCFROMCLEVENTARBPROC iglCreateSyncFromCLeventARB;
#pragma endregion

#pragma region GL_ARB_sparse_texture
    typedef void(APIENTRYP PFNGLTEXPAGECOMMITMENTARBPROC)(GLenum    target,
                                                          GLint     level,
                                                          GLint     xoffset,
                                                          GLint     yoffset,
                                                          GLint     zoffset,
                                                          GLsizei   width,
                                                          GLsizei   height,
                                                          GLsizei   depth,
                                                          GLboolean commit);
    PFNGLTEXPAGECOMMITMENTARBPROC iglTexPageCommitmentARB;
#pragma endregion

#pragma region GL_ARB_sparse_buffer
    typedef void(APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC)(GLenum     target,
                                                             GLintptr   offset,
                                                             GLsizeiptr size,
                                                             GLboolean  commit);
    PFNGLBUFFERPAGECOMMITMENTARBPROC iglBufferPageCommitmentARB;
    typedef void(APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)(GLuint     buffer,
                                                                  GLintptr   offset,
                                                                  GLsizeiptr size,
                                                                  GLboolean  commit);
    PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC iglNamedBufferPageCommitmentEXT;
    typedef void(APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)(GLuint     buffer,
                                                                  GLintptr   offset,
                                                                  GLsizeiptr size,
                                                                  GLboolean  commit);
    PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC iglNamedBufferPageCommitmentARB;
#pragma endregion

#pragma region GL_ARB_shading_language_include
    typedef void(APIENTRYP PFNGLNAMEDSTRINGARBPROC)(GLenum        type,
                                                    GLint         namelen,
                                                    const GLchar* name,
                                                    GLint         stringlen,
                                                    const GLchar* string);
    PFNGLNAMEDSTRINGARBPROC iglNamedStringARB;

    typedef void(APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
    PFNGLDELETENAMEDSTRINGARBPROC iglDeleteNamedStringARB;

    typedef void(APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint               shader,
                                                             GLsizei              count,
                                                             const GLchar* const* path,
                                                             const GLint*         length);
    PFNGLCOMPILESHADERINCLUDEARBPROC iglCompileShaderIncludeARB;

    typedef GLboolean(APIENTRYP PFNGLISNAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
    PFNGLISNAMEDSTRINGARBPROC iglIsNamedStringARB;

    typedef void(APIENTRYP PFNGLGETNAMEDSTRINGARBPROC)(GLint         namelen,
                                                       const GLchar* name,
                                                       GLsizei       bufSize,
                                                       GLint*        stringlen,
                                                       GLchar*       string);
    PFNGLGETNAMEDSTRINGARBPROC iglGetNamedStringARB;

    typedef void(APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC)(GLint         namelen,
                                                         const GLchar* name,
                                                         GLenum        pname,
                                                         GLint*        params);
    PFNGLGETNAMEDSTRINGIVARBPROC iglGetNamedStringivARB;
#pragma endregion

#pragma region GL_ARB_sample_shading
    typedef void(APIENTRYP PFNGLMINSAMPLESHADINGARBPROC)(GLfloat value);
    PFNGLMINSAMPLESHADINGARBPROC iglMinSampleShadingARB;
#pragma endregion

#pragma region GL_ARB_sample_locations
    typedef void(APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLenum         target,
                                                                     GLuint         start,
                                                                     GLsizei        count,
                                                                     const GLfloat* v);
    PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC iglFramebufferSampleLocationsfvARB;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLuint         framebuffer,
                                                                          GLuint         start,
                                                                          GLsizei        count,
                                                                          const GLfloat* v);
    PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC iglNamedFramebufferSampleLocationsfvARB;

    typedef void(APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC)(void);
    PFNGLEVALUATEDEPTHVALUESARBPROC iglEvaluateDepthValuesARB;
#pragma endregion

#pragma region GL_ARB_robustness
    typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC)(void);
    PFNGLGETGRAPHICSRESETSTATUSARBPROC iglGetGraphicsResetStatusARB;
#define glGetGraphicsResetStatusARB iglGetGraphicsResetStatusARB
    typedef void(APIENTRYP PFNGLGETNTEXIMAGEARBPROC)(GLenum  target,
                                                     GLint   level,
                                                     GLenum  format,
                                                     GLenum  type,
                                                     GLsizei bufSize,
                                                     void*   img);
    PFNGLGETNTEXIMAGEARBPROC iglGetnTexImageARB;
#define glGetnTexImageARB iglGetnTexImageARB
    typedef void(APIENTRYP PFNGLREADNPIXELSARBPROC)(GLint   x,
                                                    GLint   y,
                                                    GLsizei width,
                                                    GLsizei height,
                                                    GLenum  format,
                                                    GLenum  type,
                                                    GLsizei bufSize,
                                                    void*   data);
    PFNGLREADNPIXELSARBPROC iglReadnPixelsARB;

    typedef void(APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLsizei bufSize, void* img);
    PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC iglGetnCompressedTexImageARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMFVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
    PFNGLGETNUNIFORMFVARBPROC iglGetnUniformfvARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
    PFNGLGETNUNIFORMIVARBPROC iglGetnUniformivARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMUIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
    PFNGLGETNUNIFORMUIVARBPROC iglGetnUniformuivARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMDVARBPROC)(GLuint    program,
                                                      GLint     location,
                                                      GLsizei   bufSize,
                                                      GLdouble* params);
    PFNGLGETNUNIFORMDVARBPROC iglGetnUniformdvARB;

    typedef void(APIENTRYP PFNGLGETNMAPDVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
    PFNGLGETNMAPDVARBPROC iglGetnMapdvARB;

    typedef void(APIENTRYP PFNGLGETNMAPFVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
    PFNGLGETNMAPFVARBPROC iglGetnMapfvARB;

    typedef void(APIENTRYP PFNGLGETNMAPIVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
    PFNGLGETNMAPIVARBPROC iglGetnMapivARB;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPFVARBPROC)(GLenum map, GLsizei bufSize, GLfloat* values);
    PFNGLGETNPIXELMAPFVARBPROC iglGetnPixelMapfvARB;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUIVARBPROC)(GLenum map, GLsizei bufSize, GLuint* values);
    PFNGLGETNPIXELMAPUIVARBPROC iglGetnPixelMapuivARB;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUSVARBPROC)(GLenum map, GLsizei bufSize, GLushort* values);
    PFNGLGETNPIXELMAPUSVARBPROC iglGetnPixelMapusvARB;

    typedef void(APIENTRYP PFNGLGETNPOLYGONSTIPPLEARBPROC)(GLsizei bufSize, GLubyte* pattern);
    PFNGLGETNPOLYGONSTIPPLEARBPROC iglGetnPolygonStippleARB;

    typedef void(
        APIENTRYP PFNGLGETNCOLORTABLEARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table);
    PFNGLGETNCOLORTABLEARBPROC iglGetnColorTableARB;

    typedef void(APIENTRYP PFNGLGETNCONVOLUTIONFILTERARBPROC)(GLenum  target,
                                                              GLenum  format,
                                                              GLenum  type,
                                                              GLsizei bufSize,
                                                              void*   image);
    PFNGLGETNCONVOLUTIONFILTERARBPROC iglGetnConvolutionFilterARB;

    typedef void(APIENTRYP PFNGLGETNSEPARABLEFILTERARBPROC)(GLenum  target,
                                                            GLenum  format,
                                                            GLenum  type,
                                                            GLsizei rowBufSize,
                                                            void*   row,
                                                            GLsizei columnBufSize,
                                                            void*   column,
                                                            void*   span);
    PFNGLGETNSEPARABLEFILTERARBPROC iglGetnSeparableFilterARB;

    typedef void(APIENTRYP PFNGLGETNHISTOGRAMARBPROC)(GLenum    target,
                                                      GLboolean reset,
                                                      GLenum    format,
                                                      GLenum    type,
                                                      GLsizei   bufSize,
                                                      void*     values);
    PFNGLGETNHISTOGRAMARBPROC iglGetnHistogramARB;

    typedef void(APIENTRYP PFNGLGETNMINMAXARBPROC)(GLenum    target,
                                                   GLboolean reset,
                                                   GLenum    format,
                                                   GLenum    type,
                                                   GLsizei   bufSize,
                                                   void*     values);
    PFNGLGETNMINMAXARBPROC iglGetnMinmaxARB;
#pragma endregion

#pragma region GL_ARB_parallel_shader_compile
    typedef void(APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC)(GLuint count);
    PFNGLMAXSHADERCOMPILERTHREADSARBPROC iglMaxShaderCompilerThreadsARB;
#pragma endregion

  public:
    GLfuncsArb();

  protected:
    virtual void loadFuncsArb(Loader loader);
};

} // namespace glr
} // namespace xg