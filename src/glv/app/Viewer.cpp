
#include "Viewer.h"

#include <fstream>
#include <iosfwd>
#include <string>

#include <osg/Camera>
#include <osg/GraphicsContext>
#include <osg/Material>
#include <osg/Texture2D>
#include <osgDB/WriteFile>
#include <osgGA/FirstPersonManipulator>
#include <osgGA/SphericalManipulator>
#include <osgGA/StandardManipulator>
#include <osgGA/StateSetManipulator>
#include <osgGA/TrackballManipulator>
#include <osgViewer/Viewer>
#include <osgViewer/ViewerEventHandlers>

#ifdef GLV_BUILD_WITH_OSGVERSE

#    include <osgVerse/Pipeline/LightModule.h>
#    include <osgVerse/Pipeline/Pipeline.h>
#    include <osgVerse/Pipeline/ShadowModule.h>
#    include <osgVerse/Pipeline/SkyBox.h>

#endif

#include <xgcomm/Resources.h>

#include <glr/igl/GLdefs.h>

#include <glv/app/Application.h>
#include <glv/app/CameraPicker.h>
#include <glv/app/RealizeOperation.h>
#include <glv/modeling/NodeMask.h>

namespace glv {
namespace {} // namespace

Viewer::Viewer() {
    auto root   = osg::ref_ptr(new osg::Group());
    auto traits = osg::ref_ptr(new osg::GraphicsContext::Traits());

    traits->x                = 100;
    traits->y                = 100;
    traits->width            = 1280;
    traits->height           = 720;
    traits->windowDecoration = true;
    traits->supportsResize   = true;
    traits->doubleBuffer     = true;
    traits->depth            = 24;
    traits->stencil          = 8;
    traits->samples          = 0;
    traits->screenNum        = 0;
    traits->windowName       = "ModelViewer";

    // 在使用GL3编译时使用(OSG_GL3_AVAILABLE=TRUE)
    // traits->glContextProfileMask = IGL_CONTEXT_COMPATIBILITY_PROFILE_BIT;
    // traits->glContextVersion     = "4.5";
    // traits->glContextFlags       = 0;

    // auto gc = osg::ref_ptr(osg::GraphicsContext::createGraphicsContext(traits));

    auto gc = osg::ref_ptr(new osgViewer::GraphicsWindowEmbedded(traits));

    // false: gl_Vertex=0,gl_Normal=2,gl_Color=3
    // true : gl_Vertex=0,gl_Normal=1,gl_Color=2
    // default: true
    gc->getState()->resetVertexAttributeAlias(false);
    gc->getState()->setUseModelViewAndProjectionUniforms(true);
    // 使resetVertexAttributeAlias所作的映射生效
    // 启用后
    // --N卡：如果resetVertexAttributeAlias(true)，固定功能管线模型法线有问题
    // --Intel|Mesa3d：固定功能管线模型法线有问题
    gc->getState()->setUseVertexAttributeAliasing(true);

    // 配置MasterCamera
    auto cam = getCamera();
    cam->setGraphicsContext(gc);
    cam->setViewport(0, 0, traits->width, traits->height);
    cam->setProjectionMatrixAsPerspective(30, (double)traits->width / traits->height, 1, 1000);
    cam->setViewMatrixAsLookAt(osg::Vec3d(200, 200, 200), osg::Vec3d(), osg::Vec3d(-1, 0, 1));
    cam->setClearColor(osg::Vec4(0, 0, 0, 1));
    cam->setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    using Camm = osgGA::TrackballManipulator;

    auto camm = osg::ref_ptr(new Camm(Camm::DEFAULT_SETTINGS /*| Camm::SET_CENTER_ON_WHEEL_FORWARD_MOVEMENT*/));
    camm->setAutoComputeHomePosition(true);
    camm->setByMatrix(cam->getViewMatrix());
    // camm->setVerticalAxisFixed(true);

    setCamera(cam);
    setCameraManipulator(camm);
    addEventHandler(new osgViewer::StatsHandler());
    addEventHandler(new osgGA::StateSetManipulator(cam->getOrCreateStateSet()));
    setThreadingModel(osgViewer::Viewer::SingleThreaded);
    setLightingMode(osg::View::HEADLIGHT);
    setSceneData(root);
    setRealizeOperation(new RealizeOperation());

    auto fn_create_shader = [](const char* file) {
        std::ifstream ifs(file);
        if (ifs.is_open()) {
            std::ostringstream ss;
            ss << ifs.rdbuf();
            return ss.str();
        }
        return std::string();
    };

    // auto root_prog = osg::ref_ptr(new osg::Program());
    // root_prog->addShader(new osg::Shader(osg::Shader::VERTEX, fn_create_shader(XG_RES("shaders/phong.comp.vs.glsl"))));
    // root_prog->addShader(
    //    new osg::Shader(osg::Shader::FRAGMENT, fn_create_shader(XG_RES("shaders/phong.comp.fs.glsl"))));

    auto root_mat = osg::ref_ptr(new osg::Material());
    root_mat->setColorMode(osg::Material::OFF);

    // root->getOrCreateStateSet()->setAttributeAndModes(root_prog, osg::StateAttribute::ON);
    root->getOrCreateStateSet()->setAttributeAndModes(root_mat, osg::StateAttribute::ON);
    root->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);

    // auto cam_picker = osg::ref_ptr(new CameraPicker());
    // cam_picker->setGraphicsContext(gc);

    gc_        = gc;
    root_node_ = root;
    // cam_picker_ = cam_picker;

    // addSlave(cam_picker_, true, true, true, true);

#ifdef GLV_BUILD_WITH_OSGVERSE
    initPipelineVerse();
#else
    initPipelineDefault();
#endif
}

void Viewer::addNode(osg::Node* node) {
    root_node_->addChild(node);
}

#ifdef GLV_BUILD_WITH_OSGVERSE
void Viewer::addNodeAsDeferred(osg::Node* node) {
    setAsDeferred(node);
    addNode(node);
}
void Viewer::addNodeAsForward(osg::Node* node) {
    setAsForward(node);
    addNode(node);
}
void Viewer::addNodeAsCustom(osg::Node* node) {
    setAsCustom(node);
    addNode(node);
}
#endif

void Viewer::addSlave(osg::Camera* cam,
                      bool         useMasterSceneData,
                      bool         useMasterViewMatrix,
                      bool         useMasterProjMatrix,
                      bool         useMasterViewport) {
    osgViewer::Viewer::addSlave(cam, useMasterSceneData);

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
            new UpdateCallback(getCamera(), cam, useMasterViewMatrix, useMasterProjMatrix, useMasterViewport));
    }
}

osg::GraphicsContext* Viewer::getGraphicsContext() const {
    return gc_.get();
}

void Viewer::initPipelineDefault() {
}

#ifdef GLV_BUILD_WITH_OSGVERSE
void Viewer::initPipelineVerse() {
    return;
    // Main light
    auto light0 = new osgVerse::LightDrawable;
    light0->setColor(osg::Vec3(1.0f, 1.0f, 1.0f));
    light0->setDirection(osg::Vec3(0.02f, 0.1f, -1.0f));
    light0->setDirectional(true);
    light0->setEyeSpace(false);

    // auto light1 = new osgVerse::LightDrawable;
    // light1->setColor(osg::Vec3(1.5f, 1.5f, 1.5f));
    // light1->setDirection(osg::Vec3(1.f, 0.1f, 0.0f));
    // light1->setDirectional(true);
    // light1->setEyeSpace(false);

    auto lightGeode = new osg::Geode;
    lightGeode->addDrawable(light0);
    // lightGeode->addDrawable(light1);
    addNode(lightGeode);

    class ViewerEventCallback : public osgGA::GUIEventHandler {
      public:
        ViewerEventCallback(osgVerse::LightDrawable* light0)
          : light0_(light0) {}

        virtual bool handle(const osgGA::GUIEventAdapter& ea,
                            osgGA::GUIActionAdapter&      aa,
                            osg::Object*,
                            osg::NodeVisitor*) override {
            if (ea.getEventType() == osgGA::GUIEventAdapter::FRAME) {
                osg::Vec3 eye, center, up, dir;
                aa.asView()->getCamera()->getViewMatrixAsLookAt(eye, center, up);
                // dir = center - eye;
                dir = -eye;
                dir.normalize();
                // dir = dir * osg::Matrix::rotate(osg::PI_4 / 4, up);
                light0_->setDirection(dir);
            }
            return false;
        }

      private:
        osgVerse::LightDrawable* light0_;
    };

    addEventHandler(new ViewerEventCallback(light0));

    osgVerse::StandardPipelineParameters params(SHADER_DIR, SKYBOX_DIR + "barcelona.hdr");
    params.enablePostEffects = false;
    params.enableAO          = false;

    pipeline_ = new osgVerse::Pipeline;
    osgVerse::setupStandardPipeline(pipeline_, this, params);

    // Post pipeline settings
    auto shadow = static_cast<osgVerse::ShadowModule*>(pipeline_->getModule("Shadow"));
    if (shadow && shadow->getFrustumGeode()) {
        // setPipelineMask(shadow->getFrustumGeode(), FORWARD_SCENE_MASK);
        // addNode(shadow->getFrustumGeode());
    }

    auto light = static_cast<osgVerse::LightModule*>(pipeline_->getModule("Light"));
    if (light) light->setMainLight(light0, "Shadow");
}
#endif

void Viewer::fitToScreen() {
    auto cm = getCameraManipulator();
    cm->computeHomePosition(getCamera());
    cm->home(0);
}

} // namespace glv