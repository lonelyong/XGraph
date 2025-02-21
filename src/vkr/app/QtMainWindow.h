#pragma once

#include <vkr/vkrenderer_global.h>

#include <QMainWindow>

namespace vkr {
class QtViewer;
class VKR_API QtMainWindow : public QMainWindow {
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
} // namespace vkr