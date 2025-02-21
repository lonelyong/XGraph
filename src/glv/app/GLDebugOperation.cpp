#include "GLDebugOperation.h"

#include <string>

#include <osg/Notify>

namespace glv {
static void debugCallback(GLenum        source,
                          GLenum        type,
                          GLuint        id,
                          GLenum        severity,
                          GLsizei       length,
                          const GLchar* message,
                          const void*   userParam) {
    std::string src_desc, type_desc, id_desc;
    switch (source) {
    case GL_DEBUG_SOURCE_API: src_desc = "API"; break;
    case GL_DEBUG_SOURCE_WINDOW_SYSTEM: src_desc = "WINDOW_SYSTEM"; break;
    case GL_DEBUG_SOURCE_SHADER_COMPILER: src_desc = "SHADER_COMPILER"; break;
    case GL_DEBUG_SOURCE_THIRD_PARTY: src_desc = "THIRD_PARTY"; break;
    case GL_DEBUG_SOURCE_APPLICATION: src_desc = "APPLICATION"; break;
    case GL_DEBUG_SOURCE_OTHER: src_desc = "OTHER"; break;
    default: src_desc = "UNKNOWN_SOURCE"; break;
    }

    switch (type) {
    case GL_DEBUG_TYPE_ERROR: type_desc = "ERROR"; break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: type_desc = "DEPRECATED_BEHAVIOR"; break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: type_desc = "UNDEFINED_BEHAVIOR"; break;
    case GL_DEBUG_TYPE_PORTABILITY: type_desc = "PORTABILITY"; break;
    case GL_DEBUG_TYPE_PERFORMANCE: type_desc = "PERFORMANCE"; break;
    case GL_DEBUG_TYPE_MARKER: type_desc = "MARKER"; break;
    case GL_DEBUG_TYPE_PUSH_GROUP: type_desc = "PUSH_GROUP"; break;
    case GL_DEBUG_TYPE_POP_GROUP: type_desc = "POP_GROUP"; break;
    case GL_DEBUG_TYPE_OTHER: type_desc = "OTHER"; break;
    default: type_desc = "UNKNOWN_TYPE"; break;
    }

    switch (id) {
    case GL_NO_ERROR: id_desc = "NO_ERROR"; break;
    case GL_INVALID_ENUM: id_desc = "INVALID_ENUM"; break;
    case GL_INVALID_VALUE: id_desc = "INVALID_VALUE"; break;
    case GL_INVALID_OPERATION: id_desc = "INVALID_OPERATION"; break;
    case GL_STACK_OVERFLOW: id_desc = "STACK_OVERFLOW"; break;
    case GL_STACK_UNDERFLOW: id_desc = "STACK_UNDERFLOW"; break;
    case GL_OUT_OF_MEMORY: id_desc = "OUT_OF_MEMORY"; break;
    case GL_INVALID_FRAMEBUFFER_OPERATION: id_desc = "INVALID_FRAMEBUFFER_OPERATION"; break;
    case GL_CONTEXT_LOST: id_desc = "CONTEXT_LOST"; break;
    // case GL_TABLE_TOO_LARGE: id_desc = "TABLE_TOO_LARGE"; break;
    default: id_desc = "UNKNOWN_ID"; break;
    }

    std::string msg =
        "(ID = " + id_desc + ") " + std::string(message) + "\n\t(Source = " + src_desc + ", Type = " + type_desc + ")";
    switch (severity) {
    case GL_DEBUG_SEVERITY_HIGH: OSG_WARN << "[HIGH] " << msg << std::endl; break;
    case GL_DEBUG_SEVERITY_MEDIUM: OSG_NOTICE << "[MEDIUM] " << msg << std::endl; break;
    case GL_DEBUG_SEVERITY_LOW: OSG_INFO << "[LOW] " << msg << std::endl; break;
    case GL_DEBUG_SEVERITY_NOTIFICATION: OSG_INFO << "[NOTIFY] " << msg << std::endl; break;
    default: OSG_NOTICE << "[DEFAULT] " << msg << std::endl; break;
    }
}

GLDebugOperation::GLDebugOperation()
  : osg::Referenced(true)
  , osg::GraphicsOperation("GLDebugOperation", false)
  , glDebugMessageCallback_(nullptr) {
}

void GLDebugOperation::operator()(osg::GraphicsContext* gc) {
    glDebugMessageCallback_ = (glDebugMessageCallbackPtr)osg::getGLExtensionFuncPtr("glDebugMessageCallback");
    if (glDebugMessageCallback_ == nullptr) {
        OSG_WARN << "[GLDebugOperation] Debug callback function not found" << std::endl;
        return;
    }

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback_((glDebugMessageCallbackCallbackPtr) & (debugCallback), nullptr);
    // glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, 0, GL_FALSE);
    glDebugMessageInsert(GL_DEBUG_SOURCE_APPLICATION,
                         GL_DEBUG_TYPE_OTHER,
                         1,
                         GL_DEBUG_SEVERITY_NOTIFICATION,
                         -1,
                         "GL Debug Enabled");
}
} // namespace glv