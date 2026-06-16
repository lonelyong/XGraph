#pragma once

#include <xg/glr/glr_global.h>

#include <QOpenGLWidget>

#include <xg/glr/app/Viewer.h>

namespace xg {
namespace glr {
class Viewer;
class QtViewer : public QOpenGLWidget, public Viewer {
  public:
    QtViewer();
    virtual ~QtViewer();

    virtual int frame() override;
    virtual int run() override;

  protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;
    void         resizeEvent(QResizeEvent* e) override;

    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void wheelEvent(QWheelEvent* event) override;

  private:
    struct Data;
    Data* const d;
};
} // namespace glr
} // namespace xg