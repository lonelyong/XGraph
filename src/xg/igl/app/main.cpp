#include <iostream>

#include <QApplication>
#include <glm/ext.hpp>

#include <xg/comm/Resources.hpp>
#include <xg/comm/Text.hpp>
#include <xg/igl/app/ExampleModels.hpp>
#include <xg/igl/app/GeometryConfigurer.hpp>
#include <xg/igl/app/ResourceManager.hpp>
#include <xg/igl/app/Viewer.hpp>
#include <xg/igl/engine/Camera.hpp>
#include <xg/igl/engine/CameraManipulator.hpp>
#include <xg/igl/engine/Depth.hpp>
#include <xg/igl/engine/FrameBufferObject.hpp>
#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/PhongLight.hpp>
#include <xg/igl/engine/PhongMaterial.hpp>
#include <xg/igl/engine/Renderer.hpp>
#include <xg/igl/engine/RttRenderer.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/engine/StateSet.hpp>
#include <xg/igl/engine/Texture2D.hpp>
#include <xg/igl/engine/Uniform.hpp>
#include <xg/igl/io/MeshLoader.hpp>
#include <xg/igl/scene/Model.hpp>
#include <xg/igl/scene/Scene.hpp>

#include "viewers/GlfwViewer.hpp"
#include "viewers/QtMainWindow.hpp"
#include "viewers/QtViewer.hpp"
#include "viewers/SampleApplication.hpp"
#include "viewers/SdlViewer.hpp"

using namespace xg;

void CreateSampleScene(xg::glr::Scene* scene)
{
    using namespace glr;
    scene->addModel(ExampleModels::createAxis(20, Vec3d()));
    scene->addModel(ExampleModels::createPointCloud(1000));
    scene->addModel(ExampleModels::createCube(2, Vec3d(), true));
    scene->addModel(ExampleModels::createCube(3, Vec3d(5, 0, 0), false));
    scene->addModel(ExampleModels::createSkyBox());
    scene->addModel(ExampleModels::createImage("F:\\Users\\sa\\Downloads\\1.jpg"));
}

int main(int argc, char** argv)
{
    xg::glr::AppParameters params;
    params.mesa_always_software = true;

    xg::glr::SampleApplication app(params);
    app.initGlfw();
    app.initQt();

    auto             scene  = new xg::glr::Scene();
    xg::glr::Viewer* viewer = nullptr;

#define RTT_VIEWER1
#define GLFW_VIEWER1
#define SDL_VIEWER1

#ifdef GLFW_VIEWER
    xg::glr::GlfwViewer v;
    if (!v.initialize()) { return -1; }
    viewer = &v;

#elif defined(SDL_VIEWER)
    xg::glr::SdlViewer v;
    if (!v.initialize()) { return -1; }
    viewer = &v;
#elif defined(RTT_VIEWER)
    xg::glr::Viewer                     v;
    xg::glr::GraphicContextGlfw::Traits traits;
    traits.width   = 1;
    traits.height  = 1;
    traits.visible = false;

    auto ctx = xg::glr::GraphicContextGlfw::create(traits);
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

    auto renderer = new xg::glr::RttRenderer();
    renderer->setContext(ctx);

    auto cam = renderer->getCamera();
    cam->setViewport(0., 0., 800, 600);
    cam->setClearDepth(1.0);
    cam->setClearStencil(1);
    cam->setClearColor(xg::glr::Vec4f(0., 0., 0., 1.));
    cam->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    cam->setViewMatrixAsLookAt(xg::glr::Vec3f(5, 5, 5), xg::glr::Vec3f(), xg::glr::Vec3f(-1, 0, 1));
    auto cm  = new xg::glr::StandardCameraManipulator(cam);
    auto fbo = new xg::glr::FrameBufferObject();

    auto comp_color = new xg::glr::Texture2D();
    auto comp_depth = new xg::glr::Texture2D();

    comp_color->setInternalFormat(xg::glr::PixelData::IF_RGBA8);
    comp_color->setWidth(800);
    comp_color->setHeight(600);
    comp_depth->setWidth(800);
    comp_depth->setHeight(600);
    comp_depth->setInternalFormat(xg::glr::PixelData::IF_DEPTH_COMPONENT24);

    fbo->attachTexture(xg::glr::FrameBufferObject::COLOR_ATTACHMENT0, comp_color);
    fbo->attachTexture(xg::glr::FrameBufferObject::DEPTH_ATTACHMENT, comp_depth);

    renderer->setFbo(fbo);
    renderer->setCameraManipulator(cm);

    v.addRenderer(renderer);
    viewer = &v;

#else
    // QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication          qapp(argc, argv);
    xg::glr::QtMainWindow wnd;
    viewer = wnd.getViewer();
#endif

    if (argc > 1) {
        auto file  = xg::local8bitToUtf8(argv[1]);
        auto model = xg::glr::MeshLoader().loadFile(file);
        if (model) {
            model->getOrCreateStateSet()->setShader(
                xg::glr::ResourceManager::instance()->getInternalShader(xg::glr::ResourceManager::EXAMPLE_SAHDER_STD_PHONG));
            scene->addModel(model);
            xg::glr::GeometryConfigurer::configureStdPhong((xg::glr::Geometry*)model->getDrawableAt(0), model->getOrCreateStateSet());
        }
    }
    else {
        CreateSampleScene(scene);
    }

    auto light = new xg::glr::PhongLight();
    light->setLightMode(xg::glr::PhongLight::HEAD_LIGHT);
    light->setSpotCutoff(180);
    light->setSpotExponent(32);
    auto lights = new xg::glr::PhongLights();
    lights->addLight(light);

    auto renderer = viewer->getMasterRenderer();

    renderer->getContext()->getState()->getDefaultStateSet()->setAttribute(lights);
    renderer->getContext()->getState()->getDefaultStateSet()->setAttribute(new xg::glr::PhongMaterial());
    renderer->getContext()->getState()->getDefaultStateSet()->setAttribute(new xg::glr::Depth(0, 1, xg::glr::Depth::LEQUAL));
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
        auto img = xg::glr::Image::readPixels(0, 0, 800, 600, GL_RGBA, GL_UNSIGNED_BYTE);
        xg::glr::ImageLoader().saveAsBmp(img, "d:/1.bmp");
    }
#else
    renderer->setScene(scene);
    wnd.show();
    qapp.exec();
#endif
    return 0;
}
