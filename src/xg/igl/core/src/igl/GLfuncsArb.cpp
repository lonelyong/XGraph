#include <xg/igl/ogl/GLfuncsArb.hpp>

namespace xg
{
namespace glr
{

GLfuncsArb::GLfuncsArb()
  : oglBufferPageCommitmentARB(nullptr)
  , oglCompileShaderIncludeARB(nullptr)
  , oglCreateSyncFromCLeventARB(nullptr)
  , oglDeleteNamedStringARB(nullptr)
  , oglEvaluateDepthValuesARB(nullptr)
  , oglFramebufferSampleLocationsfvARB(nullptr)
  , oglGetGraphicsResetStatusARB(nullptr)
  , oglGetImageHandleARB(nullptr)
  , oglGetNamedStringARB(nullptr)
  , oglGetNamedStringivARB(nullptr)
  , oglGetTextureHandleARB(nullptr)
  , oglGetTextureSamplerHandleARB(nullptr)
  , oglGetVertexAttribLui64vARB(nullptr)
  , oglGetnColorTableARB(nullptr)
  , oglGetnCompressedTexImageARB(nullptr)
  , oglGetnConvolutionFilterARB(nullptr)
  , oglGetnHistogramARB(nullptr)
  , oglGetnMapdvARB(nullptr)
  , oglGetnMapfvARB(nullptr)
  , oglGetnMapivARB(nullptr)
  , oglGetnMinmaxARB(nullptr)
  , oglGetnPixelMapfvARB(nullptr)
  , oglGetnPixelMapuivARB(nullptr)
  , oglGetnPixelMapusvARB(nullptr)
  , oglGetnPolygonStippleARB(nullptr)
  , oglGetnSeparableFilterARB(nullptr)
  , oglGetnTexImageARB(nullptr)
  , oglGetnUniformdvARB(nullptr)
  , oglGetnUniformfvARB(nullptr)
  , oglGetnUniformivARB(nullptr)
  , oglGetnUniformuivARB(nullptr)
  , oglIsImageHandleResidentARB(nullptr)
  , oglIsNamedStringARB(nullptr)
  , oglIsTextureHandleResidentARB(nullptr)
  , oglMakeImageHandleNonResidentARB(nullptr)
  , oglMakeImageHandleResidentARB(nullptr)
  , oglMakeTextureHandleNonResidentARB(nullptr)
  , oglMakeTextureHandleResidentARB(nullptr)
  , oglMaxShaderCompilerThreadsARB(nullptr)
  , oglMinSampleShadingARB(nullptr)
  , oglNamedBufferPageCommitmentARB(nullptr)
  , oglNamedBufferPageCommitmentEXT(nullptr)
  , oglNamedFramebufferSampleLocationsfvARB(nullptr)
  , oglNamedStringARB(nullptr)
  , oglPrimitiveBoundingBoxARB(nullptr)
  , oglProgramUniformHandleui64ARB(nullptr)
  , oglProgramUniformHandleui64vARB(nullptr)
  , oglReadnPixelsARB(nullptr)
  , oglTexPageCommitmentARB(nullptr)
  , oglUniformHandleui64ARB(nullptr)
  , oglUniformHandleui64vARB(nullptr)
  , oglVertexAttribL1ui64ARB(nullptr)
  , oglVertexAttribL1ui64vARB(nullptr)
{}

void GLfuncsArb::loadFuncsArb(Loader loader)
{
    oglBufferPageCommitmentARB              = reinterpret_cast<PFNGLBUFFERPAGECOMMITMENTARBPROC>(loader("glBufferPageCommitmentARB"));
    oglCompileShaderIncludeARB              = reinterpret_cast<PFNGLCOMPILESHADERINCLUDEARBPROC>(loader("glCompileShaderIncludeARB"));
    oglCreateSyncFromCLeventARB             = reinterpret_cast<PFNGLCREATESYNCFROMCLEVENTARBPROC>(loader("glCreateSyncFromCLeventARB"));
    oglDeleteNamedStringARB                 = reinterpret_cast<PFNGLDELETENAMEDSTRINGARBPROC>(loader("glDeleteNamedStringARB"));
    oglEvaluateDepthValuesARB               = reinterpret_cast<PFNGLEVALUATEDEPTHVALUESARBPROC>(loader("glEvaluateDepthValuesARB"));
    oglFramebufferSampleLocationsfvARB      = reinterpret_cast<PFNGLFRAMEBUFFERSAMPLELOCATIONSFVARBPROC>(loader("glFramebufferSampleLocationsfvARB"));
    oglGetGraphicsResetStatusARB            = reinterpret_cast<PFNGLGETGRAPHICSRESETSTATUSARBPROC>(loader("glGetGraphicsResetStatusARB"));
    oglGetImageHandleARB                    = reinterpret_cast<PFNGLGETIMAGEHANDLEARBPROC>(loader("glGetImageHandleARB"));
    oglGetNamedStringARB                    = reinterpret_cast<PFNGLGETNAMEDSTRINGARBPROC>(loader("glGetNamedStringARB"));
    oglGetNamedStringivARB                  = reinterpret_cast<PFNGLGETNAMEDSTRINGIVARBPROC>(loader("glGetNamedStringivARB"));
    oglGetTextureHandleARB                  = reinterpret_cast<PFNGLGETTEXTUREHANDLEARBPROC>(loader("glGetTextureHandleARB"));
    oglGetTextureSamplerHandleARB           = reinterpret_cast<PFNGLGETTEXTURESAMPLERHANDLEARBPROC>(loader("glGetTextureSamplerHandleARB"));
    oglGetVertexAttribLui64vARB             = reinterpret_cast<PFNGLGETVERTEXATTRIBLUI64VARBPROC>(loader("glGetVertexAttribLui64vARB"));
    oglGetnColorTableARB                    = reinterpret_cast<PFNGLGETNCOLORTABLEARBPROC>(loader("glGetnColorTableARB"));
    oglGetnCompressedTexImageARB            = reinterpret_cast<PFNGLGETNCOMPRESSEDTEXIMAGEARBPROC>(loader("glGetnCompressedTexImageARB"));
    oglGetnConvolutionFilterARB             = reinterpret_cast<PFNGLGETNCONVOLUTIONFILTERARBPROC>(loader("glGetnConvolutionFilterARB"));
    oglGetnHistogramARB                     = reinterpret_cast<PFNGLGETNHISTOGRAMARBPROC>(loader("glGetnHistogramARB"));
    oglGetnMapdvARB                         = reinterpret_cast<PFNGLGETNMAPDVARBPROC>(loader("glGetnMapdvARB"));
    oglGetnMapfvARB                         = reinterpret_cast<PFNGLGETNMAPFVARBPROC>(loader("glGetnMapfvARB"));
    oglGetnMapivARB                         = reinterpret_cast<PFNGLGETNMAPIVARBPROC>(loader("glGetnMapivARB"));
    oglGetnMinmaxARB                        = reinterpret_cast<PFNGLGETNMINMAXARBPROC>(loader("glGetnMinmaxARB"));
    oglGetnPixelMapfvARB                    = reinterpret_cast<PFNGLGETNPIXELMAPFVARBPROC>(loader("glGetnPixelMapfvARB"));
    oglGetnPixelMapuivARB                   = reinterpret_cast<PFNGLGETNPIXELMAPUIVARBPROC>(loader("glGetnPixelMapuivARB"));
    oglGetnPixelMapusvARB                   = reinterpret_cast<PFNGLGETNPIXELMAPUSVARBPROC>(loader("glGetnPixelMapusvARB"));
    oglGetnPolygonStippleARB                = reinterpret_cast<PFNGLGETNPOLYGONSTIPPLEARBPROC>(loader("glGetnPolygonStippleARB"));
    oglGetnSeparableFilterARB               = reinterpret_cast<PFNGLGETNSEPARABLEFILTERARBPROC>(loader("glGetnSeparableFilterARB"));
    oglGetnTexImageARB                      = reinterpret_cast<PFNGLGETNTEXIMAGEARBPROC>(loader("glGetnTexImageARB"));
    oglGetnUniformdvARB                     = reinterpret_cast<PFNGLGETNUNIFORMDVARBPROC>(loader("glGetnUniformdvARB"));
    oglGetnUniformfvARB                     = reinterpret_cast<PFNGLGETNUNIFORMFVARBPROC>(loader("glGetnUniformfvARB"));
    oglGetnUniformivARB                     = reinterpret_cast<PFNGLGETNUNIFORMIVARBPROC>(loader("glGetnUniformivARB"));
    oglGetnUniformuivARB                    = reinterpret_cast<PFNGLGETNUNIFORMUIVARBPROC>(loader("glGetnUniformuivARB"));
    oglIsImageHandleResidentARB             = reinterpret_cast<PFNGLISIMAGEHANDLERESIDENTARBPROC>(loader("glIsImageHandleResidentARB"));
    oglIsNamedStringARB                     = reinterpret_cast<PFNGLISNAMEDSTRINGARBPROC>(loader("glIsNamedStringARB"));
    oglIsTextureHandleResidentARB           = reinterpret_cast<PFNGLISTEXTUREHANDLERESIDENTARBPROC>(loader("glIsTextureHandleResidentARB"));
    oglMakeImageHandleNonResidentARB        = reinterpret_cast<PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC>(loader("glMakeImageHandleNonResidentARB"));
    oglMakeImageHandleResidentARB           = reinterpret_cast<PFNGLMAKEIMAGEHANDLERESIDENTARBPROC>(loader("glMakeImageHandleResidentARB"));
    oglMakeTextureHandleNonResidentARB      = reinterpret_cast<PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC>(loader("glMakeTextureHandleNonResidentARB"));
    oglMakeTextureHandleResidentARB         = reinterpret_cast<PFNGLMAKETEXTUREHANDLERESIDENTARBPROC>(loader("glMakeTextureHandleResidentARB"));
    oglMaxShaderCompilerThreadsARB          = reinterpret_cast<PFNGLMAXSHADERCOMPILERTHREADSARBPROC>(loader("glMaxShaderCompilerThreadsARB"));
    oglMinSampleShadingARB                  = reinterpret_cast<PFNGLMINSAMPLESHADINGARBPROC>(loader("glMinSampleShadingARB"));
    oglNamedBufferPageCommitmentARB         = reinterpret_cast<PFNGLNAMEDBUFFERPAGECOMMITMENTARBPROC>(loader("glNamedBufferPageCommitmentARB"));
    oglNamedBufferPageCommitmentEXT         = reinterpret_cast<PFNGLNAMEDBUFFERPAGECOMMITMENTEXTPROC>(loader("glNamedBufferPageCommitmentEXT"));
    oglNamedFramebufferSampleLocationsfvARB = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERSAMPLELOCATIONSFVARBPROC>(loader("glNamedFramebufferSampleLocationsfvARB"));
    oglNamedStringARB                       = reinterpret_cast<PFNGLNAMEDSTRINGARBPROC>(loader("glNamedStringARB"));
    oglPrimitiveBoundingBoxARB              = reinterpret_cast<PFNGLPRIMITIVEBOUNDINGBOXARBPROC>(loader("glPrimitiveBoundingBoxARB"));
    oglProgramUniformHandleui64ARB          = reinterpret_cast<PFNGLPROGRAMUNIFORMHANDLEUI64ARBPROC>(loader("glProgramUniformHandleui64ARB"));
    oglProgramUniformHandleui64vARB         = reinterpret_cast<PFNGLPROGRAMUNIFORMHANDLEUI64VARBPROC>(loader("glProgramUniformHandleui64vARB"));
    oglReadnPixelsARB                       = reinterpret_cast<PFNGLREADNPIXELSARBPROC>(loader("glReadnPixelsARB"));
    oglTexPageCommitmentARB                 = reinterpret_cast<PFNGLTEXPAGECOMMITMENTARBPROC>(loader("glTexPageCommitmentARB"));
    oglUniformHandleui64ARB                 = reinterpret_cast<PFNGLUNIFORMHANDLEUI64ARBPROC>(loader("glUniformHandleui64ARB"));
    oglUniformHandleui64vARB                = reinterpret_cast<PFNGLUNIFORMHANDLEUI64VARBPROC>(loader("glUniformHandleui64vARB"));
    oglVertexAttribL1ui64ARB                = reinterpret_cast<PFNGLVERTEXATTRIBL1UI64ARBPROC>(loader("glVertexAttribL1ui64ARB"));
    oglVertexAttribL1ui64vARB               = reinterpret_cast<PFNGLVERTEXATTRIBL1UI64VARBPROC>(loader("glVertexAttribL1ui64vARB"));
}

} // namespace glr
} // namespace xg
