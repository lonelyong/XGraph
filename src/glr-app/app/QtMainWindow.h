#pragma once

#include <glr/glr_global.h>

#include <QMainWindow>

namespace glr {
class QtViewer;
class  QtMainWindow : public QMainWindow {
  public:
    QtMainWindow();
    virtual ~QtMainWindow();

  public:
    QtViewer* getViewer() const;

  protected:
  private:
    struct Data;
    Data* const d;
};
} // namespace glr