#include <xg/xviewer/app/Application.hpp>

#include <iostream>

#include <osg/Notify>
#include <osgDB/Registry>
#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE
#    include <osgVerse/pipeline/Pipeline.h>
#endif

// #include <osgVerse/pipeline/Global.h>
// #include <osgVerse/pipeline/Utilities.h>

#include <xg/comm/Environment.hpp>
#include <xg/xviewer/app/ConsoleNotifyHandler.hpp>


#ifdef _WIN32
extern "C"
{
    // Hint to Hybrid laptop drivers that our app would really rather use the NVidia/AMD GPU that you've got
    // sitting over there rather than Intel Graphics...
    XVIEWER_API unsigned int NvOptimusEnablement                  = 0x00000001;
    XVIEWER_API int          AmdPowerXpressRequestHighPerformance = 1;
}
#endif

namespace xg
{
namespace xviewer
{

static Application* s_app_inst;
static bool         s_is_osg_initialized = false;

static void initOpenSceneGraph(int argc, char** argv);

Application::Application(int argc, char** argv)
{
    if (s_app_inst) { throw std::runtime_error("There should be only one application object."); }

    params_.argc = argc;
    params_.argv = argv;

    if (params_.mesa_always_software) {
#ifdef _WIN32
        _putenv_s("LIBGL_ALWAYS_SOFTWARE", "1");
        _putenv_s("MESA_LOADER_DRIVER_OVERRIDE", "swrast");
#endif
    }
    initOpenSceneGraph(argc, argv);
}

Application::~Application()
{ s_app_inst = nullptr; }

Application* Application::current()
{ return s_app_inst; }

static void initOpenSceneGraph(int argc, char** argv)
{
    if (s_is_osg_initialized) { return; }

    // USE_VERSE_PLUGINS();

    // osgVerse::globalInitialize(0, 0);
    osg::initNotifyLevel();
    osg::setNotifyLevel(osg::INFO);
    // osg::setNotifyHandler(new ConsoleNotifyHandler());
    auto& paths          = osgDB::Registry::instance()->getLibraryFilePathList();
    auto  new_plugin_dir = xg::getApplicationDir();
    new_plugin_dir += "\\plugins\\osg";
    paths.insert(paths.begin(), new_plugin_dir);

#ifdef XG_XVIEWER_BUILD_WITH_OSGVERSE
    osgVerse::globalInitialize(argc, argv);
#endif
}

} // namespace xviewer
} // namespace xg