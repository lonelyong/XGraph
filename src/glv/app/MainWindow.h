#pragma once

#include <QMainWindow>

namespace glv {

class GraphicsContextQt;
class Viewer;

class MainWindow : public QMainWindow {
    MainWindow();

  private:
    GraphicsContextQt* main_gc_ = nullptr;
    Viewer*    viewer_;
};
} // namespace glv