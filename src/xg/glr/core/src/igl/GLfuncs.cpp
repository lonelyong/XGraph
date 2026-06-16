#include <xg/glr/igl/GLfuncs.h>

#include <algorithm>
#include <cstring>
#include <map>
#include <memory>
#include <stdio.h>
#include <vector>

static void* gl_get_proc(const char* namez);

#if defined(_WIN32) || defined(__CYGWIN__)

#    ifndef _WINDOWS_
#        undef APIENTRY
#    endif

#    include <Windows.h>

static HMODULE s_libGL;

typedef void* (*PFNWGLGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNWGLGETPROCADDRESSPROC_PRIVATE s_iglGetProcAddressPtr;

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

static int open_gl(void)
{
#    ifndef IS_UWP
    s_libGL = LoadLibraryW(L"opengl32.dll");
    if (s_libGL != NULL) {
        void (*tmp)(void);
        tmp                    = (void (*)(void))GetProcAddress(s_libGL, "wglGetProcAddress");
        s_iglGetProcAddressPtr = (PFNWGLGETPROCADDRESSPROC_PRIVATE)tmp;
        return s_iglGetProcAddressPtr != NULL;
    }
#    endif

    return 0;
}

static void close_gl(void)
{
    if (s_libGL != NULL) {
        FreeLibrary((HMODULE)s_libGL);
        s_libGL = NULL;
    }
}
#else
#    include <dlfcn.h>
static void* s_libGL;

#    if !defined(__APPLE__) && !defined(__HAIKU__)
typedef void*(APIENTRYP PFNGLXGETPROCADDRESSPROC_PRIVATE)(const char*);
static PFNGLXGETPROCADDRESSPROC_PRIVATE s_iglGetProcAddressPtr;
#    endif

static int open_gl(void)
{
#    ifdef __APPLE__
    static const char* NAMES[] = { "../Frameworks/OpenGL.framework/OpenGL",
                                   "/Library/Frameworks/OpenGL.framework/OpenGL",
                                   "/System/Library/Frameworks/OpenGL.framework/OpenGL",
                                   "/System/Library/Frameworks/OpenGL.framework/Versions/Current/OpenGL" };
#    else
    static const char* NAMES[] = { "s_libGL.so.1", "s_libGL.so" };
#    endif

    unsigned int index = 0;
    for (index = 0; index < (sizeof(NAMES) / sizeof(NAMES[0])); index++) {
        s_libGL = dlopen(NAMES[index], RTLD_NOW | RTLD_GLOBAL);

        if (s_libGL != NULL) {
#    if defined(__APPLE__) || defined(__HAIKU__)
            return 1;
#    else
            s_iglGetProcAddressPtr = (PFNGLXGETPROCADDRESSPROC_PRIVATE)dlsym(s_libGL, "glXGetProcAddressARB");
            return s_iglGetProcAddressPtr != NULL;
#    endif
        }
    }

    return 0;
}

static void close_gl(void)
{
    if (s_libGL != NULL) {
        dlclose(s_libGL);
        s_libGL = NULL;
    }
}

#endif

static void* gl_get_proc(const char* namez)
{
    void* result = NULL;
    if (s_libGL == NULL)
        return NULL;

#if !defined(__APPLE__) && !defined(__HAIKU__)
    if (s_iglGetProcAddressPtr != NULL) {
        result = s_iglGetProcAddressPtr(namez);
    }
#endif
    if (result == NULL) {
#if defined(_WIN32) || defined(__CYGWIN__)
        result = (void*)GetProcAddress((HMODULE)s_libGL, namez);
#else
        result = dlsym(s_libGL, namez);
#endif
    }

    return result;
}

namespace xg {
namespace glr
{

struct GLfuncs::Data {
    std::vector<const char*> exts;
};

GLfuncs::GLfuncs()
  : major_version(0)
  , minor_version(0)
  , d(new Data())
{}

GLfuncs::~GLfuncs()
{
    delete d;
}

bool GLfuncs::hasExtension(Extension ext) const
{
    static std::map<Extension, const char*> ext_to_extstr = {
        { GL_ARB_ES2_COMPATIBILITY,        "GL_ARB_ES2_COMPATIBILITY"        },
        { GL_ARB_ES3_COMPATIBILITY,        "GL_ARB_ES3_COMPATIBILITY"        },
        { GL_ARB_ES3_1_COMPATIBILITY,      "GL_ARB_ES3_1_COMPATIBILITY"      },
        { GL_ARB_ES3_2_COMPATIBILITY,      "GL_ARB_ES3_2_COMPATIBILITY"      },
        { GL_ARB_ARRAYS_OF_ARRAYS,         "GL_ARB_ARRAYS_OF_ARRAYS"         },
        { GL_ARB_BINDLESS_TEXTURE,         "GL_ARB_BINDLESS_TEXTURE"         },
        { GL_ARB_CL_EVENT,                 "GL_ARB_CL_EVENT"                 },
        { GL_ARB_SPARSE_TEXTURE,           "GL_ARB_SPARSE_TEXTURE"           },
        { GL_ARB_SPARSE_BUFFER,            "GL_ARB_SPARSE_BUFFER"            },
        { GL_ARB_SHADING_LANGUAGE_INCLUDE, "GL_ARB_SHADING_LANGUAGE_INCLUDE" },
        { GL_ARB_SAMPLE_SHADING,           "GL_ARB_SAMPLE_SHADING"           },
        { GL_ARB_SAMPLE_LOCATIONS,         "GL_ARB_SAMPLE_LOCATIONS"         },
        { GL_ARB_ROBUSTNESS,               "GL_ARB_ROBUSTNESS"               },
        { GL_ARB_PARALLEL_SHADER_COMPILE,  "GL_ARB_PARALLEL_SHADER_COMPILE"  }
    };

    return hasExtension(ext_to_extstr[ext]);
}

bool GLfuncs::hasExtension(const char* ext) const
{
    auto iter = std::find_if(d->exts.begin(), d->exts.end(), [ext](const char* item) { return strcmp(item, ext) == 0; });
    return iter != d->exts.end();
}

GLfuncs* GLfuncs::loadGLLoader(Loader loader)
{
    if (!loader) {
        return nullptr;
    }

    auto getstr = reinterpret_cast<PFNGLGETSTRINGPROC>(loader("glGetString"));

    if (!getstr)
        return nullptr;


#pragma region copy from glad
    int i, major, minor;

    const char* version;
    const char* prefixes[] = { "OpenGL ES-CM ", "OpenGL ES-CL ", "OpenGL ES ", NULL };

    version = (const char*)getstr(IGL_VERSION);
    if (!version)
        return nullptr;

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

    std::unique_ptr<GLfuncs> funcs = std::make_unique<GLfuncs>();

    const_cast<int&>(funcs->major_version) = major;
    const_cast<int&>(funcs->minor_version) = minor;

    funcs->loadFuncs(loader);
    funcs->loadFuncsArb(loader);

    if (major >= 11) {
        GLint_t nb_exts = 0;
        funcs->iglGetIntegerv(IGL_NUM_EXTENSIONS, &nb_exts);
        funcs->d->exts.resize(nb_exts);
        for (int i = 0; i < nb_exts; ++i) {
            auto ext          = (const char*)funcs->iglGetStringi(IGL_EXTENSIONS, i);
            funcs->d->exts[i] = ext;
        }
    }
    else {
        auto exts = (const char*)funcs->iglGetString(IGL_EXTENSIONS);
        if (exts) {
            auto  temp_exts = strdup(exts);
            char* saveptr   = 0;
#ifdef _MSC_VER
            auto token = strtok_s(temp_exts, " ", &saveptr);
            while (token) {
                funcs->d->exts.push_back(token);
                token = strtok_s(NULL, " ", &saveptr);
            }
#else
            auto token = strtok_r(temp_exts, " ", &saveptr);
            while (token) {
                funcs->d->exts.push_back(token);
                token = strtok_r(NULL, " ", &saveptr);
            }
#endif
        }
    }

    return funcs.release();
}

GLfuncs* GLfuncs::load()
{
    if (open_gl()) {
        auto funcs = loadGLLoader(&gl_get_proc);
        close_gl();
        return funcs;
    }

    return nullptr;
}

} // namespace glr
} // namespace xg