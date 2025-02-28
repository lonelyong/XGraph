#include <iostream>

#include <QApplication>

#include <glad/glad.h>
#include <glm/ext.hpp>

#include <xgcomm/Resources.h>
#include <xgcomm/Text.h>

#include <glr/app/Application.h>
#include <glr/app/ExampleModels.h>
#include <glr/app/GeometryConfigurer.h>
#include <glr/app/GlfwViewer.h>
#include <glr/app/QtMainWindow.h>
#include <glr/app/QtViewer.h>
#include <glr/app/ResourceManager.h>
#include <glr/app/SdlViewer.h>
#include <glr/app/Viewer.h>
#include <glr/engine/Camera.h>
#include <glr/engine/CameraManipulator.h>
#include <glr/engine/Depth.h>
#include <glr/engine/FrameBufferObject.h>
#include <glr/engine/GraphicContext.h>
#include <glr/engine/PhongLight.h>
#include <glr/engine/PhongMaterial.h>
#include <glr/engine/Renderer.h>
#include <glr/engine/RttRenderer.h>
#include <glr/engine/State.h>
#include <glr/engine/StateSet.h>
#include <glr/engine/Texture2D.h>
#include <glr/engine/Uniform.h>
#include <glr/io/MeshLoader.h>
#include <glr/scene/Model.h>
#include <glr/scene/Scene.h>

void CreateSampleScene(glr::Scene* scene) {
    using namespace glr;
    //scene->addModel(ExampleModels::createAxis(20, Vec3d()));
    //scene->addModel(ExampleModels::createPointCloud(1000));
    //scene->addModel(ExampleModels::createCube(2, Vec3d(), true));
    scene->addModel(ExampleModels::createCube(3, Vec3d(5, 0, 0), false));
    //scene->addModel(ExampleModels::createSkyBox());
    //scene->addModel(ExampleModels::createImage("F:\\Users\\sa\\Downloads\\1.jpg"));
}

int main(int argc, char** argv) {
    glr::AppInitializationParameters params;
    params.mesa_always_software = true;

    glr::Application app(params);
    app.initGlfw();
    app.initGlad();
    app.initQt();

    auto         scene  = new glr::Scene();
    glr::Viewer* viewer = nullptr;

#define RTT_VIEWER1
#define GLFW_VIEWER1
#define SDL_VIEWER1

#ifdef GLFW_VIEWER
    glr::GlfwViewer v;
    if (!v.initialize()) {
        return -1;
    }
    viewer = &v;

#elif defined(SDL_VIEWER)
    glr::SdlViewer v;
    if (!v.initialize()) {
        return -1;
    }
    viewer = &v;
#elif defined(RTT_VIEWER)
    glr::Viewer                     v;
    glr::GraphicContextGlfw::Traits traits;
    traits.width   = 1;
    traits.height  = 1;
    traits.visible = false;

    auto ctx = glr::GraphicContextGlfw::create(traits);
    ctx->realize();
    ctx->makeCurrent();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_PROGRAM_POINT_SIZE);
    // glEnable(GL_CULL_FACE);
    glDisable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glDepthFunc(GL_LESS);

    auto renderer = new glr::RttRenderer();
    renderer->setContext(ctx);

    auto cam = renderer->getCamera();
    cam->setViewport(0., 0., 800, 600);
    cam->setClearDepth(1.0);
    cam->setClearStencil(1);
    cam->setClearColor(glr::Vec4f(0., 0., 0., 1.));
    cam->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    cam->setViewMatrixAsLookAt(glr::Vec3f(5, 5, 5), glr::Vec3f(), glr::Vec3f(-1, 0, 1));
    auto cm  = new glr::StandardCameraManipulator(cam);
    auto fbo = new glr::FrameBufferObject();

    auto comp_color = new glr::Texture2D();
    auto comp_depth = new glr::Texture2D();

    comp_color->setInternalFormat(glr::PixelData::IF_RGBA8);
    comp_color->setWidth(800);
    comp_color->setHeight(600);
    comp_depth->setWidth(800);
    comp_depth->setHeight(600);
    comp_depth->setInternalFormat(glr::PixelData::IF_DEPTH_COMPONENT24);

    fbo->attachTexture(glr::FrameBufferObject::COLOR_ATTACHMENT0, comp_color);
    fbo->attachTexture(glr::FrameBufferObject::DEPTH_ATTACHMENT, comp_depth);

    renderer->setFbo(fbo);
    renderer->setCameraManipulator(cm);

    v.addRenderer(renderer);
    viewer = &v;

#else
    // QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication      qapp(argc, argv);
    glr::QtMainWindow wnd;
    viewer = wnd.getViewer();
#endif

    if (argc > 1) {
        auto file  = xg::local8bitToUtf8(argv[1]);
        auto model = glr::MeshLoader().loadFile(file);
        if (model) {
            model->getOrCreateStateSet()->setShader(
                glr::ResourceManager::instance()->getInternalShader(glr::ResourceManager::EXAMPLE_SAHDER_STD_PHONG));
            scene->addModel(model);
            glr::GeometryConfigurer::configureStdPhong((glr::Geometry*)model->getDrawableAt(0),
                                                       model->getOrCreateStateSet());
        }
    }
    else {
        CreateSampleScene(scene);
    }

    auto light = new glr::PhongLight();
    light->setLightMode(glr::PhongLight::HEAD_LIGHT);
    light->setSpotCutoff(180);
    light->setSpotExponent(32);
    auto lights = new glr::PhongLights();
    lights->addLight(light);

    auto renderer = viewer->getMasterRenderer();

    renderer->getContext()->getState()->getDefaultStateSet()->setAttribute(lights);
    renderer->getContext()->getState()->getDefaultStateSet()->setAttribute(new glr::PhongMaterial());
    renderer->getContext()->getState()->getDefaultStateSet()->setAttribute(new glr::Depth(0, 1, glr::Depth::LEQUAL));
    renderer->getCameraManipulator()->setVerticalAxisFixed(true);


#if defined(GLFW_VIEWER) or defined(SDL_VIEWER)
    renderer->setScene(scene);
    v.run();
#elif defined(RTT_VIEWER)
    renderer->setScene(scene);
    while (true) {
        viewer->frame();
        fbo->bind(*ctx->getState());
        glReadBuffer(GL_COLOR_ATTACHMENT0);
        auto img = glr::Image::readPixels(0, 0, 800, 600, GL_RGBA, GL_UNSIGNED_BYTE);
        glr::ImageLoader().saveAsBmp(img, "d:/1.bmp");
    }
#else
    renderer->setScene(scene);
    wnd.show();
    qapp.exec();
#endif
    return 0;
}