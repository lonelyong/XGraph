#include <xg/glr/igl/GLfuncsv450.h>

namespace xg {
namespace glr {


GLfuncsv450::GLfuncsv450()
  : iglBindTextureUnit(nullptr)
  , iglBlitNamedFramebuffer(nullptr)
  , iglCheckNamedFramebufferStatus(nullptr)
  , iglClearNamedBufferData(nullptr)
  , iglClearNamedBufferSubData(nullptr)
  , iglClearNamedFramebufferfi(nullptr)
  , iglClearNamedFramebufferfv(nullptr)
  , iglClearNamedFramebufferiv(nullptr)
  , iglClearNamedFramebufferuiv(nullptr)
  , iglClipControl(nullptr)
  , iglCompressedTextureSubImage1D(nullptr)
  , iglCompressedTextureSubImage2D(nullptr)
  , iglCompressedTextureSubImage3D(nullptr)
  , iglCopyNamedBufferSubData(nullptr)
  , iglCopyTextureSubImage1D(nullptr)
  , iglCopyTextureSubImage2D(nullptr)
  , iglCopyTextureSubImage3D(nullptr)
  , iglCreateBuffers(nullptr)
  , iglCreateFramebuffers(nullptr)
  , iglCreateProgramPipelines(nullptr)
  , iglCreateQueries(nullptr)
  , iglCreateRenderbuffers(nullptr)
  , iglCreateSamplers(nullptr)
  , iglCreateTextures(nullptr)
  , iglCreateTransformFeedbacks(nullptr)
  , iglCreateVertexArrays(nullptr)
  , iglDisableVertexArrayAttrib(nullptr)
  , iglEnableVertexArrayAttrib(nullptr)
  , iglFlushMappedNamedBufferRange(nullptr)
  , iglGenerateTextureMipmap(nullptr)
  , iglGetCompressedTextureImage(nullptr)
  , iglGetCompressedTextureSubImage(nullptr)
  , iglGetGraphicsResetStatus(nullptr)
  , iglGetNamedBufferParameteri64v(nullptr)
  , iglGetNamedBufferParameteriv(nullptr)
  , iglGetNamedBufferPointerv(nullptr)
  , iglGetNamedBufferSubData(nullptr)
  , iglGetNamedFramebufferAttachmentParameteriv(nullptr)
  , iglGetNamedFramebufferParameteriv(nullptr)
  , iglGetNamedRenderbufferParameteriv(nullptr)
  , iglGetQueryBufferObjecti64v(nullptr)
  , iglGetQueryBufferObjectiv(nullptr)
  , iglGetQueryBufferObjectui64v(nullptr)
  , iglGetQueryBufferObjectuiv(nullptr)
  , iglGetTextureImage(nullptr)
  , iglGetTextureLevelParameterfv(nullptr)
  , iglGetTextureLevelParameteriv(nullptr)
  , iglGetTextureParameterIiv(nullptr)
  , iglGetTextureParameterIuiv(nullptr)
  , iglGetTextureParameterfv(nullptr)
  , iglGetTextureParameteriv(nullptr)
  , iglGetTextureSubImage(nullptr)
  , iglGetTransformFeedbacki64_v(nullptr)
  , iglGetTransformFeedbacki_v(nullptr)
  , iglGetTransformFeedbackiv(nullptr)
  , iglGetVertexArrayIndexed64iv(nullptr)
  , iglGetVertexArrayIndexediv(nullptr)
  , iglGetVertexArrayiv(nullptr)
  , iglGetnColorTable(nullptr)
  , iglGetnCompressedTexImage(nullptr)
  , iglGetnConvolutionFilter(nullptr)
  , iglGetnHistogram(nullptr)
  , iglGetnMapdv(nullptr)
  , iglGetnMapfv(nullptr)
  , iglGetnMapiv(nullptr)
  , iglGetnMinmax(nullptr)
  , iglGetnPixelMapfv(nullptr)
  , iglGetnPixelMapuiv(nullptr)
  , iglGetnPixelMapusv(nullptr)
  , iglGetnPolygonStipple(nullptr)
  , iglGetnSeparableFilter(nullptr)
  , iglGetnTexImage(nullptr)
  , iglGetnUniformdv(nullptr)
  , iglGetnUniformfv(nullptr)
  , iglGetnUniformiv(nullptr)
  , iglGetnUniformuiv(nullptr)
  , iglInvalidateNamedFramebufferData(nullptr)
  , iglInvalidateNamedFramebufferSubData(nullptr)
  , iglMapNamedBufferRange(nullptr)
  , iglMapNamedBuffer(nullptr)
  , iglMemoryBarrierByRegion(nullptr)
  , iglNamedBufferData(nullptr)
  , iglNamedBufferStorage(nullptr)
  , iglNamedBufferSubData(nullptr)
  , iglNamedFramebufferDrawBuffers(nullptr)
  , iglNamedFramebufferDrawBuffer(nullptr)
  , iglNamedFramebufferParameteri(nullptr)
  , iglNamedFramebufferReadBuffer(nullptr)
  , iglNamedFramebufferRenderbuffer(nullptr)
  , iglNamedFramebufferTextureLayer(nullptr)
  , iglNamedFramebufferTexture(nullptr)
  , iglNamedRenderbufferStorageMultisample(nullptr)
  , iglNamedRenderbufferStorage(nullptr)
  , iglReadnPixels(nullptr)
  , iglTextureBarrier(nullptr)
  , iglTextureBufferRange(nullptr)
  , iglTextureBuffer(nullptr)
  , iglTextureParameterIiv(nullptr)
  , iglTextureParameterIuiv(nullptr)
  , iglTextureParameterfv(nullptr)
  , iglTextureParameterf(nullptr)
  , iglTextureParameteriv(nullptr)
  , iglTextureParameteri(nullptr)
  , iglTextureStorage1D(nullptr)
  , iglTextureStorage2DMultisample(nullptr)
  , iglTextureStorage2D(nullptr)
  , iglTextureStorage3DMultisample(nullptr)
  , iglTextureStorage3D(nullptr)
  , iglTextureSubImage1D(nullptr)
  , iglTextureSubImage2D(nullptr)
  , iglTextureSubImage3D(nullptr)
  , iglTransformFeedbackBufferBase(nullptr)
  , iglTransformFeedbackBufferRange(nullptr)
  , iglUnmapNamedBuffer(nullptr)
  , iglVertexArrayAttribBinding(nullptr)
  , iglVertexArrayAttribFormat(nullptr)
  , iglVertexArrayAttribIFormat(nullptr)
  , iglVertexArrayAttribLFormat(nullptr)
  , iglVertexArrayBindingDivisor(nullptr)
  , iglVertexArrayElementBuffer(nullptr)
  , iglVertexArrayVertexBuffers(nullptr)
  , iglVertexArrayVertexBuffer(nullptr) {
}

void GLfuncsv450::loadFuncs(Loader loader) {
    GLfuncsv440::loadFuncs(loader);
    iglBindTextureUnit      = reinterpret_cast<PFNGLBINDTEXTUREUNITPROC>(loader("glBindTextureUnit"));
    iglBlitNamedFramebuffer = reinterpret_cast<PFNGLBLITNAMEDFRAMEBUFFERPROC>(loader("glBlitNamedFramebuffer"));
    iglCheckNamedFramebufferStatus =
        reinterpret_cast<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC>(loader("glCheckNamedFramebufferStatus"));
    iglClearNamedBufferData    = reinterpret_cast<PFNGLCLEARNAMEDBUFFERDATAPROC>(loader("glClearNamedBufferData"));
    iglClearNamedBufferSubData = reinterpret_cast<PFNGLCLEARNAMEDBUFFERSUBDATAPROC>(loader("glClearNamedBufferSubData"));
    iglClearNamedFramebufferfi = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFIPROC>(loader("glClearNamedFramebufferfi"));
    iglClearNamedFramebufferfv = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFVPROC>(loader("glClearNamedFramebufferfv"));
    iglClearNamedFramebufferiv = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERIVPROC>(loader("glClearNamedFramebufferiv"));
    iglClearNamedFramebufferuiv =
        reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC>(loader("glClearNamedFramebufferuiv"));
    iglClipControl = reinterpret_cast<PFNGLCLIPCONTROLPROC>(loader("glClipControl"));
    iglCompressedTextureSubImage1D =
        reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC>(loader("glCompressedTextureSubImage1D"));
    iglCompressedTextureSubImage2D =
        reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC>(loader("glCompressedTextureSubImage2D"));
    iglCompressedTextureSubImage3D =
        reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC>(loader("glCompressedTextureSubImage3D"));
    iglCopyNamedBufferSubData = reinterpret_cast<PFNGLCOPYNAMEDBUFFERSUBDATAPROC>(loader("glCopyNamedBufferSubData"));
    iglCopyTextureSubImage1D  = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE1DPROC>(loader("glCopyTextureSubImage1D"));
    iglCopyTextureSubImage2D  = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE2DPROC>(loader("glCopyTextureSubImage2D"));
    iglCopyTextureSubImage3D  = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE3DPROC>(loader("glCopyTextureSubImage3D"));
    iglCreateBuffers          = reinterpret_cast<PFNGLCREATEBUFFERSPROC>(loader("glCreateBuffers"));
    iglCreateFramebuffers     = reinterpret_cast<PFNGLCREATEFRAMEBUFFERSPROC>(loader("glCreateFramebuffers"));
    iglCreateProgramPipelines = reinterpret_cast<PFNGLCREATEPROGRAMPIPELINESPROC>(loader("glCreateProgramPipelines"));
    iglCreateQueries          = reinterpret_cast<PFNGLCREATEQUERIESPROC>(loader("glCreateQueries"));
    iglCreateRenderbuffers    = reinterpret_cast<PFNGLCREATERENDERBUFFERSPROC>(loader("glCreateRenderbuffers"));
    iglCreateSamplers         = reinterpret_cast<PFNGLCREATESAMPLERSPROC>(loader("glCreateSamplers"));
    iglCreateTextures         = reinterpret_cast<PFNGLCREATETEXTURESPROC>(loader("glCreateTextures"));
    iglCreateTransformFeedbacks =
        reinterpret_cast<PFNGLCREATETRANSFORMFEEDBACKSPROC>(loader("glCreateTransformFeedbacks"));
    iglCreateVertexArrays = reinterpret_cast<PFNGLCREATEVERTEXARRAYSPROC>(loader("glCreateVertexArrays"));
    iglDisableVertexArrayAttrib =
        reinterpret_cast<PFNGLDISABLEVERTEXARRAYATTRIBPROC>(loader("glDisableVertexArrayAttrib"));
    iglEnableVertexArrayAttrib = reinterpret_cast<PFNGLENABLEVERTEXARRAYATTRIBPROC>(loader("glEnableVertexArrayAttrib"));
    iglFlushMappedNamedBufferRange =
        reinterpret_cast<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC>(loader("glFlushMappedNamedBufferRange"));
    iglGenerateTextureMipmap = reinterpret_cast<PFNGLGENERATETEXTUREMIPMAPPROC>(loader("glGenerateTextureMipmap"));
    iglGetCompressedTextureImage =
        reinterpret_cast<PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC>(loader("glGetCompressedTextureImage"));
    iglGetCompressedTextureSubImage =
        reinterpret_cast<PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC>(loader("glGetCompressedTextureSubImage"));
    iglGetGraphicsResetStatus = reinterpret_cast<PFNGLGETGRAPHICSRESETSTATUSPROC>(loader("glGetGraphicsResetStatus"));
    iglGetNamedBufferParameteri64v =
        reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERI64VPROC>(loader("glGetNamedBufferParameteri64v"));
    iglGetNamedBufferParameteriv =
        reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERIVPROC>(loader("glGetNamedBufferParameteriv"));
    iglGetNamedBufferPointerv = reinterpret_cast<PFNGLGETNAMEDBUFFERPOINTERVPROC>(loader("glGetNamedBufferPointerv"));
    iglGetNamedBufferSubData  = reinterpret_cast<PFNGLGETNAMEDBUFFERSUBDATAPROC>(loader("glGetNamedBufferSubData"));
    iglGetNamedFramebufferAttachmentParameteriv = reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(
        loader("glGetNamedFramebufferAttachmentParameteriv"));
    iglGetNamedFramebufferParameteriv =
        reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC>(loader("glGetNamedFramebufferParameteriv"));
    iglGetNamedRenderbufferParameteriv =
        reinterpret_cast<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC>(loader("glGetNamedRenderbufferParameteriv"));
    iglGetQueryBufferObjecti64v =
        reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTI64VPROC>(loader("glGetQueryBufferObjecti64v"));
    iglGetQueryBufferObjectiv = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTIVPROC>(loader("glGetQueryBufferObjectiv"));
    iglGetQueryBufferObjectui64v =
        reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTUI64VPROC>(loader("glGetQueryBufferObjectui64v"));
    iglGetQueryBufferObjectuiv = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTUIVPROC>(loader("glGetQueryBufferObjectuiv"));
    iglGetTextureImage         = reinterpret_cast<PFNGLGETTEXTUREIMAGEPROC>(loader("glGetTextureImage"));
    iglGetTextureLevelParameterfv =
        reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERFVPROC>(loader("glGetTextureLevelParameterfv"));
    iglGetTextureLevelParameteriv =
        reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERIVPROC>(loader("glGetTextureLevelParameteriv"));
    iglGetTextureParameterIiv  = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIIVPROC>(loader("glGetTextureParameterIiv"));
    iglGetTextureParameterIuiv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIUIVPROC>(loader("glGetTextureParameterIuiv"));
    iglGetTextureParameterfv   = reinterpret_cast<PFNGLGETTEXTUREPARAMETERFVPROC>(loader("glGetTextureParameterfv"));
    iglGetTextureParameteriv   = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIVPROC>(loader("glGetTextureParameteriv"));
    iglGetTextureSubImage      = reinterpret_cast<PFNGLGETTEXTURESUBIMAGEPROC>(loader("glGetTextureSubImage"));
    iglGetTransformFeedbacki64_v =
        reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI64_VPROC>(loader("glGetTransformFeedbacki64_v"));
    iglGetTransformFeedbacki_v = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI_VPROC>(loader("glGetTransformFeedbacki_v"));
    iglGetTransformFeedbackiv  = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKIVPROC>(loader("glGetTransformFeedbackiv"));
    iglGetVertexArrayIndexed64iv =
        reinterpret_cast<PFNGLGETVERTEXARRAYINDEXED64IVPROC>(loader("glGetVertexArrayIndexed64iv"));
    iglGetVertexArrayIndexediv = reinterpret_cast<PFNGLGETVERTEXARRAYINDEXEDIVPROC>(loader("glGetVertexArrayIndexediv"));
    iglGetVertexArrayiv        = reinterpret_cast<PFNGLGETVERTEXARRAYIVPROC>(loader("glGetVertexArrayiv"));
    iglGetnColorTable          = reinterpret_cast<PFNGLGETNCOLORTABLEPROC>(loader("glGetnColorTable"));
    iglGetnCompressedTexImage  = reinterpret_cast<PFNGLGETNCOMPRESSEDTEXIMAGEPROC>(loader("glGetnCompressedTexImage"));
    iglGetnConvolutionFilter   = reinterpret_cast<PFNGLGETNCONVOLUTIONFILTERPROC>(loader("glGetnConvolutionFilter"));
    iglGetnHistogram           = reinterpret_cast<PFNGLGETNHISTOGRAMPROC>(loader("glGetnHistogram"));
    iglGetnMapdv               = reinterpret_cast<PFNGLGETNMAPDVPROC>(loader("glGetnMapdv"));
    iglGetnMapfv               = reinterpret_cast<PFNGLGETNMAPFVPROC>(loader("glGetnMapfv"));
    iglGetnMapiv               = reinterpret_cast<PFNGLGETNMAPIVPROC>(loader("glGetnMapiv"));
    iglGetnMinmax              = reinterpret_cast<PFNGLGETNMINMAXPROC>(loader("glGetnMinmax"));
    iglGetnPixelMapfv          = reinterpret_cast<PFNGLGETNPIXELMAPFVPROC>(loader("glGetnPixelMapfv"));
    iglGetnPixelMapuiv         = reinterpret_cast<PFNGLGETNPIXELMAPUIVPROC>(loader("glGetnPixelMapuiv"));
    iglGetnPixelMapusv         = reinterpret_cast<PFNGLGETNPIXELMAPUSVPROC>(loader("glGetnPixelMapusv"));
    iglGetnPolygonStipple      = reinterpret_cast<PFNGLGETNPOLYGONSTIPPLEPROC>(loader("glGetnPolygonStipple"));
    iglGetnSeparableFilter     = reinterpret_cast<PFNGLGETNSEPARABLEFILTERPROC>(loader("glGetnSeparableFilter"));
    iglGetnTexImage            = reinterpret_cast<PFNGLGETNTEXIMAGEPROC>(loader("glGetnTexImage"));
    iglGetnUniformdv           = reinterpret_cast<PFNGLGETNUNIFORMDVPROC>(loader("glGetnUniformdv"));
    iglGetnUniformfv           = reinterpret_cast<PFNGLGETNUNIFORMFVPROC>(loader("glGetnUniformfv"));
    iglGetnUniformiv           = reinterpret_cast<PFNGLGETNUNIFORMIVPROC>(loader("glGetnUniformiv"));
    iglGetnUniformuiv          = reinterpret_cast<PFNGLGETNUNIFORMUIVPROC>(loader("glGetnUniformuiv"));
    iglInvalidateNamedFramebufferData =
        reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC>(loader("glInvalidateNamedFramebufferData"));
    iglInvalidateNamedFramebufferSubData =
        reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC>(loader("glInvalidateNamedFramebufferSubData"));
    iglMapNamedBufferRange   = reinterpret_cast<PFNGLMAPNAMEDBUFFERRANGEPROC>(loader("glMapNamedBufferRange"));
    iglMapNamedBuffer        = reinterpret_cast<PFNGLMAPNAMEDBUFFERPROC>(loader("glMapNamedBuffer"));
    iglMemoryBarrierByRegion = reinterpret_cast<PFNGLMEMORYBARRIERBYREGIONPROC>(loader("glMemoryBarrierByRegion"));
    iglNamedBufferData       = reinterpret_cast<PFNGLNAMEDBUFFERDATAPROC>(loader("glNamedBufferData"));
    iglNamedBufferStorage    = reinterpret_cast<PFNGLNAMEDBUFFERSTORAGEPROC>(loader("glNamedBufferStorage"));
    iglNamedBufferSubData    = reinterpret_cast<PFNGLNAMEDBUFFERSUBDATAPROC>(loader("glNamedBufferSubData"));
    iglNamedFramebufferDrawBuffers =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC>(loader("glNamedFramebufferDrawBuffers"));
    iglNamedFramebufferDrawBuffer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC>(loader("glNamedFramebufferDrawBuffer"));
    iglNamedFramebufferParameteri =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC>(loader("glNamedFramebufferParameteri"));
    iglNamedFramebufferReadBuffer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC>(loader("glNamedFramebufferReadBuffer"));
    iglNamedFramebufferRenderbuffer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC>(loader("glNamedFramebufferRenderbuffer"));
    iglNamedFramebufferTextureLayer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC>(loader("glNamedFramebufferTextureLayer"));
    iglNamedFramebufferTexture = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTUREPROC>(loader("glNamedFramebufferTexture"));
    iglNamedRenderbufferStorageMultisample =
        reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC>(loader("glNamedRenderbufferStorageMultisample"));
    iglNamedRenderbufferStorage =
        reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEPROC>(loader("glNamedRenderbufferStorage"));
    iglReadnPixels          = reinterpret_cast<PFNGLREADNPIXELSPROC>(loader("glReadnPixels"));
    iglTextureBarrier       = reinterpret_cast<PFNGLTEXTUREBARRIERPROC>(loader("glTextureBarrier"));
    iglTextureBufferRange   = reinterpret_cast<PFNGLTEXTUREBUFFERRANGEPROC>(loader("glTextureBufferRange"));
    iglTextureBuffer        = reinterpret_cast<PFNGLTEXTUREBUFFERPROC>(loader("glTextureBuffer"));
    iglTextureParameterIiv  = reinterpret_cast<PFNGLTEXTUREPARAMETERIIVPROC>(loader("glTextureParameterIiv"));
    iglTextureParameterIuiv = reinterpret_cast<PFNGLTEXTUREPARAMETERIUIVPROC>(loader("glTextureParameterIuiv"));
    iglTextureParameterfv   = reinterpret_cast<PFNGLTEXTUREPARAMETERFVPROC>(loader("glTextureParameterfv"));
    iglTextureParameterf    = reinterpret_cast<PFNGLTEXTUREPARAMETERFPROC>(loader("glTextureParameterf"));
    iglTextureParameteriv   = reinterpret_cast<PFNGLTEXTUREPARAMETERIVPROC>(loader("glTextureParameteriv"));
    iglTextureParameteri    = reinterpret_cast<PFNGLTEXTUREPARAMETERIPROC>(loader("glTextureParameteri"));
    iglTextureStorage1D     = reinterpret_cast<PFNGLTEXTURESTORAGE1DPROC>(loader("glTextureStorage1D"));
    iglTextureStorage2DMultisample =
        reinterpret_cast<PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC>(loader("glTextureStorage2DMultisample"));
    iglTextureStorage2D = reinterpret_cast<PFNGLTEXTURESTORAGE2DPROC>(loader("glTextureStorage2D"));
    iglTextureStorage3DMultisample =
        reinterpret_cast<PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC>(loader("glTextureStorage3DMultisample"));
    iglTextureStorage3D  = reinterpret_cast<PFNGLTEXTURESTORAGE3DPROC>(loader("glTextureStorage3D"));
    iglTextureSubImage1D = reinterpret_cast<PFNGLTEXTURESUBIMAGE1DPROC>(loader("glTextureSubImage1D"));
    iglTextureSubImage2D = reinterpret_cast<PFNGLTEXTURESUBIMAGE2DPROC>(loader("glTextureSubImage2D"));
    iglTextureSubImage3D = reinterpret_cast<PFNGLTEXTURESUBIMAGE3DPROC>(loader("glTextureSubImage3D"));
    iglTransformFeedbackBufferBase =
        reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC>(loader("glTransformFeedbackBufferBase"));
    iglTransformFeedbackBufferRange =
        reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC>(loader("glTransformFeedbackBufferRange"));
    iglUnmapNamedBuffer = reinterpret_cast<PFNGLUNMAPNAMEDBUFFERPROC>(loader("glUnmapNamedBuffer"));
    iglVertexArrayAttribBinding =
        reinterpret_cast<PFNGLVERTEXARRAYATTRIBBINDINGPROC>(loader("glVertexArrayAttribBinding"));
    iglVertexArrayAttribFormat = reinterpret_cast<PFNGLVERTEXARRAYATTRIBFORMATPROC>(loader("glVertexArrayAttribFormat"));
    iglVertexArrayAttribIFormat =
        reinterpret_cast<PFNGLVERTEXARRAYATTRIBIFORMATPROC>(loader("glVertexArrayAttribIFormat"));
    iglVertexArrayAttribLFormat =
        reinterpret_cast<PFNGLVERTEXARRAYATTRIBLFORMATPROC>(loader("glVertexArrayAttribLFormat"));
    iglVertexArrayBindingDivisor =
        reinterpret_cast<PFNGLVERTEXARRAYBINDINGDIVISORPROC>(loader("glVertexArrayBindingDivisor"));
    iglVertexArrayElementBuffer =
        reinterpret_cast<PFNGLVERTEXARRAYELEMENTBUFFERPROC>(loader("glVertexArrayElementBuffer"));
    iglVertexArrayVertexBuffers =
        reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERSPROC>(loader("glVertexArrayVertexBuffers"));
    iglVertexArrayVertexBuffer = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERPROC>(loader("glVertexArrayVertexBuffer"));
}


} // namespace glr
} // namespace xg