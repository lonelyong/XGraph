#include "SampleApplication.h"

#include <iostream>

#include <QApplication>
#include <QSurfaceFormat>

#include <xgcomm/Environment.h>

namespace xg {
namespace glr {
namespace {

bool s_is_qt_initialized = false;


} // namespace

SampleApplication::SampleApplication(const glr::AppParameters& params)
  : glr::Application(params) {
}

bool SampleApplication::initQt() {
    if (isQtInitialized()) {
        return true;
    }

    auto& params = getParameters();

    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(4);
    format.setVersion(params.gl_ver_maj, params.gl_ver_min);
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setColorSpace(QSurfaceFormat::ColorSpace::DefaultColorSpace);
    format.setRenderableType(QSurfaceFormat::RenderableType::OpenGL);

    QSurfaceFormat::setDefaultFormat(format);
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts, false);
    return true;
}



bool SampleApplication::isQtInitialized() const {
    return s_is_qt_initialized;
}

} // namespace glr
} // namespace xg