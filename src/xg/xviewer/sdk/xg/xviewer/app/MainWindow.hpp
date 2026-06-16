#pragma once

#include <QMainWindow>

namespace xg {
namespace xviewer {

class Viewer;
class ViewWidget;

class MainWindow : public QMainWindow {
  public:
    MainWindow();
    virtual ~MainWindow();

  public:
    ViewWidget* getViewWidget() const;

  private:
    ViewWidget* vw_ = nullptr;
};
} // namespace xviewer
} // namespace xg