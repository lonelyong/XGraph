#include "GLfuncsv310.h"

namespace glr {


GLfuncsv310::GLfuncsv310()
  : iglDrawArraysInstanced(nullptr)
  , iglDrawElementsInstanced(nullptr)
  , iglTexBuffer(nullptr)
  , iglPrimitiveRestartIndex(nullptr)
  , iglCopyBufferSubData(nullptr)
  , iglGetUniformIndices(nullptr)
  , iglGetActiveUniformsiv(nullptr)
  , iglGetActiveUniformName(nullptr)
  , iglGetUniformBlockIndex(nullptr)
  , iglGetActiveUniformBlockiv(nullptr)
  , iglUniformBlockBinding(nullptr)
  , iglGetActiveUniformBlockName(nullptr) {
}

void GLfuncsv310::loadFuncs(Loader loader) {
    GLfuncsv300::loadFuncs(loader);
    iglDrawArraysInstanced     = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDPROC>(loader("glDrawArraysInstanced"));
    iglDrawElementsInstanced   = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDPROC>(loader("glDrawElementsInstanced"));
    iglTexBuffer               = reinterpret_cast<PFNGLTEXBUFFERPROC>(loader("glTexBuffer"));
    iglPrimitiveRestartIndex   = reinterpret_cast<PFNGLPRIMITIVERESTARTINDEXPROC>(loader("glPrimitiveRestartIndex"));
    iglCopyBufferSubData       = reinterpret_cast<PFNGLCOPYBUFFERSUBDATAPROC>(loader("glCopyBufferSubData"));
    iglGetUniformIndices       = reinterpret_cast<PFNGLGETUNIFORMINDICESPROC>(loader("glGetUniformIndices"));
    iglGetActiveUniformsiv     = reinterpret_cast<PFNGLGETACTIVEUNIFORMSIVPROC>(loader("glGetActiveUniformsiv"));
    iglGetActiveUniformName    = reinterpret_cast<PFNGLGETACTIVEUNIFORMNAMEPROC>(loader("glGetActiveUniformName"));
    iglGetUniformBlockIndex    = reinterpret_cast<PFNGLGETUNIFORMBLOCKINDEXPROC>(loader("glGetUniformBlockIndex"));
    iglGetActiveUniformBlockiv = reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>(loader("glGetActiveUniformBlockiv"));
    iglUniformBlockBinding     = reinterpret_cast<PFNGLUNIFORMBLOCKBINDINGPROC>(loader("glUniformBlockBinding"));
    iglGetActiveUniformBlockName =
        reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>(loader("glGetActiveUniformBlockName"));
}
} // namespace glr