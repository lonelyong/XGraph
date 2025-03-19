#include "GLfuncsv420.h"

namespace glr {

GLfuncsv420::GLfuncsv420()
  : glBindImageTexture(nullptr)
  , glDrawArraysInstancedBaseInstance(nullptr)
  , glDrawElementsInstancedBaseInstance(nullptr)
  , glDrawElementsInstancedBaseVertexBaseInstance(nullptr)
  , glDrawTransformFeedbackInstanced(nullptr)
  , glDrawTransformFeedbackStreamInstanced(nullptr)
  , glGetActiveAtomicCounterBufferiv(nullptr)
  , glGetInternalformativ(nullptr)
  , glMemoryBarrier(nullptr)
  , glTexStorage1D(nullptr)
  , glTexStorage2D(nullptr)
  , glTexStorage3D(nullptr) {
}
void GLfuncsv420::loadFuncs(Loader loader) {
    GLfuncsv410::loadFuncs(loader);
    glBindImageTexture = reinterpret_cast<PFNGLBINDIMAGETEXTUREPROC>(loader("glBindImageTexture"));
    glDrawArraysInstancedBaseInstance =
        reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>(loader("glDrawArraysInstancedBaseInstance"));
    glDrawElementsInstancedBaseInstance =
        reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>(loader("glDrawElementsInstancedBaseInstance"));
    glDrawElementsInstancedBaseVertexBaseInstance =
        reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>(
            loader("glDrawElementsInstancedBaseVertexBaseInstance"));
    glDrawTransformFeedbackInstanced =
        reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>(loader("glDrawTransformFeedbackInstanced"));
    glDrawTransformFeedbackStreamInstanced = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>(
        loader("glDrawTransformFeedbackStreamInstanced"));
    glGetActiveAtomicCounterBufferiv =
        reinterpret_cast<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>(loader("glGetActiveAtomicCounterBufferiv"));
    glGetInternalformativ = reinterpret_cast<PFNGLGETINTERNALFORMATIVPROC>(loader("glGetInternalformativ"));
    glMemoryBarrier       = reinterpret_cast<PFNGLMEMORYBARRIERPROC>(loader("glMemoryBarrier"));
    glTexStorage1D        = reinterpret_cast<PFNGLTEXSTORAGE1DPROC>(loader("glTexStorage1D"));
    glTexStorage2D        = reinterpret_cast<PFNGLTEXSTORAGE2DPROC>(loader("glTexStorage2D"));
    glTexStorage3D        = reinterpret_cast<PFNGLTEXSTORAGE3DPROC>(loader("glTexStorage3D"));
}

} // namespace glr