#include <xg/igl/ogl/GLfuncsv310.hpp>

namespace xg
{
namespace glr
{


GLfuncsv310::GLfuncsv310()
  : oglDrawArraysInstanced(nullptr)
  , oglDrawElementsInstanced(nullptr)
  , oglTexBuffer(nullptr)
  , oglPrimitiveRestartIndex(nullptr)
  , oglCopyBufferSubData(nullptr)
  , oglGetUniformIndices(nullptr)
  , oglGetActiveUniformsiv(nullptr)
  , oglGetActiveUniformName(nullptr)
  , oglGetUniformBlockIndex(nullptr)
  , oglGetActiveUniformBlockiv(nullptr)
  , oglUniformBlockBinding(nullptr)
  , oglGetActiveUniformBlockName(nullptr)
{}

void GLfuncsv310::loadFuncs(Loader loader)
{
    GLfuncsv300::loadFuncs(loader);
    oglDrawArraysInstanced       = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDPROC>(loader("glDrawArraysInstanced"));
    oglDrawElementsInstanced     = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDPROC>(loader("glDrawElementsInstanced"));
    oglTexBuffer                 = reinterpret_cast<PFNGLTEXBUFFERPROC>(loader("glTexBuffer"));
    oglPrimitiveRestartIndex     = reinterpret_cast<PFNGLPRIMITIVERESTARTINDEXPROC>(loader("glPrimitiveRestartIndex"));
    oglCopyBufferSubData         = reinterpret_cast<PFNGLCOPYBUFFERSUBDATAPROC>(loader("glCopyBufferSubData"));
    oglGetUniformIndices         = reinterpret_cast<PFNGLGETUNIFORMINDICESPROC>(loader("glGetUniformIndices"));
    oglGetActiveUniformsiv       = reinterpret_cast<PFNGLGETACTIVEUNIFORMSIVPROC>(loader("glGetActiveUniformsiv"));
    oglGetActiveUniformName      = reinterpret_cast<PFNGLGETACTIVEUNIFORMNAMEPROC>(loader("glGetActiveUniformName"));
    oglGetUniformBlockIndex      = reinterpret_cast<PFNGLGETUNIFORMBLOCKINDEXPROC>(loader("glGetUniformBlockIndex"));
    oglGetActiveUniformBlockiv   = reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKIVPROC>(loader("glGetActiveUniformBlockiv"));
    oglUniformBlockBinding       = reinterpret_cast<PFNGLUNIFORMBLOCKBINDINGPROC>(loader("glUniformBlockBinding"));
    oglGetActiveUniformBlockName = reinterpret_cast<PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC>(loader("glGetActiveUniformBlockName"));
}

} // namespace glr
} // namespace xg