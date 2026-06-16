#include "GLfuncsv420.h"

namespace glr {


GLfuncsv420::GLfuncsv420()
  : iglBindImageTexture(nullptr)
  , iglDrawArraysInstancedBaseInstance(nullptr)
  , iglDrawElementsInstancedBaseInstance(nullptr)
  , iglDrawElementsInstancedBaseVertexBaseInstance(nullptr)
  , iglDrawTransformFeedbackInstanced(nullptr)
  , iglDrawTransformFeedbackStreamInstanced(nullptr)
  , iglGetActiveAtomicCounterBufferiv(nullptr)
  , iglGetInternalformativ(nullptr)
  , iglMemoryBarrier(nullptr)
  , iglTexStorage1D(nullptr)
  , iglTexStorage2D(nullptr)
  , iglTexStorage3D(nullptr) {
}
void GLfuncsv420::loadFuncs(Loader loader) {
    GLfuncsv410::loadFuncs(loader);
    iglBindImageTexture = reinterpret_cast<PFNGLBINDIMAGETEXTUREPROC>(loader("glBindImageTexture"));
    iglDrawArraysInstancedBaseInstance =
        reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>(loader("glDrawArraysInstancedBaseInstance"));
    iglDrawElementsInstancedBaseInstance =
        reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>(loader("glDrawElementsInstancedBaseInstance"));
    iglDrawElementsInstancedBaseVertexBaseInstance =
        reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>(
            loader("glDrawElementsInstancedBaseVertexBaseInstance"));
    iglDrawTransformFeedbackInstanced =
        reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>(loader("glDrawTransformFeedbackInstanced"));
    iglDrawTransformFeedbackStreamInstanced = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>(
        loader("glDrawTransformFeedbackStreamInstanced"));
    iglGetActiveAtomicCounterBufferiv =
        reinterpret_cast<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>(loader("glGetActiveAtomicCounterBufferiv"));
    iglGetInternalformativ = reinterpret_cast<PFNGLGETINTERNALFORMATIVPROC>(loader("glGetInternalformativ"));
    iglMemoryBarrier       = reinterpret_cast<PFNGLMEMORYBARRIERPROC>(loader("glMemoryBarrier"));
    iglTexStorage1D        = reinterpret_cast<PFNGLTEXSTORAGE1DPROC>(loader("glTexStorage1D"));
    iglTexStorage2D        = reinterpret_cast<PFNGLTEXSTORAGE2DPROC>(loader("glTexStorage2D"));
    iglTexStorage3D        = reinterpret_cast<PFNGLTEXSTORAGE3DPROC>(loader("glTexStorage3D"));
}

} // namespace glr