#include "GLfuncsv450.h"

namespace glr {

VI_OBJECT_META_IMPL(GLfuncsv450, GLfuncsv440);

GLfuncsv450::GLfuncsv450()
  : glBindTextureUnit(nullptr)
  , glBlitNamedFramebuffer(nullptr)
  , glCheckNamedFramebufferStatus(nullptr)
  , glClearNamedBufferData(nullptr)
  , glClearNamedBufferSubData(nullptr)
  , glClearNamedFramebufferfi(nullptr)
  , glClearNamedFramebufferfv(nullptr)
  , glClearNamedFramebufferiv(nullptr)
  , glClearNamedFramebufferuiv(nullptr)
  , glClipControl(nullptr)
  , glCompressedTextureSubImage1D(nullptr)
  , glCompressedTextureSubImage2D(nullptr)
  , glCompressedTextureSubImage3D(nullptr)
  , glCopyNamedBufferSubData(nullptr)
  , glCopyTextureSubImage1D(nullptr)
  , glCopyTextureSubImage2D(nullptr)
  , glCopyTextureSubImage3D(nullptr)
  , glCreateBuffers(nullptr)
  , glCreateFramebuffers(nullptr)
  , glCreateProgramPipelines(nullptr)
  , glCreateQueries(nullptr)
  , glCreateRenderbuffers(nullptr)
  , glCreateSamplers(nullptr)
  , glCreateTextures(nullptr)
  , glCreateTransformFeedbacks(nullptr)
  , glCreateVertexArrays(nullptr)
  , glDisableVertexArrayAttrib(nullptr)
  , glEnableVertexArrayAttrib(nullptr)
  , glFlushMappedNamedBufferRange(nullptr)
  , glGenerateTextureMipmap(nullptr)
  , glGetCompressedTextureImage(nullptr)
  , glGetCompressedTextureSubImage(nullptr)
  , glGetGraphicsResetStatus(nullptr)
  , glGetNamedBufferParameteri64v(nullptr)
  , glGetNamedBufferParameteriv(nullptr)
  , glGetNamedBufferPointerv(nullptr)
  , glGetNamedBufferSubData(nullptr)
  , glGetNamedFramebufferAttachmentParameteriv(nullptr)
  , glGetNamedFramebufferParameteriv(nullptr)
  , glGetNamedRenderbufferParameteriv(nullptr)
  , glGetQueryBufferObjecti64v(nullptr)
  , glGetQueryBufferObjectiv(nullptr)
  , glGetQueryBufferObjectui64v(nullptr)
  , glGetQueryBufferObjectuiv(nullptr)
  , glGetTextureImage(nullptr)
  , glGetTextureLevelParameterfv(nullptr)
  , glGetTextureLevelParameteriv(nullptr)
  , glGetTextureParameterIiv(nullptr)
  , glGetTextureParameterIuiv(nullptr)
  , glGetTextureParameterfv(nullptr)
  , glGetTextureParameteriv(nullptr)
  , glGetTextureSubImage(nullptr)
  , glGetTransformFeedbacki64_v(nullptr)
  , glGetTransformFeedbacki_v(nullptr)
  , glGetTransformFeedbackiv(nullptr)
  , glGetVertexArrayIndexed64iv(nullptr)
  , glGetVertexArrayIndexediv(nullptr)
  , glGetVertexArrayiv(nullptr)
  , glGetnColorTable(nullptr)
  , glGetnCompressedTexImage(nullptr)
  , glGetnConvolutionFilter(nullptr)
  , glGetnHistogram(nullptr)
  , glGetnMapdv(nullptr)
  , glGetnMapfv(nullptr)
  , glGetnMapiv(nullptr)
  , glGetnMinmax(nullptr)
  , glGetnPixelMapfv(nullptr)
  , glGetnPixelMapuiv(nullptr)
  , glGetnPixelMapusv(nullptr)
  , glGetnPolygonStipple(nullptr)
  , glGetnSeparableFilter(nullptr)
  , glGetnTexImage(nullptr)
  , glGetnUniformdv(nullptr)
  , glGetnUniformfv(nullptr)
  , glGetnUniformiv(nullptr)
  , glGetnUniformuiv(nullptr)
  , glInvalidateNamedFramebufferData(nullptr)
  , glInvalidateNamedFramebufferSubData(nullptr)
  , glMapNamedBufferRange(nullptr)
  , glMapNamedBuffer(nullptr)
  , glMemoryBarrierByRegion(nullptr)
  , glNamedBufferData(nullptr)
  , glNamedBufferStorage(nullptr)
  , glNamedBufferSubData(nullptr)
  , glNamedFramebufferDrawBuffers(nullptr)
  , glNamedFramebufferDrawBuffer(nullptr)
  , glNamedFramebufferParameteri(nullptr)
  , glNamedFramebufferReadBuffer(nullptr)
  , glNamedFramebufferRenderbuffer(nullptr)
  , glNamedFramebufferTextureLayer(nullptr)
  , glNamedFramebufferTexture(nullptr)
  , glNamedRenderbufferStorageMultisample(nullptr)
  , glNamedRenderbufferStorage(nullptr)
  , glReadnPixels(nullptr)
  , glTextureBarrier(nullptr)
  , glTextureBufferRange(nullptr)
  , glTextureBuffer(nullptr)
  , glTextureParameterIiv(nullptr)
  , glTextureParameterIuiv(nullptr)
  , glTextureParameterfv(nullptr)
  , glTextureParameterf(nullptr)
  , glTextureParameteriv(nullptr)
  , glTextureParameteri(nullptr)
  , glTextureStorage1D(nullptr)
  , glTextureStorage2DMultisample(nullptr)
  , glTextureStorage2D(nullptr)
  , glTextureStorage3DMultisample(nullptr)
  , glTextureStorage3D(nullptr)
  , glTextureSubImage1D(nullptr)
  , glTextureSubImage2D(nullptr)
  , glTextureSubImage3D(nullptr)
  , glTransformFeedbackBufferBase(nullptr)
  , glTransformFeedbackBufferRange(nullptr)
  , glUnmapNamedBuffer(nullptr)
  , glVertexArrayAttribBinding(nullptr)
  , glVertexArrayAttribFormat(nullptr)
  , glVertexArrayAttribIFormat(nullptr)
  , glVertexArrayAttribLFormat(nullptr)
  , glVertexArrayBindingDivisor(nullptr)
  , glVertexArrayElementBuffer(nullptr)
  , glVertexArrayVertexBuffers(nullptr)
  , glVertexArrayVertexBuffer(nullptr) {
}

void GLfuncsv450::loadFuncs(Loader loader) {
    GLfuncsv440::loadFuncs(loader);
    glBindTextureUnit      = reinterpret_cast<PFNGLBINDTEXTUREUNITPROC>(loader("glBindTextureUnit"));
    glBlitNamedFramebuffer = reinterpret_cast<PFNGLBLITNAMEDFRAMEBUFFERPROC>(loader("glBlitNamedFramebuffer"));
    glCheckNamedFramebufferStatus =
        reinterpret_cast<PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC>(loader("glCheckNamedFramebufferStatus"));
    glClearNamedBufferData    = reinterpret_cast<PFNGLCLEARNAMEDBUFFERDATAPROC>(loader("glClearNamedBufferData"));
    glClearNamedBufferSubData = reinterpret_cast<PFNGLCLEARNAMEDBUFFERSUBDATAPROC>(loader("glClearNamedBufferSubData"));
    glClearNamedFramebufferfi = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFIPROC>(loader("glClearNamedFramebufferfi"));
    glClearNamedFramebufferfv = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERFVPROC>(loader("glClearNamedFramebufferfv"));
    glClearNamedFramebufferiv = reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERIVPROC>(loader("glClearNamedFramebufferiv"));
    glClearNamedFramebufferuiv =
        reinterpret_cast<PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC>(loader("glClearNamedFramebufferuiv"));
    glClipControl = reinterpret_cast<PFNGLCLIPCONTROLPROC>(loader("glClipControl"));
    glCompressedTextureSubImage1D =
        reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC>(loader("glCompressedTextureSubImage1D"));
    glCompressedTextureSubImage2D =
        reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC>(loader("glCompressedTextureSubImage2D"));
    glCompressedTextureSubImage3D =
        reinterpret_cast<PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC>(loader("glCompressedTextureSubImage3D"));
    glCopyNamedBufferSubData = reinterpret_cast<PFNGLCOPYNAMEDBUFFERSUBDATAPROC>(loader("glCopyNamedBufferSubData"));
    glCopyTextureSubImage1D  = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE1DPROC>(loader("glCopyTextureSubImage1D"));
    glCopyTextureSubImage2D  = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE2DPROC>(loader("glCopyTextureSubImage2D"));
    glCopyTextureSubImage3D  = reinterpret_cast<PFNGLCOPYTEXTURESUBIMAGE3DPROC>(loader("glCopyTextureSubImage3D"));
    glCreateBuffers          = reinterpret_cast<PFNGLCREATEBUFFERSPROC>(loader("glCreateBuffers"));
    glCreateFramebuffers     = reinterpret_cast<PFNGLCREATEFRAMEBUFFERSPROC>(loader("glCreateFramebuffers"));
    glCreateProgramPipelines = reinterpret_cast<PFNGLCREATEPROGRAMPIPELINESPROC>(loader("glCreateProgramPipelines"));
    glCreateQueries          = reinterpret_cast<PFNGLCREATEQUERIESPROC>(loader("glCreateQueries"));
    glCreateRenderbuffers    = reinterpret_cast<PFNGLCREATERENDERBUFFERSPROC>(loader("glCreateRenderbuffers"));
    glCreateSamplers         = reinterpret_cast<PFNGLCREATESAMPLERSPROC>(loader("glCreateSamplers"));
    glCreateTextures         = reinterpret_cast<PFNGLCREATETEXTURESPROC>(loader("glCreateTextures"));
    glCreateTransformFeedbacks =
        reinterpret_cast<PFNGLCREATETRANSFORMFEEDBACKSPROC>(loader("glCreateTransformFeedbacks"));
    glCreateVertexArrays = reinterpret_cast<PFNGLCREATEVERTEXARRAYSPROC>(loader("glCreateVertexArrays"));
    glDisableVertexArrayAttrib =
        reinterpret_cast<PFNGLDISABLEVERTEXARRAYATTRIBPROC>(loader("glDisableVertexArrayAttrib"));
    glEnableVertexArrayAttrib = reinterpret_cast<PFNGLENABLEVERTEXARRAYATTRIBPROC>(loader("glEnableVertexArrayAttrib"));
    glFlushMappedNamedBufferRange =
        reinterpret_cast<PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC>(loader("glFlushMappedNamedBufferRange"));
    glGenerateTextureMipmap = reinterpret_cast<PFNGLGENERATETEXTUREMIPMAPPROC>(loader("glGenerateTextureMipmap"));
    glGetCompressedTextureImage =
        reinterpret_cast<PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC>(loader("glGetCompressedTextureImage"));
    glGetCompressedTextureSubImage =
        reinterpret_cast<PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC>(loader("glGetCompressedTextureSubImage"));
    glGetGraphicsResetStatus = reinterpret_cast<PFNGLGETGRAPHICSRESETSTATUSPROC>(loader("glGetGraphicsResetStatus"));
    glGetNamedBufferParameteri64v =
        reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERI64VPROC>(loader("glGetNamedBufferParameteri64v"));
    glGetNamedBufferParameteriv =
        reinterpret_cast<PFNGLGETNAMEDBUFFERPARAMETERIVPROC>(loader("glGetNamedBufferParameteriv"));
    glGetNamedBufferPointerv = reinterpret_cast<PFNGLGETNAMEDBUFFERPOINTERVPROC>(loader("glGetNamedBufferPointerv"));
    glGetNamedBufferSubData  = reinterpret_cast<PFNGLGETNAMEDBUFFERSUBDATAPROC>(loader("glGetNamedBufferSubData"));
    glGetNamedFramebufferAttachmentParameteriv = reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC>(
        loader("glGetNamedFramebufferAttachmentParameteriv"));
    glGetNamedFramebufferParameteriv =
        reinterpret_cast<PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC>(loader("glGetNamedFramebufferParameteriv"));
    glGetNamedRenderbufferParameteriv =
        reinterpret_cast<PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC>(loader("glGetNamedRenderbufferParameteriv"));
    glGetQueryBufferObjecti64v =
        reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTI64VPROC>(loader("glGetQueryBufferObjecti64v"));
    glGetQueryBufferObjectiv = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTIVPROC>(loader("glGetQueryBufferObjectiv"));
    glGetQueryBufferObjectui64v =
        reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTUI64VPROC>(loader("glGetQueryBufferObjectui64v"));
    glGetQueryBufferObjectuiv = reinterpret_cast<PFNGLGETQUERYBUFFEROBJECTUIVPROC>(loader("glGetQueryBufferObjectuiv"));
    glGetTextureImage         = reinterpret_cast<PFNGLGETTEXTUREIMAGEPROC>(loader("glGetTextureImage"));
    glGetTextureLevelParameterfv =
        reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERFVPROC>(loader("glGetTextureLevelParameterfv"));
    glGetTextureLevelParameteriv =
        reinterpret_cast<PFNGLGETTEXTURELEVELPARAMETERIVPROC>(loader("glGetTextureLevelParameteriv"));
    glGetTextureParameterIiv  = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIIVPROC>(loader("glGetTextureParameterIiv"));
    glGetTextureParameterIuiv = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIUIVPROC>(loader("glGetTextureParameterIuiv"));
    glGetTextureParameterfv   = reinterpret_cast<PFNGLGETTEXTUREPARAMETERFVPROC>(loader("glGetTextureParameterfv"));
    glGetTextureParameteriv   = reinterpret_cast<PFNGLGETTEXTUREPARAMETERIVPROC>(loader("glGetTextureParameteriv"));
    glGetTextureSubImage      = reinterpret_cast<PFNGLGETTEXTURESUBIMAGEPROC>(loader("glGetTextureSubImage"));
    glGetTransformFeedbacki64_v =
        reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI64_VPROC>(loader("glGetTransformFeedbacki64_v"));
    glGetTransformFeedbacki_v = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKI_VPROC>(loader("glGetTransformFeedbacki_v"));
    glGetTransformFeedbackiv  = reinterpret_cast<PFNGLGETTRANSFORMFEEDBACKIVPROC>(loader("glGetTransformFeedbackiv"));
    glGetVertexArrayIndexed64iv =
        reinterpret_cast<PFNGLGETVERTEXARRAYINDEXED64IVPROC>(loader("glGetVertexArrayIndexed64iv"));
    glGetVertexArrayIndexediv = reinterpret_cast<PFNGLGETVERTEXARRAYINDEXEDIVPROC>(loader("glGetVertexArrayIndexediv"));
    glGetVertexArrayiv        = reinterpret_cast<PFNGLGETVERTEXARRAYIVPROC>(loader("glGetVertexArrayiv"));
    glGetnColorTable          = reinterpret_cast<PFNGLGETNCOLORTABLEPROC>(loader("glGetnColorTable"));
    glGetnCompressedTexImage  = reinterpret_cast<PFNGLGETNCOMPRESSEDTEXIMAGEPROC>(loader("glGetnCompressedTexImage"));
    glGetnConvolutionFilter   = reinterpret_cast<PFNGLGETNCONVOLUTIONFILTERPROC>(loader("glGetnConvolutionFilter"));
    glGetnHistogram           = reinterpret_cast<PFNGLGETNHISTOGRAMPROC>(loader("glGetnHistogram"));
    glGetnMapdv               = reinterpret_cast<PFNGLGETNMAPDVPROC>(loader("glGetnMapdv"));
    glGetnMapfv               = reinterpret_cast<PFNGLGETNMAPFVPROC>(loader("glGetnMapfv"));
    glGetnMapiv               = reinterpret_cast<PFNGLGETNMAPIVPROC>(loader("glGetnMapiv"));
    glGetnMinmax              = reinterpret_cast<PFNGLGETNMINMAXPROC>(loader("glGetnMinmax"));
    glGetnPixelMapfv          = reinterpret_cast<PFNGLGETNPIXELMAPFVPROC>(loader("glGetnPixelMapfv"));
    glGetnPixelMapuiv         = reinterpret_cast<PFNGLGETNPIXELMAPUIVPROC>(loader("glGetnPixelMapuiv"));
    glGetnPixelMapusv         = reinterpret_cast<PFNGLGETNPIXELMAPUSVPROC>(loader("glGetnPixelMapusv"));
    glGetnPolygonStipple      = reinterpret_cast<PFNGLGETNPOLYGONSTIPPLEPROC>(loader("glGetnPolygonStipple"));
    glGetnSeparableFilter     = reinterpret_cast<PFNGLGETNSEPARABLEFILTERPROC>(loader("glGetnSeparableFilter"));
    glGetnTexImage            = reinterpret_cast<PFNGLGETNTEXIMAGEPROC>(loader("glGetnTexImage"));
    glGetnUniformdv           = reinterpret_cast<PFNGLGETNUNIFORMDVPROC>(loader("glGetnUniformdv"));
    glGetnUniformfv           = reinterpret_cast<PFNGLGETNUNIFORMFVPROC>(loader("glGetnUniformfv"));
    glGetnUniformiv           = reinterpret_cast<PFNGLGETNUNIFORMIVPROC>(loader("glGetnUniformiv"));
    glGetnUniformuiv          = reinterpret_cast<PFNGLGETNUNIFORMUIVPROC>(loader("glGetnUniformuiv"));
    glInvalidateNamedFramebufferData =
        reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC>(loader("glInvalidateNamedFramebufferData"));
    glInvalidateNamedFramebufferSubData =
        reinterpret_cast<PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC>(loader("glInvalidateNamedFramebufferSubData"));
    glMapNamedBufferRange   = reinterpret_cast<PFNGLMAPNAMEDBUFFERRANGEPROC>(loader("glMapNamedBufferRange"));
    glMapNamedBuffer        = reinterpret_cast<PFNGLMAPNAMEDBUFFERPROC>(loader("glMapNamedBuffer"));
    glMemoryBarrierByRegion = reinterpret_cast<PFNGLMEMORYBARRIERBYREGIONPROC>(loader("glMemoryBarrierByRegion"));
    glNamedBufferData       = reinterpret_cast<PFNGLNAMEDBUFFERDATAPROC>(loader("glNamedBufferData"));
    glNamedBufferStorage    = reinterpret_cast<PFNGLNAMEDBUFFERSTORAGEPROC>(loader("glNamedBufferStorage"));
    glNamedBufferSubData    = reinterpret_cast<PFNGLNAMEDBUFFERSUBDATAPROC>(loader("glNamedBufferSubData"));
    glNamedFramebufferDrawBuffers =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC>(loader("glNamedFramebufferDrawBuffers"));
    glNamedFramebufferDrawBuffer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC>(loader("glNamedFramebufferDrawBuffer"));
    glNamedFramebufferParameteri =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC>(loader("glNamedFramebufferParameteri"));
    glNamedFramebufferReadBuffer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC>(loader("glNamedFramebufferReadBuffer"));
    glNamedFramebufferRenderbuffer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC>(loader("glNamedFramebufferRenderbuffer"));
    glNamedFramebufferTextureLayer =
        reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC>(loader("glNamedFramebufferTextureLayer"));
    glNamedFramebufferTexture = reinterpret_cast<PFNGLNAMEDFRAMEBUFFERTEXTUREPROC>(loader("glNamedFramebufferTexture"));
    glNamedRenderbufferStorageMultisample =
        reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC>(loader("glNamedRenderbufferStorageMultisample"));
    glNamedRenderbufferStorage =
        reinterpret_cast<PFNGLNAMEDRENDERBUFFERSTORAGEPROC>(loader("glNamedRenderbufferStorage"));
    glReadnPixels          = reinterpret_cast<PFNGLREADNPIXELSPROC>(loader("glReadnPixels"));
    glTextureBarrier       = reinterpret_cast<PFNGLTEXTUREBARRIERPROC>(loader("glTextureBarrier"));
    glTextureBufferRange   = reinterpret_cast<PFNGLTEXTUREBUFFERRANGEPROC>(loader("glTextureBufferRange"));
    glTextureBuffer        = reinterpret_cast<PFNGLTEXTUREBUFFERPROC>(loader("glTextureBuffer"));
    glTextureParameterIiv  = reinterpret_cast<PFNGLTEXTUREPARAMETERIIVPROC>(loader("glTextureParameterIiv"));
    glTextureParameterIuiv = reinterpret_cast<PFNGLTEXTUREPARAMETERIUIVPROC>(loader("glTextureParameterIuiv"));
    glTextureParameterfv   = reinterpret_cast<PFNGLTEXTUREPARAMETERFVPROC>(loader("glTextureParameterfv"));
    glTextureParameterf    = reinterpret_cast<PFNGLTEXTUREPARAMETERFPROC>(loader("glTextureParameterf"));
    glTextureParameteriv   = reinterpret_cast<PFNGLTEXTUREPARAMETERIVPROC>(loader("glTextureParameteriv"));
    glTextureParameteri    = reinterpret_cast<PFNGLTEXTUREPARAMETERIPROC>(loader("glTextureParameteri"));
    glTextureStorage1D     = reinterpret_cast<PFNGLTEXTURESTORAGE1DPROC>(loader("glTextureStorage1D"));
    glTextureStorage2DMultisample =
        reinterpret_cast<PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC>(loader("glTextureStorage2DMultisample"));
    glTextureStorage2D = reinterpret_cast<PFNGLTEXTURESTORAGE2DPROC>(loader("glTextureStorage2D"));
    glTextureStorage3DMultisample =
        reinterpret_cast<PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC>(loader("glTextureStorage3DMultisample"));
    glTextureStorage3D  = reinterpret_cast<PFNGLTEXTURESTORAGE3DPROC>(loader("glTextureStorage3D"));
    glTextureSubImage1D = reinterpret_cast<PFNGLTEXTURESUBIMAGE1DPROC>(loader("glTextureSubImage1D"));
    glTextureSubImage2D = reinterpret_cast<PFNGLTEXTURESUBIMAGE2DPROC>(loader("glTextureSubImage2D"));
    glTextureSubImage3D = reinterpret_cast<PFNGLTEXTURESUBIMAGE3DPROC>(loader("glTextureSubImage3D"));
    glTransformFeedbackBufferBase =
        reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC>(loader("glTransformFeedbackBufferBase"));
    glTransformFeedbackBufferRange =
        reinterpret_cast<PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC>(loader("glTransformFeedbackBufferRange"));
    glUnmapNamedBuffer = reinterpret_cast<PFNGLUNMAPNAMEDBUFFERPROC>(loader("glUnmapNamedBuffer"));
    glVertexArrayAttribBinding =
        reinterpret_cast<PFNGLVERTEXARRAYATTRIBBINDINGPROC>(loader("glVertexArrayAttribBinding"));
    glVertexArrayAttribFormat = reinterpret_cast<PFNGLVERTEXARRAYATTRIBFORMATPROC>(loader("glVertexArrayAttribFormat"));
    glVertexArrayAttribIFormat =
        reinterpret_cast<PFNGLVERTEXARRAYATTRIBIFORMATPROC>(loader("glVertexArrayAttribIFormat"));
    glVertexArrayAttribLFormat =
        reinterpret_cast<PFNGLVERTEXARRAYATTRIBLFORMATPROC>(loader("glVertexArrayAttribLFormat"));
    glVertexArrayBindingDivisor =
        reinterpret_cast<PFNGLVERTEXARRAYBINDINGDIVISORPROC>(loader("glVertexArrayBindingDivisor"));
    glVertexArrayElementBuffer =
        reinterpret_cast<PFNGLVERTEXARRAYELEMENTBUFFERPROC>(loader("glVertexArrayElementBuffer"));
    glVertexArrayVertexBuffers =
        reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERSPROC>(loader("glVertexArrayVertexBuffers"));
    glVertexArrayVertexBuffer = reinterpret_cast<PFNGLVERTEXARRAYVERTEXBUFFERPROC>(loader("glVertexArrayVertexBuffer"));
}


} // namespace glr