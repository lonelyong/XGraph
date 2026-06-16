#include "MainWindow.h"

#include "ViewWidget.h"
#include "Viewer.h"

namespace glv {
MainWindow::MainWindow() {

    vw_ = new ViewWidget();
    setCentralWidget(vw_);
}

MainWindow::~MainWindow() {
}

ViewWidget* MainWindow::getViewWidget() const {
    return vw_;
}
} // namespace glv