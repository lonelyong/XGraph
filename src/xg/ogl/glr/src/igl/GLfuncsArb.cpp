#include "GLfuncsArb.h"

namespace glr {
GLfuncsArb::GLfuncsArb()
  : iglBufferPageCommitmentARB(nullptr)
  , iglCompileShaderIncludeARB(nullptr)
  , iglCreateSyncFromCLeventARB(nullptr)
  , iglDeleteNamedStringARB(nullptr)
  , iglEvaluateDepthValuesARB(nullptr)
  , iglFramebufferSampleLocationsfvARB(nullptr)
  , iglGetGraphicsResetStatusARB(nullptr)
  , iglGetImageHandleARB(nullptr)
  , iglGetNamedStringARB(nullptr)
  , iglGetNamedStringivARB(nullptr)
  , iglGetTextureHandleARB(nullptr)
  , iglGetTextureSamplerHandleARB(nullptr)
  , iglGetVertexAttribLui64vARB(nullptr)
  , iglGetnColorTableARB(nullptr)
  , iglGetnCompressedTexImageARB(nullptr)
  , iglGetnConvolutionFilterARB(nullptr)
  , iglGetnHistogramARB(nullptr)
  , iglGetnMapdvARB(nullptr)
  , iglGetnMapfvARB(nullptr)
  , iglGetnMapivARB(nullptr)
  , iglGetnMinmaxARB(nullptr)
  , iglGetnPixelMapfvARB(nullptr)
  , iglGetnPixelMapuivARB(nullptr)
  , iglGetnPixelMapusvARB(nullptr)
  , iglGetnPolygonStippleARB(nullptr)
  , iglGetnSeparableFilterARB(nullptr)
  , iglGetnTexImageARB(nullptr)
  , iglGetnUniformdvARB(nullptr)
  , iglGetnUniformfvARB(nullptr)
  , iglGetnUniformivARB(nullptr)
  , iglGetnUniformuivARB(nullptr)
  , iglIsImageHandleResidentARB(nullptr)
  , iglIsNamedStringARB(nullptr)
  , iglIsTextureHandleResidentARB(nullptr)
  , iglMakeImageHandleNonResidentARB(nullptr)
  , iglMakeImageHandleResidentARB(nullptr)
  , iglMakeTextureHandleNonResidentARB(nullptr)
  , iglMakeTextureHandleResidentARB(nullptr)
  , iglMaxShaderCompilerThreadsARB(nullptr)
  , iglMinSampleShadingARB(nullptr)
  , iglNamedBufferPageCommitmentARB(nullptr)
  , iglNamedBufferPageCommitmentEXT(nullptr)
  , iglNamedFramebufferSampleLocationsfvARB(nullptr)
  , iglNamedStringARB(nullptr)
  , iglPrimitiveBoundingBoxARB(nullptr)
  , iglProgramUniformHandleui64ARB(nullptr)
  , iglProgramUniformHandleui64vARB(nullptr)
  , iglReadnPixelsARB(nullptr)
  , iglTexPageCommitmentARB(nullptr)
  , iglUniformHandleui64ARB(nullptr)
  , iglUniformHandleui64vARB(nullptr)
  , iglVertexAttribL1ui64ARB(nullptr)
  , iglVertexAttribL1ui64vARB(nullptr) {
}

void GLfuncsArb::loadFuncsArb(Loader loader) {
    iglBufferPageCommitmentARB =
        reinterpret_cast<PFNGLBUFFERPAGECOMMITMENTARBPROC>(loader("glBufferPageCommitmentARB"));
    iglCompileShaderIncludeARB =
        reinterpret_cast<PFNGLCOMPILESHADERINCLUDEARBPROC>(loader("glCompileShaderIncludeARB"));
    iglCreateSyncFromCLeventARB =
        reinterpret_cast<PFNGLCREATESYNCFROMCLEVENTARBPROC>(loader("glCreateSyncFromCLeventARB"));
    iglDeleteNamedStringARB   = reinterpret_cast<PFNGLDELETENAMEDSTRINGARBPROC>(loader("glDeleteNamedStringARB"));
    iglEvaluateDepthValuesARB = reinterpret_cast<PFNGLEVALUATEDEPTHVALUESARBPROC>(loader("glEvaluateDepthValuesARB"));
    iglFramebufferSampleLocationsfvARB =
        reinterpret_cast<PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC>(loader("glFramebufferSampleLocationsfvARB"));
    iglGetGraphicsResetStatusARB =
        reinterpret_cast<PFNGLGETGRAPHICSRESETSTATUSARBPROC>(loader("glGetGraphicsResetStatusARB"));
    iglGetImageHandleARB   = reinterpret_cast<PFNGLGETIMAGEHANDLEARBPROC>(loader("glGetImageHandleARB"));
    iglGetNamedStringARB   = reinterpret_cast<PFNGLGETNAMEDSTRINGARBPROC>(loader("glGetNamedStringARB"));
    iglGetNamedStringivARB = reinterpret_cast<PFNGLGETNAMEDSTRINGIVARBPROC>(loader("glGetNamedStringivARB"));
    iglGetTextureHandleARB = reinterpret_cast<PFNGLGETTEXTUREHANDLEARBPROC>(loader("glGetTextureHandleARB"));
    iglGetTextureSamplerHandleARB =
        reinterpret_cast<PFNGLGETTEXTURESAMPLERHANDLEARBPROC>(loader("glGetTextureSamplerHandleARB"));
    iglGetVertexAttribLui64vARB =
        reinterpret_cast<PFNGLGETVERTEXATTRIBLUI64VARBPROC>(loader("glGetVertexAttribLui64vARB"));
    iglGetnColorTableARB = reinterpret_cast<PFNGLGETNCOLORTABLEARBPROC>(loader("glGetnColorTableARB"));
    iglGetnCompressedTexImageARB =
        reinterpret_cast<PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC>(loader("glGetnCompressedTexImageARB"));
    iglGetnConvolutionFilterARB =
        reinterpret_cast<PFNGLGETNCONVOLUTIONFILTERARBPROC>(loader("glGetnConvolutionFilterARB"));
    iglGetnHistogramARB       = reinterpret_cast<PFNGLGETNHISTOGRAMARBPROC>(loader("glGetnHistogramARB"));
    iglGetnMapdvARB           = reinterpret_cast<PFNGLGETNMAPDVARBPROC>(loader("glGetnMapdvARB"));
    iglGetnMapfvARB           = reinterpret_cast<PFNGLGETNMAPFVARBPROC>(loader("glGetnMapfvARB"));
    iglGetnMapivARB           = reinterpret_cast<PFNGLGETNMAPIVARBPROC>(loader("glGetnMapivARB"));
    iglGetnMinmaxARB          = reinterpret_cast<PFNGLGETNMINMAXARBPROC>(loader("glGetnMinmaxARB"));
    iglGetnPixelMapfvARB      = reinterpret_cast<PFNGLGETNPIXELMAPFVARBPROC>(loader("glGetnPixelMapfvARB"));
    iglGetnPixelMapuivARB     = reinterpret_cast<PFNGLGETNPIXELMAPUIVARBPROC>(loader("glGetnPixelMapuivARB"));
    iglGetnPixelMapusvARB     = reinterpret_cast<PFNGLGETNPIXELMAPUSVARBPROC>(loader("glGetnPixelMapusvARB"));
    iglGetnPolygonStippleARB  = reinterpret_cast<PFNGLGETNPOLYGONSTIPPLEARBPROC>(loader("glGetnPolygonStippleARB"));
    iglGetnSeparableFilterARB = reinterpret_cast<PFNGLGETNSEPARABLEFILTERARBPROC>(loader("glGetnSeparableFilterARB"));
    iglGetnTexImageARB        = reinterpret_cast<PFNGLGETNTEXIMAGEARBPROC>(loader("glGetnTexImageARB"));
    iglGetnUniformdvARB       = reinterpret_cast<PFNGLGETNUNIFORMDVARBPROC>(loader("glGetnUniformdvARB"));
    iglGetnUniformfvARB       = reinterpret_cast<PFNGLGETNUNIFORMFVARBPROC>(loader("glGetnUniformfvARB"));
    iglGetnUniformivARB       = reinterpret_cast<PFNGLGETNUNIFORMIVARBPROC>(loader("glGetnUniformivARB"));
    iglGetnUniformuivARB      = reinterpret_cast<PFNGLGETNUNIFORMUIVARBPROC>(loader("glGetnUniformuivARB"));
    iglIsImageHandleResidentARB =
        reinterpret_cast<PFNGLISIMAGEHANDLERESIDENTARBPROC>(loader("glIsImageHandleResidentARB"));
    iglIsNamedStringARB = reinterpret_cast<PFNGLISNAMEDSTRINGARBPROC>(loader("glIsNamedStringARB"));
    iglIsTextureHandleResidentARB =
        reinterpret_cast<PFNGLISTEXTUREHANDLERESIDENTARBPROC>(loader("glIsTextureHandleResidentARB"));
    iglMakeImageHandleNonResidentARB =
        reinterpret_cast<PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC>(loader("glMakeImageHandleNonResidentARB"));
    iglMakeImageHandleResidentARB =
        reinterpret_cast<PFNGLMAKEIMAGEHANDLERESIDENTARBPROC>(loader("glMakeImageHandleResidentARB"));
    iglMakeTextureHandleNonResidentARB =
        reinterpret_cast<PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC>(loader("glMakeTextureHandleNonResidentARB"));
    iglMakeTextureHandleResidentARB =
        reinterpret_cast<PFNGLMAKETEXTUREHANDLERESIDENTARBPROC>(loader("glMakeTextureHandleResidentARB"));
    iglMaxShaderCompilerThreadsARB =
        reinterpret_cast<PFNGLMAXSHADERCOMPILERTHREADSARBPROC>(loader("glMaxShaderCompilerThreadsARB"));
    iglMinSampleShadingARB = reinterpret_cast<PFNGLMINSAMPLESHADINGARBPROC>(loader("glMinSampleShadingARB"));
    iglNamedBufferPageCommitmentARB =
        reinterpret_cast<PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC>(loader("glNamedBufferPageCommitmentARB"));
    iglNamedBufferPageCommitmentEXT =
        reinterpret_cast<PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC>(loader("glNamedBufferPageCommitmentEXT"));
    iglNamedFramebufferSampleLocationsfvARB = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC>(
        loader("glNamedFramebufferSampleLocationsfvARB"));
    iglNamedStringARB = reinterpret_cast<PFNGLNAMEDSTRINGARBPROC>(loader("glNamedStringARB"));
    iglPrimitiveBoundingBoxARB =
        reinterpret_cast<PFNGLPRIMITIVEBOUNDINGBOXARBPROC>(loader("glPrimitiveBoundingBoxARB"));
    iglProgramUniformHandleui64ARB =
        reinterpret_cast<PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC>(loader("glProgramUniformHandleui64ARB"));
    iglProgramUniformHandleui64vARB =
        reinterpret_cast<PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC>(loader("glProgramUniformHandleui64vARB"));
    iglReadnPixelsARB         = reinterpret_cast<PFNGLREADNPIXELSARBPROC>(loader("glReadnPixelsARB"));
    iglTexPageCommitmentARB   = reinterpret_cast<PFNGLTEXPAGECOMMITMENTARBPROC>(loader("glTexPageCommitmentARB"));
    iglUniformHandleui64ARB   = reinterpret_cast<PFNGLUNIFORMHANDLEUI64ARBPROC>(loader("glUniformHandleui64ARB"));
    iglUniformHandleui64vARB  = reinterpret_cast<PFNGLUNIFORMHANDLEUI64VARBPROC>(loader("glUniformHandleui64vARB"));
    iglVertexAttribL1ui64ARB  = reinterpret_cast<PFNGLVERTEXATTRIBL1UI64ARBPROC>(loader("glVertexAttribL1ui64ARB"));
    iglVertexAttribL1ui64vARB = reinterpret_cast<PFNGLVERTEXATTRIBL1UI64VARBPROC>(loader("glVertexAttribL1ui64vARB"));
}
} // namespace glr
