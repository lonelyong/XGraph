#include "Viewer.h"

#include <fstream>
#include <iosfwd>
#include <string>

#include <glad/glad.h>

#include <osg/Camera>
#include <osg/GraphicsContext>
#include <osg/Material>
#include <osg/Texture2D>
#include <osgDB/WriteFile>
#include <osgGA/FirstPersonManipulator>
#include <osgGA/StandardManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/TerrainManipulator>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#include <osgVerse/Pipeline/LightModule.h>
#include <osgVerse/Pipeline/Pipeline.h>
#include <osgVerse/Pipeline/ShadowModule.h>
#include <osgVerse/Pipeline/SkyBox.h>

#include "GLDebugOperation.h"
#include "PickerCamera.h"
#include <xgcomm/Resources.h>

namespace glv {
namespace {

class ViewerImpl : public osgViewer::Viewer {
  public:
    ViewerImpl(osgVerse::Pipeline* pipeline)
      : pipeline_(pipeline) {}

  protected:
    virtual osg::GraphicsOperation* createRenderer(osg::Camera* camera) override {
        if (pipeline_.valid())
            return pipeline_->createRenderer(camera);
        else
            return osgViewer::Viewer::createRenderer(camera);
    }

  private:
    osg::ref_ptr<osgVerse::Pipeline> pipeline_;
};
} // namespace

struct Viewer::Data {
    osg::ref_ptr<ViewerImpl>   impl;
    osg::ref_ptr<osg::Group>   root_node;
    osg::ref_ptr<PickerCamera> picker_cam;
};

Viewer::Viewer()
  : d(new Data()) {
    auto pipeline = osg::ref_ptr(new osgVerse::Pipeline());
    auto root     = osg::ref_ptr(new osg::Group());
    auto impl     = osg::ref_ptr(new ViewerImpl(pipeline));
    auto traits   = osg::ref_ptr(new osg::GraphicsContext::Traits());

    traits->x                    = 100;
    traits->y                    = 100;
    traits->width                = 1280;
    traits->height               = 720;
    traits->windowDecoration     = true;
    traits->supportsResize       = true;
    traits->doubleBuffer         = true;
    traits->depth                = 24;
    traits->samples              = 4;
    traits->screenNum            = 0;
    traits->glContextProfileMask = GL_CONTEXT_COMPATIBILITY_PROFILE_BIT;
    //  在使用gl3编译时使用
    // traits->glContextVersion     = "3.3";

    traits->windowName = "ModelViewer";

    auto gc  = osg::ref_ptr(osg::GraphicsContext::createGraphicsContext(traits));
    // false: gl_Vertex=0,gl_Normal=2,gl_Color=3
    // true : gl_Vertex=0,gl_Normal=1,gl_Color=2
    // default: true
    // gc->getState()->resetVertexAttributeAlias(false);
    //// gc->getState()->setUseVertexAttributeAliasing(true);
    // gc->getState()->setUseModelViewAndProjectionUniforms(true);
    //// 使resetVertexAttributeAlias所作的映射生效
    // gc->getState()->setUseVertexAttributeAliasing(true);
    auto cam = impl->getCamera();
    cam->setGraphicsContext(gc);
    cam->setViewport(0, 0, traits->width, traits->height);
    cam->setProjectionMatrixAsPerspective(30, (double)traits->width / traits->height, 1, 1000);
    cam->setViewMatrixAsLookAt(osg::Vec3d(200, 200, 200), osg::Vec3d(), osg::Vec3d(-1, 0, 1));

    using Camm = osgGA::TrackballManipulator;

    auto camm = osg::ref_ptr(new Camm(Camm::DEFAULT_SETTINGS | Camm::SET_CENTER_ON_WHEEL_FORWARD_MOVEMENT));
    camm->setAutoComputeHomePosition(true);
    camm->setByMatrix(cam->getViewMatrix());
    camm->setVerticalAxisFixed(true);

    auto picker_cam = osg::ref_ptr(new PickerCamera());
    picker_cam->setGraphicsContext(gc);

    impl->setCameraManipulator(camm);
    impl->setCamera(cam);
    impl->addEventHandler(new osgViewer::StatsHandler());
    impl->addEventHandler(new osgViewer::WindowSizeHandler());
    impl->addEventHandler(new osgGA::StateSetManipulator(cam->getOrCreateStateSet()));
    impl->setThreadingModel(osgViewer::Viewer::SingleThreaded);
    impl->setSceneData(root);
    impl->setRealizeOperation(new GLDebugOperation());
    impl->setLightingMode(osg::View::HEADLIGHT);

    auto fn_create_shader = [](const char* file) {
        std::ifstream ifs(file);
        if (ifs.is_open()) {
            std::ostringstream ss;
            ss << ifs.rdbuf();
            return ss.str();
        }
        return std::string();
    };

    auto root_prog = osg::ref_ptr(new osg::Program());
    root_prog->addShader(new osg::Shader(osg::Shader::VERTEX, fn_create_shader(XG_RES("shaders/phong.comp.vs.glsl"))));
    root_prog->addShader(
        new osg::Shader(osg::Shader::FRAGMENT, fn_create_shader(XG_RES("shaders/phong.comp.fs.glsl"))));

    auto root_mat = osg::ref_ptr(new osg::Material());
    root_mat->setColorMode(osg::Material::AMBIENT_AND_DIFFUSE);

    root->getOrCreateStateSet()->setAttributeAndModes(root_prog, osg::StateAttribute::ON);
    root->getOrCreateStateSet()->setAttributeAndModes(root_mat, osg::StateAttribute::ON);
    root->getOrCreateStateSet()->setMode(GL_LIGHTING, 1);
    root->getOrCreateStateSet()->setMode(GL_LIGHT1, 1);
    root->getOrCreateStateSet()->setMode(GL_LIGHT0, 0);

    auto main_light = new osg::Light();
    main_light->setAmbient(osg::Vec4(1, 1, 0, 1));
    main_light->setDiffuse(osg::Vec4(1, 0, 0, 1));
    main_light->setLightNum(1);
    main_light->setDataVariance(osg::Object::DYNAMIC);
    main_light->setPosition(osg::Vec4(0, 1, 0, 0));

    // auto main_ls = new osg::LightSource();
    // main_ls->setLight(main_light);
    // root->addChild(main_ls);

    root->getOrCreateStateSet()->setAttributeAndModes(main_light, 1);

    // gc->getState()->setGlobalDefaultAttribute(main_light);

    struct RootNodeUpdateCallback : public osg::NodeCallback {
        virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override {
            osg::Vec3d eye, target, up, dir;
            cam_->getViewMatrixAsLookAt(eye, target, up);
            dir = target - eye;
            dir.normalize();
            light_->setPosition(osg::Vec4(dir.x(), dir.y(), dir.z(), 0.));
        }
        osg::ref_ptr<osg::Camera> cam_;
        osg::ref_ptr<osg::Light>  light_;
    };

    auto callback    = new RootNodeUpdateCallback();
    callback->cam_   = cam;
    callback->light_ = main_light;

    root->addUpdateCallback(callback);

    d->root_node  = root;
    d->impl       = impl;
    d->picker_cam = picker_cam;

    // addCamera(picker_cam, true, true, true, true);

    //// Main light
    // auto light0 = new osgVerse::LightDrawable;
    // light0->setColor(osg::Vec3(1.0f, 1.0f, 1.0f));
    // light0->setDirection(osg::Vec3(0.02f, 0.1f, -1.0f));
    // light0->setDirectional(true);
    // light0->setEyeSpace(false);

    // auto light1 = new osgVerse::LightDrawable;
    // light1->setColor(osg::Vec3(1.5f, 1.5f, 1.5f));
    // light1->setDirection(osg::Vec3(1.f, 0.1f, 0.0f));
    // light1->setDirectional(true);
    // light1->setEyeSpace(false);

    // auto lightGeode = new osg::Geode;
    // lightGeode->addDrawable(light0);
    //// lightGeode->addDrawable(light1);
    // addNode(lightGeode);

    // class ViewerEventCallback : public osgGA::GUIEventHandler {
    //   public:
    //     ViewerEventCallback(osgVerse::LightDrawable* light0)
    //       : light0_(light0) {}
    //     virtual bool handle(const osgGA::GUIEventAdapter& ea,
    //                         osgGA::GUIActionAdapter&      aa,
    //                         osg::Object*,
    //                         osg::NodeVisitor*) override {
    //         if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME) {
    //             osg::Vec3 eye, center, up, dir;
    //             aa.asView()->getCamera()->getViewMatrixAsLookAt(eye, center, up);
    //             // dir = center - eye;
    //             dir = -eye;
    //             dir.normalize();
    //             // dir = dir * osg::Matrix::rotate(osg::PI_4 / 4, up);
    //             light0_->setDirection(dir);
    //         }
    //         return false;
    //     }

    //  private:
    //    osgVerse::LightDrawable* light0_;
    //};

    // d->impl->addEventHandler(new ViewerEventCallback(light0));

    // osgVerse::StandardPipelineParameters params(SHADER_DIR, SKYBOX_DIR + "barcelona.hdr");
    // params.enablePostEffects = false;
    // params.enableAO          = false;
    ////osgVerse::setupStandardPipeline(pipeline, d->impl.get(), params);

    // // Post pipeline settings
    // //auto shadow = static_cast<osgVerse::ShadowModule*>(pipeline->getModule("Shadow"));
    // //if (shadow && shadow->getFrustumGeode())
    // //{
    // //    setPipelineMask(shadow->getFrustumGeode(), FORWARD_SCENE_MASK);
    // //    addNode(shadow->getFrustumGeode());
    // //}

    // auto light = static_cast<osgVerse::LightModule*>(pipeline->getModule("Light"));
    // if (light) light->setMainLight(light0, "Shadow");
}

void Viewer::run() {
    d->impl->run();
}

void Viewer::addNode(osg::Node* node) {
    osgVerse::TangentSpaceVisitor tsv;
    node->accept(tsv);
    d->root_node->addChild(node);
}

void Viewer::addCamera(osg::Camera* cam,
                       bool         useMasterSceneData,
                       bool         useMasterViewMatrix,
                       bool         useMasterProjMatrix,
                       bool         useMasterViewport) {
    d->impl->addSlave(cam, useMasterSceneData);

    if (useMasterViewMatrix || useMasterProjMatrix || useMasterViewport) {
        struct UpdateCallback : osg::NodeCallback {
            UpdateCallback(osg::Camera* master,
                           osg::Camera* slave,
                           bool         useMasterViewMatrix,
                           bool         useMasterProjMatrix,
                           bool         useMasterViewport)
              : master_(master)
              , slave_(slave)
              , use_mas_view_(useMasterViewMatrix)
              , use_mas_proj_(useMasterProjMatrix)
              , use_mas_vp_(useMasterViewport) {}

            osg::Camera *master_, *slave_;
            bool         use_mas_view_, use_mas_proj_, use_mas_vp_;

            virtual void operator()(osg::Node* node, osg::NodeVisitor* nv) override {
                auto cam = node->asCamera();
                if (use_mas_view_) {
                    cam->setViewMatrix(master_->getViewMatrix());
                }
                if (use_mas_proj_) {
                    cam->setViewMatrix(master_->getProjectionMatrix());
                }
                if (use_mas_vp_) {
                    auto vp = master_->getViewport();
                    cam->setViewport(vp->x(), vp->y(), vp->width(), vp->height());
                }
            }
        };

        cam->addUpdateCallback(
            new UpdateCallback(getMasterCamera(), cam, useMasterViewMatrix, useMasterProjMatrix, useMasterViewport));
    }
}

void Viewer::fitToScreen() {
    auto cm = d->impl->getCameraManipulator();
    cm->computeHomePosition(d->impl->getCamera());
    cm->home(0);
    cm->setByMatrix(cm->getMatrix() * osg::Matrix::rotate(osg::inRadians(45), osg::Vec3d(1, 0, 0)));
    auto x = cm->getInverseMatrix();
}

osg::Camera* Viewer::getMasterCamera() const {
    return d->impl->getCamera();
}
} // namespace glv