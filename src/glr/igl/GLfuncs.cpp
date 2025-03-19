#include <glr/igl/GLfuncs.h>

#include <memory>
#include <stdio.h>

#include <glr/igl/GLdefs.h>

#include <glr/igl/GLfuncsv460.h>

namespace glr {
VI_OBJECT_META_IMPL(GLfuncs, vine::Object);

typedef const GLubyte_t* (*PFNGLGETSTRINGPROC)(GLenum_t name);

GLfuncs* GLfuncs::load(Loader loader) {
    if (!loader) {
        return nullptr;
    }

    auto glGetString = reinterpret_cast<PFNGLGETSTRINGPROC>(loader("glGetString"));

    if (!glGetString) return nullptr;

    int i, major, minor;

    const char* version;
    const char* prefixes[] = { "OpenGL ES-CM ", "OpenGL ES-CL ", "OpenGL ES ", NULL };

    version = (const char*)glGetString(IGL_VERSION);
    if (!version) return nullptr;

    for (i = 0; prefixes[i]; i++) {
        const size_t length = strlen(prefixes[i]);
        if (strncmp(version, prefixes[i], length) == 0) {
            version += length;
            break;
        }
    }

/* PR #18 */
#ifdef _MSC_VER
    sscanf_s(version, "%d.%d", &major, &minor);
#else
    sscanf(version, "%d.%d", &major, &minor);
#endif

    std::unique_ptr<GLfuncs> funcs;

    if (major == 1 && minor == 0) {
        funcs.reset(new GLfuncsv100());
    }
    else if (major == 1 && minor == 1) {
        funcs.reset(new GLfuncsv110());
    }
    else if (major == 1 && minor == 2) {
        funcs.reset(new GLfuncsv120());
    }
    else if (major == 1 && minor == 3) {
        funcs.reset(new GLfuncsv130());
    }
    else if (major == 1 && minor == 4) {
        funcs.reset(new GLfuncsv140());
    }
    else if (major == 1 && minor == 5) {
        funcs.reset(new GLfuncsv150());
    }
    else if (major == 2 && minor == 0) {
        funcs.reset(new GLfuncsv200());
    }
    else if (major == 2 && minor == 1) {
        funcs.reset(new GLfuncsv210());
    }
    else if (major == 3 && minor == 0) {
        funcs.reset(new GLfuncsv300());
    }
    else if (major == 3 && minor == 1) {
        funcs.reset(new GLfuncsv310());
    }
    else if (major == 3 && minor == 2) {
        funcs.reset(new GLfuncsv320());
    }
    else if (major == 3 && minor == 3) {
        funcs.reset(new GLfuncsv330());
    }
    else if (major == 4 && minor == 0) {
        funcs.reset(new GLfuncsv400());
    }
    else if (major == 4 && minor == 1) {
        funcs.reset(new GLfuncsv410());
    }
    else if (major == 4 && minor == 2) {
        funcs.reset(new GLfuncsv420());
    }
    else if (major == 4 && minor == 3) {
        funcs.reset(new GLfuncsv430());
    }
    else if (major == 4 && minor == 4) {
        funcs.reset(new GLfuncsv440());
    }
    else if (major == 4 && minor == 5) {
        funcs.reset(new GLfuncsv450());
    }
    else if (major == 4 && minor == 6) {
        funcs.reset(new GLfuncsv460());
    }

    funcs->loadFuncs(loader);

    return funcs.release();
}

} // namespace glr