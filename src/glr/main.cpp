#include <QApplication>
#include <Windows.h>

#include <iostream>

#include <glm/ext.hpp>

#include <vine/core/Ptr.h>
#include <vine/ge/Rect2d.h>

#include <xgcomm/Resources.h>

#include <glr/app/AppInitializer.h>
#include <glr/app/ResourceManager.h>
#include <glr/engine/Camera.h>
#include <glr/engine/CameraManipulator.h>
#include <glr/engine/CubeMap.h>
#include <glr/engine/FrameBufferObject.h>
#include <glr/engine/GraphicContext.h>
#include <glr/engine/Image.h>
#include <glr/engine/Light.h>
#include <glr/engine/Material.h>
#include <glr/engine/Renderer.h>
#include <glr/engine/RttRenderer.h>
#include <glr/engine/Shader.h>
#include <glr/engine/SkyBox.h>
#include <glr/engine/StateSet.h>
#include <glr/engine/Texture2D.h>
#include <glr/engine/Uniform.h>
#include <glr/io/ImageLoader.h>
#include <glr/io/MeshLoader.h>
#include <glr/io/PointCloudLoader.h>
#include <glr/scene/Geometry.h>
#include <glr/scene/Model.h>
#include <glr/scene/Scene.h>
#include <glr/viewer/GlfwViewer.h>
#include <glr/viewer/QtMainWindow.h>
#include <glr/viewer/QtViewer.h>
#include <glr/viewer/Viewer.h>

void CreateSampleShapes(glr::Scene* scene) {
    using ResMgr = glr::ResourceManager;
    auto resmgr  = ResMgr::instance();

    auto axis = new glr::Model();
    {
        auto geom     = new glr::Geometry();
        auto vertices = new glr::Vec3fArray();
        {
            vertices->push_back(glr::Vec3f());
            vertices->push_back(glr::Vec3f(10, 0, 0));
            vertices->push_back(glr::Vec3f());
            vertices->push_back(glr::Vec3f(0, 10, 0));
            vertices->push_back(glr::Vec3f());
            vertices->push_back(glr::Vec3f(0, 0, 10));
        }
        geom->addVertexAttribArray(0, vertices);
        auto colors = new glr::Vec4fArray();
        {
            colors->emplace_back(1.f, 0.f, 0.0f, 1.0f);
            colors->emplace_back(1.f, 0.f, 0.0f, 1.0f);
            colors->emplace_back(0.f, 1.f, 0.0f, 1.0f);
            colors->emplace_back(0.f, 1.f, 0.0f, 1.0f);
            colors->emplace_back(0.f, 0.f, 1.0f, 1.0f);
            colors->emplace_back(0.f, 0.f, 1.0f, 1.0f);
        }
        geom->addVertexAttribArray(2, colors);
        geom->addPrimitiveSet(new glr::DrawArrays(glr::PrimitiveSet::MODE_LINES, 0, vertices->size()));
        axis->addDrawable(geom);
        axis->getOrCreateStateSet()->setAttribute(new glr::Material());
        axis->getOrCreateStateSet()->setShader(
            glr::ResourceManager::instance()->getInternalShader(glr::ResourceManager::IS_Base));
        axis->getOrCreateStateSet()->setAttribute(new glr::Uniform("use_texture", false));
    }

    auto cube = new glr::Model();
    {
        auto geom   = glr::Geometry::createCube(1, 0, 1, -1, 3);
        auto colors = new glr::Vec4fArray();
        colors->push_back({ 0.8f, 0.8f, 0.8f, 1.0f });
        geom->addVertexAttribArray(2, colors);
        auto tex = glr::ResourceManager::instance()->getInternalCubeMap(glr::ResourceManager::ICM_CubeMap1);
        geom->addTexture(GL_TEXTURE0, "tex", tex);

        auto light = new glr::Light();
        light->setPosition(glr::Vec4f(10, 10, 10, 1.));
        light->setDirection(glr::Vec3f(2, 4, -1));
        auto lights = new glr::Lights();
        lights->addLight(light);

        cube->addDrawable(geom);
        glr::Mat4d m1(1.);
        m1 = glm::rotate(m1, glm::radians(90.), glr::Vec3d(1.0, 0., 0.));
        cube->setMatrix(m1);
        cube->getOrCreateStateSet()->setAttribute(new glr::Material());
        cube->getOrCreateStateSet()->setAttribute(lights);
        cube->getOrCreateStateSet()->setShader(
            glr::ResourceManager::instance()->getInternalShader(glr::ResourceManager::IS_Geometry));
    }

    auto skybox = glr::createSkyBox(resmgr->getInternalCubeMap(ResMgr::ICM_CubeMap2));

    auto pc = new glr::Model();
    {
        auto geom     = new glr::Geometry();
        auto vertices = new glr::Vec3fArray();
        auto colors   = new glr::Vec3fArray();
        vertices->reserve(1000);
        colors->reserve(vertices->capacity());
        auto posi_offset = INT16_MAX / 10000.f / 2.f;
        for (size_t i = 0; i < vertices->capacity(); i++) {
            vertices->push_back({ rand() / 10000. - posi_offset, rand() / 10000. - posi_offset, rand() / 10000. });
            colors->push_back({ rand() / static_cast<double>(INT16_MAX),
                                rand() / static_cast<double>(INT16_MAX),
                                rand() / static_cast<double>(INT16_MAX) });
        }
        geom->addVertexAttribArray(0, vertices);
        geom->addVertexAttribArray(1, colors);
        geom->addPrimitiveSet(new glr::DrawArrays(glr::DrawArrays::MODE_POINTS, 0, vertices->size()));
        pc->addDrawable(geom);
        pc->getOrCreateStateSet()->setShader(resmgr->getInternalShader(ResMgr::IS_PointCloud));
    }


    auto img = new glr::Model();
    {
        auto tex = new glr::Texture2D();
        tex->setImage("f:\\Users\\sa\\Downloads\\1.jpg");
        auto geom_img =
            glr::Geometry::createTexturedQuad(0,
                                              1,
                                              3,
                                              vine::ge::Rect2d(0, 0, tex->getWidth() / 100., tex->getHeight() / 100.),
                                              vine::ge::Rect2d(0, 0, 1, 1));

        // auto colors = new glr::Vec4fArray();
        // colors->push_back(Vec4f(0,1,0,1));
        // geom_img->addVertexAttribArray(2, colors);

        geom_img->addTexture(0, "tex", tex);
        img->addDrawable(geom_img);
        img->getOrCreateStateSet()->setAttribute(new glr::Uniform("use_texture", true));
        img->getOrCreateStateSet()->setShader(resmgr->getInternalShader(ResMgr::IS_Base));
    }

    scene->addChild(axis);
    scene->addChild(pc);
    scene->addChild(cube);
    scene->addChild(skybox);
    scene->addChild(img);
}

int main(int argc, char** argv) {
    glr::AppInitializationParameters params;
    glr::AppInitializer              initializer(params);
    initializer.initGlfw();
    initializer.initGlad();
    initializer.initQt();

    auto scene = new glr::Scene();

#define RTT_VIEWER1
#define GLFW_VIEWER1

#ifdef GLFW_VIEWER
    glr::GlfwViewer v;
    v.initialize();
    auto renderer = v.getMasterRenderer();

#elif defined(RTT_VIEWER)
    auto                            viewer = new glr::Viewer();
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
    cam->setClearColor(Vec4f(0., 0., 0., 1.));
    cam->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    cam->setViewMatrixAsLookAt(Vec3f(5, 5, 5), Vec3f(), Vec3f(-1, 0, 1));
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

    viewer->addRenderer(renderer);

#else
    // QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication      app(argc, argv);
    glr::QtMainWindow wnd;
    auto              renderer = wnd.getViewer()->getMasterRenderer();
#endif

    if (argc > 1) {
        auto file  = argv[1];
        auto model = glr::MeshLoader().loadFile(file);
        auto light = new glr::Light();
        light->setPosition(glr::Vec4f(10, 10, 10, 1.));
        light->setDirection(glr::Vec3f(2, 4, -1));
        auto lights = new glr::Lights();
        lights->addLight(light);
        model->getOrCreateStateSet()->setAttribute(new glr::Material());
        model->getOrCreateStateSet()->setAttribute(lights);
        model->getOrCreateStateSet()->setAttribute(new glr::Uniform("use_texture", false));
        model->getOrCreateStateSet()->setShader(
            glr::ResourceManager::instance()->getInternalShader(glr::ResourceManager::IS_Base));
        scene->addChild(model);
    }
    else {
        CreateSampleShapes(scene);
    }

    auto x = renderer->isKindOf<vine::Object>();
    auto y = renderer->toString();
    std::cout << 1 << std::endl;

#ifdef GLFW_VIEWER
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
    app.exec();
#endif
    return 0;
}