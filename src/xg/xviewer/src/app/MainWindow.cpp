#include <xg/xviewer/app/MainWindow.hpp>

#include <xg/xviewer/app/ViewWidget.hpp>
#include <xg/xviewer/app/Viewer.hpp>

namespace xg {
namespace xviewer {
MainWindow::MainWindow() {

    vw_ = new ViewWidget();
    setCentralWidget(vw_);
}

MainWindow::~MainWindow() {
}

ViewWidget* MainWindow::getViewWidget() const {
    return vw_;
}
} // namespace xviewer
} // namespace xg