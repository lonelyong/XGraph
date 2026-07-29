#include <xg/igl/ogl/GLfuncsv420.hpp>

namespace xg
{
namespace glr
{


GLfuncsv420::GLfuncsv420()
  : oglBindImageTexture(nullptr)
  , oglDrawArraysInstancedBaseInstance(nullptr)
  , oglDrawElementsInstancedBaseInstance(nullptr)
  , oglDrawElementsInstancedBaseVertexBaseInstance(nullptr)
  , oglDrawTransformFeedbackInstanced(nullptr)
  , oglDrawTransformFeedbackStreamInstanced(nullptr)
  , oglGetActiveAtomicCounterBufferiv(nullptr)
  , oglGetInternalformativ(nullptr)
  , oglMemoryBarrier(nullptr)
  , oglTexStorage1D(nullptr)
  , oglTexStorage2D(nullptr)
  , oglTexStorage3D(nullptr)
{}

void GLfuncsv420::loadFuncs(Loader loader)
{
    GLfuncsv410::loadFuncs(loader);
    oglBindImageTexture                  = reinterpret_cast<PFNGLBINDIMAGETEXTUREPROC>(loader("glBindImageTexture"));
    oglDrawArraysInstancedBaseInstance   = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC>(loader("glDrawArraysInstancedBaseInstance"));
    oglDrawElementsInstancedBaseInstance = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC>(loader("glDrawElementsInstancedBaseInstance"));
    oglDrawElementsInstancedBaseVertexBaseInstance =
        reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC>(loader("glDrawElementsInstancedBaseVertexBaseInstance"));
    oglDrawTransformFeedbackInstanced       = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC>(loader("glDrawTransformFeedbackInstanced"));
    oglDrawTransformFeedbackStreamInstanced = reinterpret_cast<PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC>(loader("glDrawTransformFeedbackStreamInstanced"));
    oglGetActiveAtomicCounterBufferiv       = reinterpret_cast<PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC>(loader("glGetActiveAtomicCounterBufferiv"));
    oglGetInternalformativ                  = reinterpret_cast<PFNGLGETINTERNALFORMATIVPROC>(loader("glGetInternalformativ"));
    oglMemoryBarrier                        = reinterpret_cast<PFNGLMEMORYBARRIERPROC>(loader("glMemoryBarrier"));
    oglTexStorage1D                         = reinterpret_cast<PFNGLTEXSTORAGE1DPROC>(loader("glTexStorage1D"));
    oglTexStorage2D                         = reinterpret_cast<PFNGLTEXSTORAGE2DPROC>(loader("glTexStorage2D"));
    oglTexStorage3D                         = reinterpret_cast<PFNGLTEXSTORAGE3DPROC>(loader("glTexStorage3D"));
}

} // namespace glr
} // namespace xg