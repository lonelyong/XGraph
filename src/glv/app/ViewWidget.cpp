#include "ViewWidget.h"

#include "Viewer.h"

namespace glv {


WiewWidget::WiewWidget(QObject* parent /*= nullptr*/)
{
    viewer_ = new Viewer();
}

void WiewWidget::initializeGL() {
}

void WiewWidget::resizeGL(int w, int h) {
}

void WiewWidget::paintGL() {
}

void WiewWidget::resizeEvent(QResizeEvent* e) {
}

void WiewWidget::mousePressEvent(QMouseEvent* event) {
}

void WiewWidget::mouseReleaseEvent(QMouseEvent* event) {
}

void WiewWidget::mouseDoubleClickEvent(QMouseEvent* event) {
}

void WiewWidget::mouseMoveEvent(QMouseEvent* event) {
}

void WiewWidget::wheelEvent(QWheelEvent* event) {
}

} // namespace glv
