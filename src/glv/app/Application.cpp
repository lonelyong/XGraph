#include "Application.h"

#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <osg/Notify>
#include <osgDB/Registry>

#include <osgVerse/pipeline/Global.h>
#include <osgVerse/pipeline/Utilities.h>

#include <xgcomm/Environment.h>

#include "ConsoleNotifyHandler.h"

namespace glv {


static bool s_is_osg_initialized = false;
static void initOpenSceneGraph();

Application::Application(const AppInitializationParameters& params)
  : params_(params) {
}

Application::~Application() {
}

static void initOpenSceneGraph() {
    if (s_is_osg_initialized) {
        return;
    }

    USE_VERSE_PLUGINS();

    osgVerse::globalInitialize(0, 0);
    osg::initNotifyLevel();
    osg::setNotifyLevel(osg::DEBUG_FP);
    osg::setNotifyHandler(new ConsoleNotifyHandler());
    auto& paths          = osgDB::Registry::instance()->getLibraryFilePathList();
    auto  new_plugin_dir = xg::getApplicationDir();
    new_plugin_dir += "\\plugins\\osg";
    paths.insert(paths.begin(), new_plugin_dir);
    // osgDB::Registry::instance()->setLibraryFilePathList(paths);
}

} // namespace glv