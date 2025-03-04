#include "Application.h"

#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <osg/Notify>
#include <osgDB/Registry>

// #include <osgVerse/pipeline/Global.h>
// #include <osgVerse/pipeline/Utilities.h>

#include <xgcomm/Environment.h>

#include "ConsoleNotifyHandler.h"

extern "C" {
// Hint to Hybrid laptop drivers that our app would really rather use the NVidia/AMD GPU that you've got
// sitting over there rather than Intel Graphics...
GLV_API unsigned int NvOptimusEnablement                  = 0x00000001;
GLV_API int          AmdPowerXpressRequestHighPerformance = 1;
}

namespace glv {

static Application* s_app_inst;
static bool         s_is_osg_initialized = false;

static void initOpenSceneGraph();

Application::Application(const AppParameters& params)
  : params_(params) {
    if (s_app_inst) {
        throw std::exception("There should be only one application object.");
    }

    if (params.mesa_always_software) {
#ifdef _WIN32
        _putenv_s("LIBGL_ALWAYS_SOFTWARE", "1");
        _putenv_s("MESA_LOADER_DRIVER_OVERRIDE", "swrast");
#endif
    }
    initOpenSceneGraph();
}

Application::~Application() {
    s_app_inst = nullptr;
}

Application* Application::current() {
    return s_app_inst;
}

static void initOpenSceneGraph() {
    if (s_is_osg_initialized) {
        return;
    }

    // USE_VERSE_PLUGINS();

    // osgVerse::globalInitialize(0, 0);
    osg::initNotifyLevel();
    osg::setNotifyLevel(osg::INFO);
    // osg::setNotifyHandler(new ConsoleNotifyHandler());
    auto& paths          = osgDB::Registry::instance()->getLibraryFilePathList();
    auto  new_plugin_dir = xg::getApplicationDir();
    new_plugin_dir += "\\plugins\\osg";
    paths.insert(paths.begin(), new_plugin_dir);

    bool glad_loaded = false;

    //if (glfwInit() == GLFW_TRUE) {
    //    auto wnd = glfwCreateWindow(1, 1, "GladAppInitializer", NULL, NULL);
    //    if (wnd) {
    //        glfwMakeContextCurrent(wnd);
    //        if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    //            glad_loaded = true;
    //        }
    //        glfwDestroyWindow(wnd);
    //    }
    //}

    //if (!glad_loaded) {
    //    std::cout << "Failed to initialize GLAD." << std::endl;
    //}
}

} // namespace glv