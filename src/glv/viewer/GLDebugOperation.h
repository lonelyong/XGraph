#pragma once
#include <glad/glad.h>

#include <osg/GraphicsThread>

namespace osg {
class GraphicsContext;

}

namespace glv {
typedef void(APIENTRY* glDebugMessageCallbackCallbackPtr)(GLenum        source,
                                                          GLenum        type,
                                                          GLuint        id,
                                                          GLenum        severity,
                                                          GLsizei       length,
                                                          const GLchar* message,
                                                          const void*   userParam);
typedef void(APIENTRY* glDebugMessageCallbackPtr)(glDebugMessageCallbackCallbackPtr callback, const void* userParam);

class GLDebugOperation : public osg::GraphicsOperation {
  public:
    GLDebugOperation();

  public:
    virtual void operator()(osg::GraphicsContext* gc) override;

  private:
    glDebugMessageCallbackPtr glDebugMessageCallback_;
};
} // namespace glv