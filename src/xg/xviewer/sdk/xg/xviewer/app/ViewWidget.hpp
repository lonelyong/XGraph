#pragma once

#include <QOpenGLWidget>

#include <osg/ref_ptr>

namespace xg {
namespace xviewer {

class Viewer;

class ViewWidget : public QOpenGLWidget {

  public:
    ViewWidget(QObject* parent = nullptr);

  public:
    void    setViewer(Viewer* viewer);
    Viewer* getViewer() const;

  protected:
    virtual void initializeGL() override;
    virtual void resizeGL(int w, int h) override;
    virtual void paintGL() override;

    void         resizeEvent(QResizeEvent* e) override;
    virtual void closeEvent(QCloseEvent* event) override;
    virtual void keyPressEvent(QKeyEvent* event) override;
    virtual void keyReleaseEvent(QKeyEvent* event) override;

    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void wheelEvent(QWheelEvent* event) override;
    virtual bool event(QEvent* event) override;

  private:
    bool isValid() const;

  private:
    osg::ref_ptr<Viewer> viewer_;
    bool                 first_frame_ = true;
};

} // namespace xviewer
} // namespace xg