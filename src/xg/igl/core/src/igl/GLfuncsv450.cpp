#include <xg/igl/ogl/GLfuncsv450.hpp>

namespace xg
{
namespace glr
{


GLfuncsv450::GLfuncsv450()
  : oglBindTextureUnit(nullptr)
  , oglBlitNamedFramebuffer(nullptr)
  , oglCheckNamedFramebufferStatus(nullptr)
  , oglClearNamedBufferData(nullptr)
  , oglClearNamedBufferSubData(nullptr)
  , oglClearNamedFramebufferfi(nullptr)
  , oglClearNamedFramebufferfv(nullptr)
  , oglClearNamedFramebufferiv(nullptr)
  , oglClearNamedFramebufferuiv(nullptr)
  , oglClipControl(nullptr)
  , oglCompressedTextureSubImage1D(nullptr)
  , oglCompressedTextureSubImage2D(nullptr)
  , oglCompressedTextureSubImage3D(nullptr)
  , oglCopyNamedBufferSubData(nullptr)
  , oglCopyTextureSubImage1D(nullptr)
  , oglCopyTextureSubImage2D(nullptr)
  , oglCopyTextureSubImage3D(nullptr)
  , oglCreateBuffers(nullptr)
  , oglCreateFramebuffers(nullptr)
  , oglCreateProgramPipelines(nullptr)
  , oglCreateQueries(nullptr)
  , oglCreateRenderbuffers(nullptr)
  , oglCreateSamplers(nullptr)
  , oglCreateTextures(nullptr)
  , oglCreateTransformFeedbacks(nullptr)
  , oglCreateVertexArrays(nullptr)
  , oglDisableVertexArrayAttrib(nullptr)
  , oglEnableVertexArrayAttrib(nullptr)
  , oglFlushMappedNamedBufferRange(nullptr)
  , oglGenerateTextureMipmap(nullptr)
  , oglGetCompressedTextureImage(nullptr)
  , oglGetCompressedTextureSubImage(nullptr)
  , oglGetGraphicsResetStatus(nullptr)
  , oglGetNamedBufferParameteri64v(nullptr)
  , oglGetNamedBufferParameteriv(nullptr)
  , oglGetNamedBufferPointerv(nullptr)
  , oglGetNamedBufferSubData(nullptr)
  , oglGetNamedFramebufferAttachmentParameteriv(nullptr)
  , oglGetNamedFramebufferParameteriv(nullptr)
  , oglGetNamedRenderbufferParameteriv(nullptr)
  , oglGetQueryBufferObjecti64v(nullptr)
  , oglGetQueryBufferObjectiv(nullptr)
  , oglGetQueryBufferObjectui64v(nullptr)
  , oglGetQueryBufferObjectuiv(nullptr)
  , oglGetTextureImage(nullptr)
  , oglGetTextureLevelParameterfv(nullptr)
  , oglGetTextureLevelParameteriv(nullptr)
  , oglGetTextureParameterIiv(nullptr)
  , oglGetTextureParameterIuiv(nullptr)
  , oglGetTextureParameterfv(nullptr)
  , oglGetTextureParameteriv(nullptr)
  , oglGetTextureSubImage(nullptr)
  , oglGetTransformFeedbacki64_v(nullptr)
  , oglGetTransformFeedbacki_v(nullptr)
  , oglGetTransformFeedbackiv(nullptr)
  , oglGetVertexArrayIndexed64iv(nullptr)
  , oglGetVertexArrayIndexediv(nullptr)
  , oglGetVertexArrayiv(nullptr)
  , oglGetnColorTable(nullptr)
  , oglGetnCompressedTexImage(nullptr)
  , oglGetnConvolutionFilter(nullptr)
  , oglGetnHistogram(nullptr)
  , oglGetnMapdv(nullptr)
  , oglGetnMapfv(nullptr)
  , oglGetnMapiv(nullptr)
  , oglGetnMinmax(nullptr)
  , oglGetnPixelMapfv(nullptr)
  , oglGetnPixelMapuiv(nullptr)
  , oglGetnPixelMapusv(nullptr)
  , oglGetnPolygonStipple(nullptr)
  , oglGetnSeparableFilter(nullptr)
  , oglGetnTexImage(nullptr)
  , oglGetnUniformdv(nullptr)
  , oglGetnUniformfv(nullptr)
  , oglGetnUniformiv(nullptr)
  , oglGetnUniformuiv(nullptr)
  , oglInvalidateNamedFramebufferData(nullptr)
  , oglInvalidateNamedFramebufferSubData(nullptr)
  , oglMapNamedBufferRange(nullptr)
  , oglMapNamedBuffer(nullptr)
  , oglMemoryBarrierByRegion(nullptr)
  , oglNamedBufferData(nullptr)
  , oglNamedBufferStorage(nullptr)
  , oglNamedBufferSubData(nullptr)
  , oglNamedFramebufferDrawBuffers(nullptr)
  , oglNamedFramebufferDrawBuffer(nullptr)
  , oglNamedFramebufferParameteri(nullptr)
  , oglNamedFramebufferReadBuffer(nullptr)
  , oglNamedFramebufferRenderbuffer(nullptr)
  , oglNamedFramebufferTextureLayer(nullptr)
  , oglNamedFramebufferTexture(nullptr)
  , oglNamedRenderbufferStorageMultisample(nullptr)
  , oglNamedRenderbufferStorage(nullptr)
  , oglReadnPixels(nullptr)
  , oglTextureBarrier(nullptr)
  , oglTextureBufferRange(nullptr)
  , oglTextureBuffer(nullptr)
  , oglTextureParameterIiv(nullptr)
  , oglTextureParameterIuiv(nullptr)
  , oglTextureParameterfv(nullptr)
  , oglTextureParameterf(nullptr)
  , oglTextureParameteriv(nullptr)
  , oglTextureParameteri(nullptr)
  , oglTextureStorage1D(nullptr)
  , oglTextureStorage2DMultisample(nullptr)
  , oglTextureStorage2D(nullptr)
  , oglTextureStorage3DMultisample(nullptr)
  , oglTextureStorage3D(nullptr)
  , oglTextureSubImage1D(nullptr)
  , oglTextureSubImage2D(nullptr)
  , oglTextureSubImage3D(nullptr)
  , oglTransformFeedbackBufferBase(nullptr)
  , oglTransformFeedbackBufferRange(nullptr)
  , oglUnmapNamedBuffer(nullptr)
  , oglVertexArrayAttribBinding(nullptr)
  , oglVertexArrayAttribFormat(nullptr)
  , oglVertexArrayAttribIFormat(nullptr)
  , oglVertexArrayAttribLFormat(nullptr)
  , oglVertexArrayBindingDivisor(nullptr)
  , oglVertexArrayElementBuffer(nullptr)
  , oglVertexArrayVertexBuffers(nullptr)
  , oglVertexArrayVertexBuffer(nullptr)
{}

void GLfuncsv450::loadFuncs(Loader loader)
{
    GLfuncsv440::loadFuncs(loader);
    oglBindTextureUnit              = reinterpret_cast<PFNGLBINDTEXTUREUNITPROC>(loader("glBindTextureUnit"));
    oglBlitNamedFramebuffer         = reinterpret_cast<PFNGLBLITNAMEDFRAMEBUFFERPROC>(loader("glBlitNamedFramebuffer"));
    oglCheckNamedFramebufferStatus  = reinterpret_cast<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC>(loader("glCheckNamedFramebufferStatus"));
    oglClearNamedBufferData         = reinterpret_cast<PFNGLCLEARNAMEDBUFFERDATAPROC>(loader("glClearNamedBufferData"));
    oglClearNamedBufferSubData      = reinterpret_cast<PFNGLCLEARNAMEDBUFFERSUBDATAPROC>(loader("glClearNamedBufferSubData"));
    oglClearNamedFramebufferfi      = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFIPROC>(loader("glClearNamedFramebufferfi"));
    oglClearNamedFramebufferfv      = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFVPROC>(loader("glClearNamedFramebufferfv"));
    oglClearNamedFramebufferiv      = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERIVPROC>(loader("glClearNamedFramebufferiv"));
    oglClearNamedFramebufferuiv     = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC>(loader("glClearNamedFramebufferuiv"));
    oglClipControl                  = reinterpret_cast<PFNGLCLIPCONTROLPROC>(loader("glClipControl"));
    oglCompressedTextureSubImage1D  = reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC>(loader("glCompressedTextureSubImage1D"));
    oglCompressedTextureSubImage2D  = reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC>(loader("glCompressedTextureSubImage2D"));
    oglCompressedTextureSubImage3D  = reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC>(loader("glCompressedTextureSubImage3D"));
    oglCopyNamedBufferSubData       = reinterpret_cast<PFNGLCOPYNAMEDBUFFERSUBDATAPROC>(loader("glCopyNamedBufferSubData"));
    oglCopyTextureSubImage1D        = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE1DPROC>(loader("glCopyTextureSubImage1D"));
    oglCopyTextureSubImage2D        = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE2DPROC>(loader("glCopyTextureSubImage2D"));
    oglCopyTextureSubImage3D        = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE3DPROC>(loader("glCopyTextureSubImage3D"));
    oglCreateBuffers                = reinterpret_cast<PFNGLCREATEBUFFERSPROC>(loader("glCreateBuffers"));
    oglCreateFramebuffers           = reinterpret_cast<PFNGLCREATEFRAMEBUFFERSPROC>(loader("glCreateFramebuffers"));
    oglCreateProgramPipelines       = reinterpret_cast<PFNGLCREATEPROGRAMPIPELINESPROC>(loader("glCreateProgramPipelines"));
    oglCreateQueries                = reinterpret_cast<PFNGLCREATEQUERIESPROC>(loader("glCreateQueries"));
    oglCreateRenderbuffers          = reinterpret_cast<PFNGLCREATERENDERBUFFERSPROC>(loader("glCreateRenderbuffers"));
    oglCreateSamplers               = reinterpret_cast<PFNGLCREATESAMPLERSPROC>(loader("glCreateSamplers"));
    oglCreateTextures               = reinterpret_cast<PFNGLCREATETEXTURESPROC>(loader("glCreateTextures"));
    oglCreateTransformFeedbacks     = reinterpret_cast<PFNGLCREATETRANSFORMFEEDBACKSPROC>(loader("glCreateTransformFeedbacks"));
    oglCreateVertexArrays           = reinterpret_cast<PFNGLCREATEVERTEXARRAYSPROC>(loader("glCreateVertexArrays"));
    oglDisableVertexArrayAttrib     = reinterpret_cast<PFNGLDISABLEVERTEXARRAYATTRIBPROC>(loader("glDisableVertexArrayAttrib"));
    oglEnableVertexArrayAttrib      = reinterpret_cast<PFNGLENABLEVERTEXARRAYATTRIBPROC>(loader("glEnableVertexArrayAttrib"));
    oglFlushMappedNamedBufferRange  = reinterpret_cast<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC>(loader("glFlushMappedNamedBufferRange"));
    oglGenerateTextureMipmap        = reinterpret_cast<PFNGLGENERATETEXTUREMIPMAPPROC>(loader("glGenerateTextureMipmap"));
    oglGetCompressedTextureImage    = reinterpret_cast<PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC>(loader("glGetCompressedTextureImage"));
    oglGetCompressedTextureSubImage = reinterpret_cast<PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC>(loader("glGetCompressedTextureSubImage"));
    oglGetGraphicsResetStatus       = reinterpret_cast<PFNGLGETGRAPHICSRESETSTATUSPROC>(loader("glGetGraphicsResetStatus"));
    oglGetNamedBufferParameteri64v  = reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERI64VPROC>(loader("glGetNamedBufferParameteri64v"));
    oglGetNamedBufferParameteriv    = reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERIVPROC>(loader("glGetNamedBufferParameteriv"));
    oglGetNamedBufferPointerv       = reinterpret_cast<PFNGLGETNAMEDBUFFERPOINTERVPROC>(loader("glGetNamedBufferPointerv"));
    oglGetNamedBufferSubData        = reinterpret_cast<PFNGLGETNAMEDBUFFERSUBDATAPROC>(loader("glGetNamedBufferSubData"));
    oglGetNamedFramebufferAttachmentParameteriv =
        reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(loader("glGetNamedFramebufferAttachmentParameteriv"));
    oglGetNamedFramebufferParameteriv      = reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC>(loader("glGetNamedFramebufferParameteriv"));
    oglGetNamedRenderbufferParameteriv     = reinterpret_cast<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC>(loader("glGetNamedRenderbufferParameteriv"));
    oglGetQueryBufferObjecti64v            = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTI64VPROC>(loader("glGetQueryBufferObjecti64v"));
    oglGetQueryBufferObjectiv              = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTIVPROC>(loader("glGetQueryBufferObjectiv"));
    oglGetQueryBufferObjectui64v           = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTUI64VPROC>(loader("glGetQueryBufferObjectui64v"));
    oglGetQueryBufferObjectuiv             = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTUIVPROC>(loader("glGetQueryBufferObjectuiv"));
    oglGetTextureImage                     = reinterpret_cast<PFNGLGETTEXTUREIMAGEPROC>(loader("glGetTextureImage"));
    oglGetTextureLevelParameterfv          = reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERFVPROC>(loader("glGetTextureLevelParameterfv"));
    oglGetTextureLevelParameteriv          = reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERIVPROC>(loader("glGetTextureLevelParameteriv"));
    oglGetTextureParameterIiv              = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIIVPROC>(loader("glGetTextureParameterIiv"));
    oglGetTextureParameterIuiv             = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIUIVPROC>(loader("glGetTextureParameterIuiv"));
    oglGetTextureParameterfv               = reinterpret_cast<PFNGLGETTEXTUREPARAMETERFVPROC>(loader("glGetTextureParameterfv"));
    oglGetTextureParameteriv               = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIVPROC>(loader("glGetTextureParameteriv"));
    oglGetTextureSubImage                  = reinterpret_cast<PFNGLGETTEXTURESUBIMAGEPROC>(loader("glGetTextureSubImage"));
    oglGetTransformFeedbacki64_v           = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI64_VPROC>(loader("glGetTransformFeedbacki64_v"));
    oglGetTransformFeedbacki_v             = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI_VPROC>(loader("glGetTransformFeedbacki_v"));
    oglGetTransformFeedbackiv              = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKIVPROC>(loader("glGetTransformFeedbackiv"));
    oglGetVertexArrayIndexed64iv           = reinterpret_cast<PFNGLGETVERTEXARRAYINDEXED64IVPROC>(loader("glGetVertexArrayIndexed64iv"));
    oglGetVertexArrayIndexediv             = reinterpret_cast<PFNGLGETVERTEXARRAYINDEXEDIVPROC>(loader("glGetVertexArrayIndexediv"));
    oglGetVertexArrayiv                    = reinterpret_cast<PFNGLGETVERTEXARRAYIVPROC>(loader("glGetVertexArrayiv"));
    oglGetnColorTable                      = reinterpret_cast<PFNGLGETNCOLORTABLEPROC>(loader("glGetnColorTable"));
    oglGetnCompressedTexImage              = reinterpret_cast<PFNGLGETNCOMPRESSEDTEXIMAGEPROC>(loader("glGetnCompressedTexImage"));
    oglGetnConvolutionFilter               = reinterpret_cast<PFNGLGETNCONVOLUTIONFILTERPROC>(loader("glGetnConvolutionFilter"));
    oglGetnHistogram                       = reinterpret_cast<PFNGLGETNHISTOGRAMPROC>(loader("glGetnHistogram"));
    oglGetnMapdv                           = reinterpret_cast<PFNGLGETNMAPDVPROC>(loader("glGetnMapdv"));
    oglGetnMapfv                           = reinterpret_cast<PFNGLGETNMAPFVPROC>(loader("glGetnMapfv"));
    oglGetnMapiv                           = reinterpret_cast<PFNGLGETNMAPIVPROC>(loader("glGetnMapiv"));
    oglGetnMinmax                          = reinterpret_cast<PFNGLGETNMINMAXPROC>(loader("glGetnMinmax"));
    oglGetnPixelMapfv                      = reinterpret_cast<PFNGLGETNPIXELMAPFVPROC>(loader("glGetnPixelMapfv"));
    oglGetnPixelMapuiv                     = reinterpret_cast<PFNGLGETNPIXELMAPUIVPROC>(loader("glGetnPixelMapuiv"));
    oglGetnPixelMapusv                     = reinterpret_cast<PFNGLGETNPIXELMAPUSVPROC>(loader("glGetnPixelMapusv"));
    oglGetnPolygonStipple                  = reinterpret_cast<PFNGLGETNPOLYGONSTIPPLEPROC>(loader("glGetnPolygonStipple"));
    oglGetnSeparableFilter                 = reinterpret_cast<PFNGLGETNSEPARABLEFILTERPROC>(loader("glGetnSeparableFilter"));
    oglGetnTexImage                        = reinterpret_cast<PFNGLGETNTEXIMAGEPROC>(loader("glGetnTexImage"));
    oglGetnUniformdv                       = reinterpret_cast<PFNGLGETNUNIFORMDVPROC>(loader("glGetnUniformdv"));
    oglGetnUniformfv                       = reinterpret_cast<PFNGLGETNUNIFORMFVPROC>(loader("glGetnUniformfv"));
    oglGetnUniformiv                       = reinterpret_cast<PFNGLGETNUNIFORMIVPROC>(loader("glGetnUniformiv"));
    oglGetnUniformuiv                      = reinterpret_cast<PFNGLGETNUNIFORMUIVPROC>(loader("glGetnUniformuiv"));
    oglInvalidateNamedFramebufferData      = reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC>(loader("glInvalidateNamedFramebufferData"));
    oglInvalidateNamedFramebufferSubData   = reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC>(loader("glInvalidateNamedFramebufferSubData"));
    oglMapNamedBufferRange                 = reinterpret_cast<PFNGLMAPNAMEDBUFFERRANGEPROC>(loader("glMapNamedBufferRange"));
    oglMapNamedBuffer                      = reinterpret_cast<PFNGLMAPNAMEDBUFFERPROC>(loader("glMapNamedBuffer"));
    oglMemoryBarrierByRegion               = reinterpret_cast<PFNGLMEMORYBARRIERBYREGIONPROC>(loader("glMemoryBarrierByRegion"));
    oglNamedBufferData                     = reinterpret_cast<PFNGLNAMEDBUFFERDATAPROC>(loader("glNamedBufferData"));
    oglNamedBufferStorage                  = reinterpret_cast<PFNGLNAMEDBUFFERSTORAGEPROC>(loader("glNamedBufferStorage"));
    oglNamedBufferSubData                  = reinterpret_cast<PFNGLNAMEDBUFFERSUBDATAPROC>(loader("glNamedBufferSubData"));
    oglNamedFramebufferDrawBuffers         = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC>(loader("glNamedFramebufferDrawBuffers"));
    oglNamedFramebufferDrawBuffer          = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC>(loader("glNamedFramebufferDrawBuffer"));
    oglNamedFramebufferParameteri          = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC>(loader("glNamedFramebufferParameteri"));
    oglNamedFramebufferReadBuffer          = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC>(loader("glNamedFramebufferReadBuffer"));
    oglNamedFramebufferRenderbuffer        = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC>(loader("glNamedFramebufferRenderbuffer"));
    oglNamedFramebufferTextureLayer        = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC>(loader("glNamedFramebufferTextureLayer"));
    oglNamedFramebufferTexture             = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTUREPROC>(loader("glNamedFramebufferTexture"));
    oglNamedRenderbufferStorageMultisample = reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC>(loader("glNamedRenderbufferStorageMultisample"));
    oglNamedRenderbufferStorage            = reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEPROC>(loader("glNamedRenderbufferStorage"));
    oglReadnPixels                         = reinterpret_cast<PFNGLREADNPIXELSPROC>(loader("glReadnPixels"));
    oglTextureBarrier                      = reinterpret_cast<PFNGLTEXTUREBARRIERPROC>(loader("glTextureBarrier"));
    oglTextureBufferRange                  = reinterpret_cast<PFNGLTEXTUREBUFFERRANGEPROC>(loader("glTextureBufferRange"));
    oglTextureBuffer                       = reinterpret_cast<PFNGLTEXTUREBUFFERPROC>(loader("glTextureBuffer"));
    oglTextureParameterIiv                 = reinterpret_cast<PFNGLTEXTUREPARAMETERIIVPROC>(loader("glTextureParameterIiv"));
    oglTextureParameterIuiv                = reinterpret_cast<PFNGLTEXTUREPARAMETERIUIVPROC>(loader("glTextureParameterIuiv"));
    oglTextureParameterfv                  = reinterpret_cast<PFNGLTEXTUREPARAMETERFVPROC>(loader("glTextureParameterfv"));
    oglTextureParameterf                   = reinterpret_cast<PFNGLTEXTUREPARAMETERFPROC>(loader("glTextureParameterf"));
    oglTextureParameteriv                  = reinterpret_cast<PFNGLTEXTUREPARAMETERIVPROC>(loader("glTextureParameteriv"));
    oglTextureParameteri                   = reinterpret_cast<PFNGLTEXTUREPARAMETERIPROC>(loader("glTextureParameteri"));
    oglTextureStorage1D                    = reinterpret_cast<PFNGLTEXTURESTORAGE1DPROC>(loader("glTextureStorage1D"));
    oglTextureStorage2DMultisample         = reinterpret_cast<PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC>(loader("glTextureStorage2DMultisample"));
    oglTextureStorage2D                    = reinterpret_cast<PFNGLTEXTURESTORAGE2DPROC>(loader("glTextureStorage2D"));
    oglTextureStorage3DMultisample         = reinterpret_cast<PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC>(loader("glTextureStorage3DMultisample"));
    oglTextureStorage3D                    = reinterpret_cast<PFNGLTEXTURESTORAGE3DPROC>(loader("glTextureStorage3D"));
    oglTextureSubImage1D                   = reinterpret_cast<PFNGLTEXTURESUBIMAGE1DPROC>(loader("glTextureSubImage1D"));
    oglTextureSubImage2D                   = reinterpret_cast<PFNGLTEXTURESUBIMAGE2DPROC>(loader("glTextureSubImage2D"));
    oglTextureSubImage3D                   = reinterpret_cast<PFNGLTEXTURESUBIMAGE3DPROC>(loader("glTextureSubImage3D"));
    oglTransformFeedbackBufferBase         = reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC>(loader("glTransformFeedbackBufferBase"));
    oglTransformFeedbackBufferRange        = reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC>(loader("glTransformFeedbackBufferRange"));
    oglUnmapNamedBuffer                    = reinterpret_cast<PFNGLUNMAPNAMEDBUFFERPROC>(loader("glUnmapNamedBuffer"));
    oglVertexArrayAttribBinding            = reinterpret_cast<PFNGLVERTEXARRAYATTRIBBINDINGPROC>(loader("glVertexArrayAttribBinding"));
    oglVertexArrayAttribFormat             = reinterpret_cast<PFNGLVERTEXARRAYATTRIBFORMATPROC>(loader("glVertexArrayAttribFormat"));
    oglVertexArrayAttribIFormat            = reinterpret_cast<PFNGLVERTEXARRAYATTRIBIFORMATPROC>(loader("glVertexArrayAttribIFormat"));
    oglVertexArrayAttribLFormat            = reinterpret_cast<PFNGLVERTEXARRAYATTRIBLFORMATPROC>(loader("glVertexArrayAttribLFormat"));
    oglVertexArrayBindingDivisor           = reinterpret_cast<PFNGLVERTEXARRAYBINDINGDIVISORPROC>(loader("glVertexArrayBindingDivisor"));
    oglVertexArrayElementBuffer            = reinterpret_cast<PFNGLVERTEXARRAYELEMENTBUFFERPROC>(loader("glVertexArrayElementBuffer"));
    oglVertexArrayVertexBuffers            = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERSPROC>(loader("glVertexArrayVertexBuffers"));
    oglVertexArrayVertexBuffer             = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERPROC>(loader("glVertexArrayVertexBuffer"));
}


} // namespace glr
} // namespace xg