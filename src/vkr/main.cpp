#include <QApplication>
#include <Windows.h>

#include <iostream>

#include <glm/ext.hpp>

#include <vine/core/Ptr.h>
#include <vine/ge/Rect2d.h>

#include <xgcomm/Resources.h>

#include <vkr/app/Application.h>
#include <vkr/app/ResourceManager.h>
#include <vkr/engine/Camera.h>
#include <vkr/engine/CameraManipulator.h>
#include <vkr/engine/GraphicContext.h>
#include <vkr/engine/Image.h>
#include <vkr/engine/Light.h>
#include <vkr/engine/Material.h>
#include <vkr/engine/Renderer.h>
#include <vkr/engine/Shader.h>
#include <vkr/engine/StateSet.h>
#include <vkr/engine/Uniform.h>
#include <vkr/io/ImageLoader.h>
#include <vkr/io/MeshLoader.h>
#include <vkr/io/PointCloudLoader.h>
#include <vkr/scene/Geometry.h>
#include <vkr/scene/Model.h>
#include <vkr/scene/Scene.h>
#include <vkr/app/GlfwViewer.h>
#include <vkr/app/QtMainWindow.h>
#include <vkr/app/QtViewer.h>
#include <vkr/app/SdlViewer.h>
#include <vkr/app/Viewer.h>

void CreateSampleScene(vkr::Scene* scene) {
}

int main(int argc, char** argv) {
    // MESA3D 确保使用软件驱动
    _putenv_s("LIBGL_ALWAYS_SOFTWARE", "1");
    _putenv_s("MESA_LOADER_DRIVER_OVERRIDE", "swrast");

    vkr::AppInitializationParameters params;
    vkr::Application              initializer(params);
    initializer.initGlfw();
    initializer.initQt();

    auto scene = new vkr::Scene();

#define GLFW_VIEWER
#define SDL_VIEWER1

#ifdef GLFW_VIEWER
    vkr::GlfwViewer v;
    if (!v.initialize()) {
        return -1;
    }
    auto renderer = v.getMasterRenderer();

#elif defined(SDL_VIEWER)
    vkr::SdlViewer v;
    if (!v.initialize()) {
        return -1;
    }
    auto renderer = v.getMasterRenderer();

    // QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication      app(argc, argv);
    vkr::QtMainWindow wnd;
    auto              renderer = wnd.getViewer()->getMasterRenderer();
#endif

    if (argc > 1) {
        auto file  = argv[1];
        auto model = vkr::MeshLoader().loadFile(file);
        auto light = new vkr::Light();
        light->setPosition(vkr::Vec4f(10, 10, 10, 1.));
        light->setDirection(vkr::Vec3f(2, 4, -1));
        auto lights = new vkr::Lights();
        lights->addLight(light);
        model->getOrCreateStateSet()->setAttribute(new vkr::Material());
        model->getOrCreateStateSet()->setAttribute(lights);
        model->getOrCreateStateSet()->setAttribute(new vkr::Uniform("use_texture", false));
        model->getOrCreateStateSet()->setShader(
            vkr::ResourceManager::instance()->getInternalShader(vkr::ResourceManager::IS_Base));
        scene->addModel(model);
    }
    else {
        CreateSampleScene(scene);
    }

    auto x = renderer->isKindOf<vine::Object>();
    auto y = renderer->toString();
    renderer->getCameraManipulator()->setVerticalAxisFixed(true);

#if defined(GLFW_VIEWER) or defined(SDL_VIEWER)
    renderer->setScene(scene);
    v.run();
#else
    renderer->setScene(scene);
    wnd.show();
    app.exec();
#endif
    return 0;
}