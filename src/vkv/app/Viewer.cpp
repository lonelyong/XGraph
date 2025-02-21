#include "Viewer.h"

#include <fstream>
#include <iosfwd>
#include <string>

#include <vsg/app/Camera.h>
#include <vsg/app/CloseHandler.h>
#include <vsg/app/RenderGraph.h>
#include <vsg/app/Trackball.h>
#include <vsg/app/View.h>
#include <vsg/app/Viewer.h>
#include <vsg/app/Window.h>
#include <vsg/app/WindowTraits.h>
#include <vsg/lighting/Light.h>
#include <vsg/nodes/Group.h>
#include <vsg/nodes/Node.h>

#include <xgcomm/Resources.h>


namespace vkv {
namespace {} // namespace

struct Viewer::Data {
    vsg::ref_ptr<vsg::Group>        root_node;
    vsg::ref_ptr<vsg::Camera>       camera;
    vsg::ref_ptr<vsg::Window>       window;
    vsg::ref_ptr<vsg::View>         view;
    vsg::ref_ptr<vsg::CommandGraph> cmd_graph;
    vsg::ref_ptr<vsg::RenderGraph>  render_graph;
};

Viewer::Viewer()
  : d(new Data()) {
    auto root   = vsg::ref_ptr(new vsg::Group());
    auto traits = vsg::ref_ptr(new vsg::WindowTraits());

    traits->x           = 100;
    traits->y           = 100;
    traits->width       = 1280;
    traits->height      = 720;
    traits->samples     = 4;
    traits->screenNum   = 0;
    traits->windowTitle = "ModelViewer-Vulkan";

    auto window = vsg::Window::create(traits);
    addWindow(window);

    auto lookAt      = vsg::LookAt::create(vsg::dvec3(100, 0, 0), vsg::dvec3(), vsg::dvec3(0.0, 0.0, 1.0));
    auto perspective = vsg::Perspective::create(30.0,
                                                static_cast<double>(window->extent2D().width) /
                                                    static_cast<double>(window->extent2D().height),
                                                0,
                                                1000);

    auto cam =
        vsg::ref_ptr(new vsg::Camera(perspective, lookAt, vsg::ref_ptr(new vsg::ViewportState(window->extent2D()))));

    auto headlight = vsg::createHeadlight();

    auto view = vsg::ref_ptr(new vsg::View(cam, root, vsg::RECORD_ALL));
    view->addChild(headlight);

    auto trackball = vsg::ref_ptr(new vsg::Trackball(cam));
    trackball->addWindow(window);

    auto render_graph = vsg::ref_ptr(new vsg::RenderGraph(window, view));
    render_graph->setClearValues(VkClearColorValue({ 1.0f, 1.0f, 1.0f, 1.0f }), VkClearDepthStencilValue({ 1.0f, 0 }));

    auto cmd_graph    = vsg::ref_ptr(new vsg::CommandGraph(window));
    cmd_graph->addChild(render_graph);

    assignRecordAndSubmitTaskAndPresentation({ cmd_graph });

    addEventHandler(trackball);
    addEventHandler(vsg::ref_ptr(new vsg::CloseHandler(this)));

    compile();

    d->root_node    = root;
    d->camera       = cam;
    d->window       = window;
    d->view         = view;
    d->cmd_graph    = cmd_graph;
    d->render_graph = render_graph;
}

void Viewer::run() {
    while (advanceToNextFrame()) {
        handleEvents();
        update();
        recordAndSubmit();
        present();
    }
}

void Viewer::addNode(vsg::ref_ptr<vsg::Node> node) {
    d->root_node->addChild(node);
}

void Viewer::fitToScreen() {
    // auto cm = d->impl->getCameraManipulator();
    // cm->computeHomePosition(d->impl->getCamera());
    // cm->home(0);
    // cm->setByMatrix(cm->getMatrix() * vsg::Matrix::rotate(vsg::inRadians(45), vsg::Vec3d(1, 0, 0)));
    // auto x = cm->getInverseMatrix();
}

} // namespace vkv