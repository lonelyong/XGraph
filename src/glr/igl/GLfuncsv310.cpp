#include "GLfuncsv310.h"

namespace glr {
GLfuncsv310::GLfuncsv310()
  : glDrawArraysInstanced(nullptr)
  , glDrawElementsInstanced(nullptr)
  , glTexBuffer(nullptr)
  , glPrimitiveRestartIndex(nullptr)
  , glCopyBufferSubData(nullptr)
  , glGetUniformIndices(nullptr)
  , glGetActiveUniformsiv(nullptr)
  , glGetActiveUniformName(nullptr)
  , glGetUniformBlockIndex(nullptr)
  , glGetActiveUniformBlockiv(nullptr)
  , glUniformBlockBinding(nullptr)
  , glGetActiveUniformBlockName(nullptr) {
}

void GLfuncsv310::loadFuncs(Loader loader) {
    glDrawArraysInstanced     = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDPROC>(loader("glDrawArraysInstanced"));
    glDrawElementsInstanced   = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDPROC>(loader("glDrawElementsInstanced"));
    glTexBuffer               = reinterpret_cast<PFNGLTEXBUFFERPROC>(loader("glTexBuffer"));
    glPrimitiveRestartIndex   = reinterpret_cast<PFNGLPRIMITIVERESTARTINDEXPROC>(loader("glPrimitiveRestartIndex"));
    glCopyBufferSubData       = reinterpret_cast<PFNGLCOPYBUFFERSUBDATAPROC>(loader("glCopyBufferSubData"));
    glGetUniformIndices       = reinterpret_cast<PFNGLGETUNIFORMINDICESPROC>(loader("glGetUniformIndices"));
    glGetActiveUniformsiv     = reinterpret_cast<PFNGLGETACTIVEUNIFORMSIVPROC>(loader("glGetActiveUniformsiv"));
    glGetActiveUniformName    = reinterpret_cast<PFNGLGETACTIVEUNIFORMNAMEPROC>(loader("glGetActiveUniformName"));
    glGetUniformBlockIndex    = reinterpret_cast<PFNGLGETUNIFORMBLOCKINDEXPROC>(loader("glGetUniformBlockIndex"));
    glGetActiveUniformBlockiv = reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>(loader("glGetActiveUniformBlockiv"));
    glUniformBlockBinding     = reinterpret_cast<PFNGLUNIFORMBLOCKBINDINGPROC>(loader("glUniformBlockBinding"));
    glGetActiveUniformBlockName =
        reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>(loader("glGetActiveUniformBlockName"));
}
} // namespace glr