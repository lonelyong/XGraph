#include "QtMainWindow.hpp"

#include <QMenuBar>
#include <QStatusBar>

#include "QtViewer.hpp"


namespace xg {
namespace glr {
struct QtMainWindow::Data {
    QtViewer* viewer;
};

QtMainWindow::QtMainWindow()
  : d(new Data) {
    auto viewer = new QtViewer();
    
    auto menu_bar = new QMenuBar();
    {
        auto file_menu = menu_bar->addMenu("File");
        file_menu->addAction("Open");
        file_menu->addAction("Save");
        file_menu->addAction("Exit");
    }

    auto status_bar = new QStatusBar();
    
    setGeometry(100, 100, 800, 600);

    setMenuBar(menu_bar);
    setCentralWidget(viewer);
    setStatusBar(status_bar);

    d->viewer = viewer;
}

QtMainWindow::~QtMainWindow() {
    delete d;
}

QtViewer* QtMainWindow::getViewer() const {
    return d->viewer;
}
} // namespace glr
} // namespace xg