#include <glr/igl/GLfuncs.h>

#include <memory>
#include <stdio.h>

#include <glr/igl/GLdefs.h>

#include <glr/igl/GLfuncsv460.h>


static void* gl_get_rpoc(const char* namez);

#if defined(_WIN32) || defined(__CYGWIN__)

#    ifndef _WINDOWS_
#        undef APIENTRY
#    endif

#    include <Windows.h>

static HMODULE libGL;

typedef void* (*PFNWGLGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNWGLGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;

#    ifdef _MSC_VER
#        ifdef __has_include
#            if __has_include(<winapifamily.h>)
#                define HAVE_WINAPIFAMILY 1
#            endif
#        elif _MSC_VER >= 1700 && !_USING_V110_SDK71_
#            define HAVE_WINAPIFAMILY 1
#        endif
#    endif

#    ifdef HAVE_WINAPIFAMILY
#        include <winapifamily.h>
#        if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#            define IS_UWP 1
#        endif
#    endif

static int open_gl(void) {
#    ifndef IS_UWP
    libGL = LoadLibraryW(L"opengl32.dll");
    if (libGL != NULL) {
        void (*tmp)(void);
        tmp                   = (void (*)(void))GetProcAddress(libGL, "wglGetProcAddress");
        gladGetProcAddressPtr = (PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
        return gladGetProcAddressPtr != NULL;
    }
#    endif

    return 0;
}

static void close_gl(void) {
    if (libGL != NULL) {
        FreeLibrary((HMODULE)libGL);
        libGL = NULL;
    }
}
#else
#    include <dlfcn.h>
static void* libGL;

#    if !defined(__APPLE__) && !defined(__HAIKU__)
typedef void*(APIENTRYP PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNGLXGETPROCADDRESSPROC_PRIVATE gladGetProcAddressPtr;
#    endif

static int open_gl(void) {
#    ifdef __APPLE__
    static const char* NAMES[] = { "../Frameworks/OpenGL.framework/OpenGL",
                                   "/Library/Frameworks/OpenGL.framework/OpenGL",
                                   "/System/Library/Frameworks/OpenGL.framework/OpenGL",
                                   "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL" };
#    else
    static const char* NAMES[] = { "libGL.so.1", "libGL.so" };
#    endif

    unsigned int index = 0;
    for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
        libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL);

        if (libGL != NULL) {
#    if defined(__APPLE__) || defined(__HAIKU__)
            return 1;
#    else
            gladGetProcAddressPtr = (PFNGLXGETPROCADDRESSPROC_PRIVATE)dlsym(libGL, "glXGetProcAddressARB");
            return gladGetProcAddressPtr != NULL;
#    endif
        }
    }

    return 0;
}

static void close_gl(void) {
    if (libGL != NULL) {
        dlclose(libGL);
        libGL = NULL;
    }
}

#endif

static void* gl_get_rpoc(const char* namez) {
    void* result = NULL;
    if (libGL == NULL) return NULL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
    if (gladGetProcAddressPtr != NULL) {
        result = gladGetProcAddressPtr(namez);
    }
#endif
    if (result == NULL) {
#if defined(_WIN32) || defined(__CYGWIN__)
        result = (void*)GetProcAddress((HMODULE)libGL, namez);
#else
        result = dlsym(libGL, namez);
#endif
    }

    return result;
}

namespace glr {
VI_OBJECT_META_IMPL(GLfuncs, vine::Object);

typedef const GLubyte_t* (*PFNGLGETSTRINGPROC)(GLenum_t name);

GLfuncs* GLfuncs::loadGLLoader(Loader loader) {
    if (!loader) {
        return nullptr;
    }

    auto glGetString = reinterpret_cast<PFNGLGETSTRINGPROC>(loader("glGetString"));

    if (!glGetString) return nullptr;


#pragma region copy from glad
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
#pragma endregion

    std::unique_ptr<GLfuncs> funcs;

    const_cast<int&>(funcs->major_version) = major;
    const_cast<int&>(funcs->minor_version) = minor;

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

GLfuncs* GLfuncs::load() {

    if (open_gl()) {
        return loadGLLoader(&gl_get_rpoc);
        close_gl();
    }

    return nullptr;
}

} // namespace glr