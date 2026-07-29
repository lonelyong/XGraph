
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

#ifndef ENTRY
#    define ENTRY APIENTRY
#endif

namespace xg
{
namespace glr
{

class IGL_CORE_API GLfuncsArb {

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
    PFNGLPRIMITIVEBOUNDINGBOXARBPROC oglPrimitiveBoundingBoxARB;
#pragma endregion

#pragma region GL_ARB_bindless_texture
    typedef GLuint64(APIENTRYP PFNGLGETTEXTUREHANDLEARBPROC)(GLuint texture);
    PFNGLGETTEXTUREHANDLEARBPROC oglGetTextureHandleARB;

    typedef GLuint64(APIENTRYP PFNGLGETTEXTURESAMPLERHANDLEARBPROC)(GLuint texture, GLuint sampler);
    PFNGLGETTEXTURESAMPLERHANDLEARBPROC oglGetTextureSamplerHandleARB;

    typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
    PFNGLMAKETEXTUREHANDLERESIDENTARBPROC oglMakeTextureHandleResidentARB;

    typedef void(APIENTRYP PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC)(GLuint64 handle);
    PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC oglMakeTextureHandleNonResidentARB;

    typedef GLuint64(APIENTRYP PFNGLGETIMAGEHANDLEARBPROC)(GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
    PFNGLGETIMAGEHANDLEARBPROC oglGetImageHandleARB;

    typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle, GLenum access);
    PFNGLMAKEIMAGEHANDLERESIDENTARBPROC oglMakeImageHandleResidentARB;

    typedef void(APIENTRYP PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC)(GLuint64 handle);
    PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC oglMakeImageHandleNonResidentARB;

    typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64ARBPROC)(GLint location, GLuint64 value);
    PFNGLUNIFORMHANDLEUI64ARBPROC oglUniformHandleui64ARB;

    typedef void(APIENTRYP PFNGLUNIFORMHANDLEUI64VARBPROC)(GLint location, GLsizei count, const GLuint64* value);
    PFNGLUNIFORMHANDLEUI64VARBPROC oglUniformHandleui64vARB;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC)(GLuint program, GLint location, GLuint64 value);
    PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC oglProgramUniformHandleui64ARB;

    typedef void(APIENTRYP PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC)(GLuint program, GLint location, GLsizei count, const GLuint64* values);
    PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC oglProgramUniformHandleui64vARB;

    typedef GLboolean(APIENTRYP PFNGLISTEXTUREHANDLERESIDENTARBPROC)(GLuint64 handle);
    PFNGLISTEXTUREHANDLERESIDENTARBPROC oglIsTextureHandleResidentARB;

    typedef GLboolean(APIENTRYP PFNGLISIMAGEHANDLERESIDENTARBPROC)(GLuint64 handle);
    PFNGLISIMAGEHANDLERESIDENTARBPROC oglIsImageHandleResidentARB;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64ARBPROC)(GLuint index, GLuint64EXT x);
    PFNGLVERTEXATTRIBL1UI64ARBPROC oglVertexAttribL1ui64ARB;

    typedef void(APIENTRYP PFNGLVERTEXATTRIBL1UI64VARBPROC)(GLuint index, const GLuint64EXT* v);
    PFNGLVERTEXATTRIBL1UI64VARBPROC oglVertexAttribL1ui64vARB;

    typedef void(APIENTRYP PFNGLGETVERTEXATTRIBLUI64VARBPROC)(GLuint index, GLenum pname, GLuint64EXT* params);
    PFNGLGETVERTEXATTRIBLUI64VARBPROC oglGetVertexAttribLui64vARB;

#pragma endregion

#pragma region GL_ARB_cl_event
    typedef GLsync(APIENTRYP PFNGLCREATESYNCFROMCLEVENTARBPROC)(struct _cl_context* context, struct _cl_event* event, GLbitfield flags);
    PFNGLCREATESYNCFROMCLEVENTARBPROC oglCreateSyncFromCLeventARB;
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
    PFNGLTEXPAGECOMMITMENTARBPROC oglTexPageCommitmentARB;
#pragma endregion

#pragma region GL_ARB_sparse_buffer
    typedef void(APIENTRYP PFNGLBUFFERPAGECOMMITMENTARBPROC)(GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
    PFNGLBUFFERPAGECOMMITMENTARBPROC oglBufferPageCommitmentARB;
    typedef void(APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
    PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC oglNamedBufferPageCommitmentEXT;
    typedef void(APIENTRYP PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC)(GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
    PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC oglNamedBufferPageCommitmentARB;
#pragma endregion

#pragma region GL_ARB_shading_language_include
    typedef void(APIENTRYP PFNGLNAMEDSTRINGARBPROC)(GLenum type, GLint namelen, const GLchar* name, GLint stringlen, const GLchar* string);
    PFNGLNAMEDSTRINGARBPROC oglNamedStringARB;

    typedef void(APIENTRYP PFNGLDELETENAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
    PFNGLDELETENAMEDSTRINGARBPROC oglDeleteNamedStringARB;

    typedef void(APIENTRYP PFNGLCOMPILESHADERINCLUDEARBPROC)(GLuint shader, GLsizei count, const GLchar* const* path, const GLint* length);
    PFNGLCOMPILESHADERINCLUDEARBPROC oglCompileShaderIncludeARB;

    typedef GLboolean(APIENTRYP PFNGLISNAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name);
    PFNGLISNAMEDSTRINGARBPROC oglIsNamedStringARB;

    typedef void(APIENTRYP PFNGLGETNAMEDSTRINGARBPROC)(GLint namelen, const GLchar* name, GLsizei bufSize, GLint* stringlen, GLchar* string);
    PFNGLGETNAMEDSTRINGARBPROC oglGetNamedStringARB;

    typedef void(APIENTRYP PFNGLGETNAMEDSTRINGIVARBPROC)(GLint namelen, const GLchar* name, GLenum pname, GLint* params);
    PFNGLGETNAMEDSTRINGIVARBPROC oglGetNamedStringivARB;
#pragma endregion

#pragma region GL_ARB_sample_shading
    typedef void(APIENTRYP PFNGLMINSAMPLESHADINGARBPROC)(GLfloat value);
    PFNGLMINSAMPLESHADINGARBPROC oglMinSampleShadingARB;
#pragma endregion

#pragma region GL_ARB_sample_locations
    typedef void(APIENTRYP PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLenum target, GLuint start, GLsizei count, const GLfloat* v);
    PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC oglFramebufferSampleLocationsfvARB;

    typedef void(APIENTRYP PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC)(GLuint framebuffer, GLuint start, GLsizei count, const GLfloat* v);
    PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC oglNamedFramebufferSampleLocationsfvARB;

    typedef void(APIENTRYP PFNGLEVALUATEDEPTHVALUESARBPROC)(void);
    PFNGLEVALUATEDEPTHVALUESARBPROC oglEvaluateDepthValuesARB;
#pragma endregion

#pragma region GL_ARB_robustness
    typedef GLenum(APIENTRYP PFNGLGETGRAPHICSRESETSTATUSARBPROC)(void);
    PFNGLGETGRAPHICSRESETSTATUSARBPROC oglGetGraphicsResetStatusARB;
#define glGetGraphicsResetStatusARBoglGetGraphicsResetStatusARB
    typedef void(APIENTRYP PFNGLGETNTEXIMAGEARBPROC)(GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void* img);
    PFNGLGETNTEXIMAGEARBPROC oglGetnTexImageARB;
#define glGetnTexImageARBoglGetnTexImageARB
    typedef void(APIENTRYP PFNGLREADNPIXELSARBPROC)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void* data);
    PFNGLREADNPIXELSARBPROC oglReadnPixelsARB;

    typedef void(APIENTRYP PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC)(GLenum target, GLint lod, GLsizei bufSize, void* img);
    PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC oglGetnCompressedTexImageARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMFVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLfloat* params);
    PFNGLGETNUNIFORMFVARBPROC oglGetnUniformfvARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLint* params);
    PFNGLGETNUNIFORMIVARBPROC oglGetnUniformivARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMUIVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLuint* params);
    PFNGLGETNUNIFORMUIVARBPROC oglGetnUniformuivARB;

    typedef void(APIENTRYP PFNGLGETNUNIFORMDVARBPROC)(GLuint program, GLint location, GLsizei bufSize, GLdouble* params);
    PFNGLGETNUNIFORMDVARBPROC oglGetnUniformdvARB;

    typedef void(APIENTRYP PFNGLGETNMAPDVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLdouble* v);
    PFNGLGETNMAPDVARBPROC oglGetnMapdvARB;

    typedef void(APIENTRYP PFNGLGETNMAPFVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLfloat* v);
    PFNGLGETNMAPFVARBPROC oglGetnMapfvARB;

    typedef void(APIENTRYP PFNGLGETNMAPIVARBPROC)(GLenum target, GLenum query, GLsizei bufSize, GLint* v);
    PFNGLGETNMAPIVARBPROC oglGetnMapivARB;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPFVARBPROC)(GLenum map, GLsizei bufSize, GLfloat* values);
    PFNGLGETNPIXELMAPFVARBPROC oglGetnPixelMapfvARB;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUIVARBPROC)(GLenum map, GLsizei bufSize, GLuint* values);
    PFNGLGETNPIXELMAPUIVARBPROC oglGetnPixelMapuivARB;

    typedef void(APIENTRYP PFNGLGETNPIXELMAPUSVARBPROC)(GLenum map, GLsizei bufSize, GLushort* values);
    PFNGLGETNPIXELMAPUSVARBPROC oglGetnPixelMapusvARB;

    typedef void(APIENTRYP PFNGLGETNPOLYGONSTIPPLEARBPROC)(GLsizei bufSize, GLubyte* pattern);
    PFNGLGETNPOLYGONSTIPPLEARBPROC oglGetnPolygonStippleARB;

    typedef void(APIENTRYP PFNGLGETNCOLORTABLEARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* table);
    PFNGLGETNCOLORTABLEARBPROC oglGetnColorTableARB;

    typedef void(APIENTRYP PFNGLGETNCONVOLUTIONFILTERARBPROC)(GLenum target, GLenum format, GLenum type, GLsizei bufSize, void* image);
    PFNGLGETNCONVOLUTIONFILTERARBPROC oglGetnConvolutionFilterARB;

    typedef void(APIENTRYP PFNGLGETNSEPARABLEFILTERARBPROC)(GLenum  target,
                                                            GLenum  format,
                                                            GLenum  type,
                                                            GLsizei rowBufSize,
                                                            void*   row,
                                                            GLsizei columnBufSize,
                                                            void*   column,
                                                            void*   span);
    PFNGLGETNSEPARABLEFILTERARBPROC oglGetnSeparableFilterARB;

    typedef void(APIENTRYP PFNGLGETNHISTOGRAMARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
    PFNGLGETNHISTOGRAMARBPROC oglGetnHistogramARB;

    typedef void(APIENTRYP PFNGLGETNMINMAXARBPROC)(GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void* values);
    PFNGLGETNMINMAXARBPROC oglGetnMinmaxARB;
#pragma endregion

#pragma region GL_ARB_parallel_shader_compile
    typedef void(APIENTRYP PFNGLMAXSHADERCOMPILERTHREADSARBPROC)(GLuint count);
    PFNGLMAXSHADERCOMPILERTHREADSARBPROC oglMaxShaderCompilerThreadsARB;
#pragma endregion

  public:
    GLfuncsArb();

  protected:
    virtual void loadFuncsArb(Loader loader);
};

} // namespace glr
} // namespace xg