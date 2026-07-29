#pragma once

#include <xg/igl/glr_global.hpp>

#include <QMainWindow>

namespace xg
{
namespace glr
{

class QtViewer;

class QtMainWindow : public QMainWindow {
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
} // namespace xg