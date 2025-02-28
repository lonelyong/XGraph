#include "Application.h"

#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <osg/Notify>
#include <osgDB/Registry>

//#include <osgVerse/pipeline/Global.h>
//#include <osgVerse/pipeline/Utilities.h>

#include <xgcomm/Environment.h>

#include "ConsoleNotifyHandler.h"

namespace glv {


static bool s_is_osg_initialized = false;
static void initOpenSceneGraph();

Application::Application(const AppInitializationParameters& params)
  : params_(params) {
    initOpenSceneGraph();
}

Application::~Application() {
}

static void initOpenSceneGraph() {
    if (s_is_osg_initialized) {
        return;
    }

    //USE_VERSE_PLUGINS();

    //osgVerse::globalInitialize(0, 0);
    osg::initNotifyLevel();
    osg::setNotifyLevel(osg::INFO);
    //osg::setNotifyHandler(new ConsoleNotifyHandler());
    auto& paths          = osgDB::Registry::instance()->getLibraryFilePathList();
    auto  new_plugin_dir = xg::getApplicationDir();
    new_plugin_dir += "\\plugins\\osg";
    paths.insert(paths.begin(), new_plugin_dir);

    bool glad_loaded = false;

    if (glfwInit() == GLFW_TRUE) {
        auto wnd = glfwCreateWindow(1, 1, "GladAppInitializer", NULL, NULL);
        if (wnd) {
            glfwMakeContextCurrent(wnd);
            if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
                glad_loaded = true;
            }
            glfwDestroyWindow(wnd);
        }
    }

    if (!glad_loaded) {
        std::cout << "Failed to initialize GLAD." << std::endl;
    }

}

} // namespace glv