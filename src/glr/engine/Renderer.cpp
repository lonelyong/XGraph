#include <glr/engine/Renderer.h>

#include <functional>

#include <vine/Ptr.hpp>

#include <glr/engine/Camera.h>
#include <glr/engine/CameraManipulator.h>
#include <glr/engine/GraphicContext.h>
#include <glr/engine/RenderInfo.h>
#include <glr/engine/State.h>
#include <glr/scene/Drawable.h>
#include <glr/scene/Model.h>
#include <glr/scene/Scene.h>

namespace glr {
V_OBJECT_META_IMPL(Renderer, Object);

struct Renderer::Data {
    vine::RefPtr<Camera>            camera;
    vine::RefPtr<GraphicContext>    ctx;
    vine::RefPtr<CameraManipulator> cm;
    vine::RefPtr<Scene>             scene;
    RenderOrder                     render_order;
    bool                            use_master_scene       = false;
    bool                            use_master_viewport    = false;
    bool                            use_master_view_matrix = false;
    bool                            use_master_proj_matrix = false;
    bool                            is_first_frame         = true;
    bool                            is_freezed             = false;
};

Renderer::Renderer()
  : d(new Data()) {
    auto cam  = new Camera();
    d->camera = cam;
}

Renderer::~Renderer() {
    delete d;
}

Camera* Renderer::getCamera() const {
    return d->camera.get();
}

void Renderer::setCamera(Camera* cam) {
    d->camera = cam;
}

GraphicContext* Renderer::getContext() const {
    return d->ctx.get();
}

void Renderer::setContext(GraphicContext* ctx) {
    d->ctx = ctx;
}

CameraManipulator* Renderer::getCameraManipulator() const {
    return d->cm.get();
}

void Renderer::setCameraManipulator(CameraManipulator* cm) {
    d->cm = cm;
}

int Renderer::render(RenderInfo& info) {
    if (!d->ctx || d->is_freezed) {
        return -1;
    }

    if (d->is_first_frame) {
        d->is_first_frame = false;
    }

    // glEnable(IGL_DEPTH_TEST);
    // glDepthFunc(IGL_LESS);
    // glDepthMask(IGL_TRUE);
    // glDepthRange(0.0, 1.0);

    auto master_renderer = info.getMasterRenderer();
    auto master_cam      = master_renderer->getCamera();
    auto cam             = d->camera.get();

    auto scene = d->use_master_scene ? master_renderer->getScene() : d->scene.get();
    if (!scene) {
        return 0;
    }

    if (d->use_master_viewport) {
        int x, y, w, h;
        master_cam->getViewport(x, y, w, h);
        cam->setViewport(w, y, w, h);
    }

    if (d->use_master_view_matrix) {
        cam->setViewMatrix(master_cam->getViewMatrix());
    }

    if (d->use_master_proj_matrix) {
        cam->setProjectionMatrix(master_cam->getProjectionMatrix());
    }


    auto& ctx   = *d->ctx;
    auto& state = *ctx.getState();

    ctx.makeCurrent();
    state.pushCamera(cam);

    auto nb_models = scene->getNumModels();
    for (size_t i = 0; i < nb_models; ++i) {
        auto model = vine::obj_cast<Model>(scene->getModelAt(i));

        if (!model) {
            continue;
        }

        auto matrix_m = model->getMatrix();
        auto stateset = model->getStateSet();
        state.pushStateSet(stateset);
        state.pushModelMatrix(matrix_m);
        state.apply();
        for (int j = 0; j < model->getNumDrawables(); ++j) {
            auto drawable = model->getDrawableAt(j);
            drawable->draw(state);
        }
        state.popModelMatrix();
        state.popStateSet(stateset);
    }
    state.popCamera(cam);
    return 0;
}

void Renderer::setRenderOrder(RenderOrder order) {
    d->render_order = order;
}

Renderer::RenderOrder Renderer::getRenderOrder() const {
    return d->render_order;
}

void Renderer::setScene(Scene* scene) {
    d->scene = scene;
}

Scene* Renderer::getScene() const {
    return d->scene.get();
}

void Renderer::setUseMasterScene(bool val) {
    d->use_master_scene = val;
}

bool Renderer::getUseMasterScene() const {
    return d->use_master_scene;
}

void Renderer::setUseMasterViewport(bool val) {
    d->use_master_viewport = val;
}

bool Renderer::getUseMasterViewport() const {
    return d->use_master_viewport;
}

void Renderer::setUseMasterViewMatrix(bool val) {
    d->use_master_view_matrix = val;
}

bool Renderer::getUseMasterViewMatrix() const {
    return d->use_master_view_matrix;
}

void Renderer::setUseMasterProjectionMatrix(bool val) {
    d->use_master_proj_matrix = val;
}

bool Renderer::getUseMasterProjectionMatrix() const {
    return d->use_master_proj_matrix;
}

void Renderer::setFreeze(bool val) {
    d->is_freezed = val;
}

bool Renderer::getFreezed() const {
    return d->is_freezed;
}

bool Renderer::handleEvent(Event* e) {
    auto handled = EventReceiver::handleEvent(e);

    if (false == handled) {
        if (d->cm.hasValue()) {
            handled |= d->cm->handleEvent(e);
        }
    }

    if (false == handled) {
        if (d->scene.hasValue()) {
            handled |= d->scene->handleEvent(e);
        }
    }

    return handled;
}

void Renderer::update(UpdateContext* ctx) {
    EventReceiver::update(ctx);
    if (d->scene.hasValue()) {
        d->scene->update(ctx);
    }
}
} // namespace glr