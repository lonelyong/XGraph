#include <xg/xviewer/app/RealizeOperation.hpp>

#include <string>

#include <osg/GraphicsContext>
#include <osg/Notify>
#include <osg/ValueObject>

#include <xg/glr/igl/GLfuncs.hpp>

#include <xg/xviewer/utils/GLfuncsManager.hpp>

namespace xg {
namespace xviewer {

static void debugMessageCallback(GLenum        source,
                                 GLenum        type,
                                 GLuint        id,
                                 GLenum        severity,
                                 GLsizei       length,
                                 const GLchar* message,
                                 const void*   userParam) {
    std::string src_desc, type_desc, id_desc;
    switch (source) {
    case IGL_DEBUG_SOURCE_API: src_desc = "API"; break;
    case IGL_DEBUG_SOURCE_WINDOW_SYSTEM: src_desc = "WINDOW_SYSTEM"; break;
    case IGL_DEBUG_SOURCE_SHADER_COMPILER: src_desc = "SHADER_COMPILER"; break;
    case IGL_DEBUG_SOURCE_THIRD_PARTY: src_desc = "THIRD_PARTY"; break;
    case IGL_DEBUG_SOURCE_APPLICATION: src_desc = "APPLICATION"; break;
    case IGL_DEBUG_SOURCE_OTHER: src_desc = "OTHER"; break;
    default: src_desc = "UNKNOWN_SOURCE"; break;
    }

    switch (type) {
    case IGL_DEBUG_TYPE_ERROR: type_desc = "ERROR"; break;
    case IGL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: type_desc = "DEPRECATED_BEHAVIOR"; break;
    case IGL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: type_desc = "UNDEFINED_BEHAVIOR"; break;
    case IGL_DEBUG_TYPE_PORTABILITY: type_desc = "PORTABILITY"; break;
    case IGL_DEBUG_TYPE_PERFORMANCE: type_desc = "PERFORMANCE"; break;
    case IGL_DEBUG_TYPE_MARKER: type_desc = "MARKER"; break;
    case IGL_DEBUG_TYPE_PUSH_GROUP: type_desc = "PUSH_GROUP"; break;
    case IGL_DEBUG_TYPE_POP_GROUP: type_desc = "POP_GROUP"; break;
    case IGL_DEBUG_TYPE_OTHER: type_desc = "OTHER"; break;
    default: type_desc = "UNKNOWN_TYPE"; break;
    }

    switch (id) {
    case IGL_NO_ERROR: id_desc = "NO_ERROR"; break;
    case IGL_INVALID_ENUM: id_desc = "INVALID_ENUM"; break;
    case IGL_INVALID_VALUE: id_desc = "INVALID_VALUE"; break;
    case IGL_INVALID_OPERATION: id_desc = "INVALID_OPERATION"; break;
    case IGL_STACK_OVERFLOW: id_desc = "STACK_OVERFLOW"; break;
    case IGL_STACK_UNDERFLOW: id_desc = "STACK_UNDERFLOW"; break;
    case IGL_OUT_OF_MEMORY: id_desc = "OUT_OF_MEMORY"; break;
    case IGL_INVALID_FRAMEBUFFER_OPERATION: id_desc = "INVALID_FRAMEBUFFER_OPERATION"; break;
    case IGL_CONTEXT_LOST: id_desc = "CONTEXT_LOST"; break;
    // case IGL_TABLE_TOO_LARGE: id_desc = "TABLE_TOO_LARGE"; break;
    default: id_desc = "UNKNOWN"; break;
    }

    std::string msg = "(ID = " + id_desc + "; Source = " + src_desc + "; Type = " + type_desc + ") " + message;
    switch (severity) {
    case IGL_DEBUG_SEVERITY_HIGH: OSG_WARN << "[HIGH] " << msg << std::endl; break;
    case IGL_DEBUG_SEVERITY_MEDIUM: OSG_NOTICE << "[MEDIUM] " << msg << std::endl; break;
    case IGL_DEBUG_SEVERITY_LOW: OSG_INFO << "[LOW] " << msg << std::endl; break;
    case IGL_DEBUG_SEVERITY_NOTIFICATION: OSG_INFO << "[NOTIFY] " << msg << std::endl; break;
    default: OSG_NOTICE << "[DEFAULT] " << msg << std::endl; break;
    }
}

RealizeOperation::RealizeOperation()
  : osg::Referenced(true)
  , osg::GraphicsOperation("RealizeOperation", false) {
}

void RealizeOperation::operator()(osg::GraphicsContext* gc) {
    GLint ver_maj, ver_min;

    auto funcs = GLfuncsManager::instance().getOrRegisterByContext(gc);
     
    auto gl_ver = glGetString(IGL_VERSION);
    auto vendor = glGetString(IGL_VENDOR);

    glGetIntegerv(IGL_MAJOR_VERSION, &ver_maj);
    glGetIntegerv(IGL_MINOR_VERSION, &ver_min);
    bool is_gl2_available = true;
    if ((ver_maj == 3 && ver_min >= 2) || ver_maj > 3) {
        GLint profile_mask;
        glGetIntegerv(IGL_CONTEXT_PROFILE_MASK, &profile_mask);
        if (profile_mask) {
            is_gl2_available = profile_mask == IGL_CONTEXT_COMPATIBILITY_PROFILE_BIT;
        }
        if (!profile_mask) {
            GLint flags;
            glGetIntegerv(IGL_CONTEXT_FLAGS, &flags);
            if (flags & IGL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT) {
                is_gl2_available = true;
            }

            if (!flags) {
                GLint nb_exts;
                glGetIntegerv(IGL_NUM_EXTENSIONS, &nb_exts);
                for (GLint i = 0; i < nb_exts; ++i) {
                    auto ext = (const char*)funcs->iglGetStringi(IGL_EXTENSIONS, i);
                    if (strcmp(ext, "GL_ARB_compatibility") == 0) {
                        is_gl2_available = true;
                        break;
                    }
                }
            }
        }
    }

    funcs->iglDisable(IGL_SCISSOR_TEST);
    funcs->iglDisable(IGL_MULTISAMPLE);

    GLint sampleBuffers = 0, samples = 0, max_vertex_attrib = 0, max_tex_units, max_tex_img_units;
    funcs->iglGetIntegerv(IGL_SAMPLE_BUFFERS, &sampleBuffers);
    funcs->iglGetIntegerv(IGL_SAMPLES, &samples);
    funcs->iglGetIntegerv(IGL_MAX_VERTEX_ATTRIBS, &max_vertex_attrib);
    funcs->iglGetIntegerv(IGL_MAX_TEXTURE_UNITS, &max_tex_units);
    funcs->iglGetIntegerv(IGL_MAX_TEXTURE_IMAGE_UNITS, &max_tex_img_units);

    OSG_INFO << "\nGraphics context realized.";
    OSG_INFO << "\nGL Version: " << gl_ver;
    OSG_INFO << "\nGL Vendor: " << vendor;
    OSG_INFO << "\nGL2 Available: " << is_gl2_available;
    OSG_INFO << "\n\n";

    if (true || ver_maj == 4 && ver_min >= 3) {

        funcs->iglEnable(IGL_DEBUG_OUTPUT);
        funcs->iglDebugMessageCallback(debugMessageCallback, nullptr);
        funcs->iglDebugMessageControl(IGL_DONT_CARE, IGL_DONT_CARE, IGL_DONT_CARE, 0, 0, IGL_TRUE);
        funcs->iglDebugMessageInsert(IGL_DEBUG_SOURCE_APPLICATION,
                                     IGL_DEBUG_TYPE_OTHER,
                                     1,
                                     IGL_DEBUG_SEVERITY_NOTIFICATION,
                                     -1,
                                     "GL Debug Enabled");
    }
}
} // namespace xviewer
} // namespace xg