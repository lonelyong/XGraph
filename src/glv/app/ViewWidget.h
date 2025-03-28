#pragma once

#include <QOpenGLWidget>

#include "Viewer.h"

namespace glv {

class WiewWidget : public QOpenGLWidget {

  public:
    WiewWidget(QObject* parent = nullptr);

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
    osg::ref_ptr<Viewer> viewer_;
};

} // namespace glv