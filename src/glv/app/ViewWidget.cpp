#include "ViewWidget.h"

#include <QResizeEvent>

#include "Viewer.h"

namespace glv {

#define __RETURN_IF_INVALID__                                                                                          \
    if (!isValid()) return;

static int mapToOsgMouseButton(Qt::MouseButton btn) {
    if (btn & Qt::LeftButton) {
        return osgGA::GUIEventAdapter::LEFT_MOUSE_BUTTON;
    }
    else if (btn & Qt::MiddleButton) {
        return osgGA::GUIEventAdapter::MIDDLE_MOUSE_BUTTON;
    }
    else if (btn & Qt::RightButton) {
        return osgGA::GUIEventAdapter::RIGHT_MOUSE_BUTTON;
    }
    return 0;
}

static int mapToOsgKey(int key) {
    switch (key) {
    case Qt::Key_Escape: return osgGA::GUIEventAdapter::KEY_Escape;
    case Qt::Key_Tab: return osgGA::GUIEventAdapter::KEY_Tab;
    case Qt::Key_Backspace: return osgGA::GUIEventAdapter::KEY_BackSpace;
    case Qt::Key_Return: return osgGA::GUIEventAdapter::KEY_Return;
    case Qt::Key_Enter: return osgGA::GUIEventAdapter::KEY_Return;
    case Qt::Key_Insert: return osgGA::GUIEventAdapter::KEY_Insert;
    case Qt::Key_Delete: return osgGA::GUIEventAdapter::KEY_Delete;
    case Qt::Key_Pause: return osgGA::GUIEventAdapter::KEY_Pause;
    case Qt::Key_Print: return osgGA::GUIEventAdapter::KEY_Print;
    case Qt::Key_SysReq: return osgGA::GUIEventAdapter::KEY_Sys_Req;
    case Qt::Key_Clear: return osgGA::GUIEventAdapter::KEY_Clear;
    case Qt::Key_Home: return osgGA::GUIEventAdapter::KEY_Home;
    case Qt::Key_End: return osgGA::GUIEventAdapter::KEY_End;
    case Qt::Key_Left: return osgGA::GUIEventAdapter::KEY_Left;
    case Qt::Key_Up: return osgGA::GUIEventAdapter::KEY_Up;
    case Qt::Key_Right: return osgGA::GUIEventAdapter::KEY_Right;
    case Qt::Key_Down: return osgGA::GUIEventAdapter::KEY_Down;
    case Qt::Key_PageUp: return osgGA::GUIEventAdapter::KEY_Page_Up;
    case Qt::Key_PageDown: return osgGA::GUIEventAdapter::KEY_Page_Down;
    case Qt::Key_CapsLock: return osgGA::GUIEventAdapter::KEY_Caps_Lock;
    case Qt::Key_NumLock: return osgGA::GUIEventAdapter::KEY_Num_Lock;
    case Qt::Key_ScrollLock: return osgGA::GUIEventAdapter::KEY_Scroll_Lock;
    case Qt::Key_F1: return osgGA::GUIEventAdapter::KEY_F1;
    case Qt::Key_F2: return osgGA::GUIEventAdapter::KEY_F2;
    case Qt::Key_F3: return osgGA::GUIEventAdapter::KEY_F3;
    case Qt::Key_F4: return osgGA::GUIEventAdapter::KEY_F4;
    case Qt::Key_F5: return osgGA::GUIEventAdapter::KEY_F5;
    case Qt::Key_F6: return osgGA::GUIEventAdapter::KEY_F6;
    case Qt::Key_F7: return osgGA::GUIEventAdapter::KEY_F7;
    case Qt::Key_F8: return osgGA::GUIEventAdapter::KEY_F8;
    case Qt::Key_F9: return osgGA::GUIEventAdapter::KEY_F9;
    case Qt::Key_F10: return osgGA::GUIEventAdapter::KEY_F10;
    case Qt::Key_F11: return osgGA::GUIEventAdapter::KEY_F11;
    case Qt::Key_F12: return osgGA::GUIEventAdapter::KEY_F12;
    case Qt::Key_Space: return osgGA::GUIEventAdapter::KEY_Space;
    case Qt::Key_Exclam: return osgGA::GUIEventAdapter::KEY_Exclaim;
    case Qt::Key_QuoteDbl: return osgGA::GUIEventAdapter::KEY_Quotedbl;
    case Qt::Key_NumberSign: return osgGA::GUIEventAdapter::KEY_Hash;
    case Qt::Key_Dollar: return osgGA::GUIEventAdapter::KEY_Dollar;
    case Qt::Key_Percent: return (osgGA::GUIEventAdapter::KeySymbol)0x25; // '%'
    case Qt::Key_Ampersand: return osgGA::GUIEventAdapter::KEY_Ampersand;
    case Qt::Key_Apostrophe: return osgGA::GUIEventAdapter::KEY_Quote;
    case Qt::Key_ParenLeft: return osgGA::GUIEventAdapter::KEY_Leftparen;
    case Qt::Key_ParenRight: return osgGA::GUIEventAdapter::KEY_Rightparen;
    case Qt::Key_Asterisk: return osgGA::GUIEventAdapter::KEY_Asterisk;
    case Qt::Key_Plus: return osgGA::GUIEventAdapter::KEY_Plus;
    case Qt::Key_Comma: return osgGA::GUIEventAdapter::KEY_Comma;
    case Qt::Key_Minus: return osgGA::GUIEventAdapter::KEY_Minus;
    case Qt::Key_Period: return osgGA::GUIEventAdapter::KEY_Period;
    case Qt::Key_Slash: return osgGA::GUIEventAdapter::KEY_Slash;
    case Qt::Key_Colon: return osgGA::GUIEventAdapter::KEY_Colon;
    case Qt::Key_Semicolon: return osgGA::GUIEventAdapter::KEY_Semicolon;
    case Qt::Key_Less: return osgGA::GUIEventAdapter::KEY_Less;
    case Qt::Key_Equal: return osgGA::GUIEventAdapter::KEY_Equals;
    case Qt::Key_Greater: return osgGA::GUIEventAdapter::KEY_Greater;
    case Qt::Key_Question: return osgGA::GUIEventAdapter::KEY_Question;
    case Qt::Key_At: return osgGA::GUIEventAdapter::KEY_At;
    case Qt::Key_BracketLeft: return osgGA::GUIEventAdapter::KEY_Leftbracket;
    case Qt::Key_Backslash: return osgGA::GUIEventAdapter::KEY_Backslash;
    case Qt::Key_BracketRight: return osgGA::GUIEventAdapter::KEY_Rightbracket;
    case Qt::Key_AsciiCircum: return osgGA::GUIEventAdapter::KEY_Caret;
    case Qt::Key_Underscore: return osgGA::GUIEventAdapter::KEY_Underscore;
    case Qt::Key_QuoteLeft: return osgGA::GUIEventAdapter::KEY_Backquote;
    default: break;
    }
    return (osgGA::GUIEventAdapter::KeySymbol)key;
}

static int mapToOsgModifiers(Qt::KeyboardModifiers modifier) {
    switch (modifier) {
    case Qt::NoModifier: return 0;
    case Qt::ShiftModifier: return osgGA ::GUIEventAdapter::MODKEY_SHIFT;
    case Qt::ControlModifier: return osgGA ::GUIEventAdapter ::MODKEY_CTRL;
    case Qt::AltModifier: return osgGA ::GUIEventAdapter ::MODKEY_ALT;
    // case Qt::MetaModifier: break;
    // case Qt::KeypadModifier: break;
    // case Qt::GroupSwitchModifier: break;
    // case Qt::KeyboardModifierMask: break;
    default: break;
    }
    return 0;
}


ViewWidget::ViewWidget(QObject* parent /*= nullptr*/) {
    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setSamples(0);
    setFormat(format);

    this->setFocusPolicy(Qt::StrongFocus);
    this->setMinimumSize(320, 240);
    this->setMouseTracking(true);
}

void ViewWidget::setViewer(Viewer* viewer) {
    viewer_ = viewer;
}

Viewer* ViewWidget::getViewer() const {
    return viewer_.get();
}

void ViewWidget::initializeGL() {
    QOpenGLWidget::initializeGL();
}

void ViewWidget::resizeGL(int w, int h) {
    QOpenGLWidget::resizeGL(w, h);
}

void ViewWidget::paintGL() {
    if (isValid()) {
        auto cam = viewer_->getCamera();
        auto gc  = cam->getGraphicsContext();

        if (first_frame_) {
            auto def_fbo = defaultFramebufferObject();
            gc->setDefaultFboId(def_fbo);
            first_frame_ = false;
        }

        viewer_->frame();
    }
}

void ViewWidget::resizeEvent(QResizeEvent* event) {
    if (isValid()) {
        auto  ratio = this->screen()->devicePixelRatio();
        auto& size  = event->size();
        auto  cam   = viewer_->getCamera();
        auto  gc    = cam->getGraphicsContext();
        // 会更新gc下所有相机的Viewport与投影矩阵
        gc->resized(0, 0, size.width() * ratio, size.height() * ratio);

        auto gw = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            gw->getEventQueue()->windowResize(0, 0, size.width() * ratio, size.height() * ratio);
        }
    }
    QOpenGLWidget::resizeEvent(event);
}

void ViewWidget::closeEvent(QCloseEvent* event) {
    if (isValid()) {
        viewer_->setDone(true);
    }
    QOpenGLWidget::closeEvent(event);
}

void ViewWidget::keyPressEvent(QKeyEvent* event) {
    if (isValid()) {
        auto cam = viewer_->getCamera();
        auto gc  = cam->getGraphicsContext();
        auto gw  = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            gw->getEventQueue()->keyPress(mapToOsgKey(event->key()), mapToOsgModifiers(event->modifiers()));
        }
    }

    QOpenGLWidget::keyPressEvent(event);
}

void ViewWidget::keyReleaseEvent(QKeyEvent* event) {
    if (isValid()) {
        auto cam = viewer_->getCamera();
        auto gc  = cam->getGraphicsContext();
        auto gw  = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            gw->getEventQueue()->keyRelease(mapToOsgKey(event->key()), mapToOsgModifiers(event->modifiers()));
        }
    }
    QOpenGLWidget::keyReleaseEvent(event);
}

void ViewWidget::mousePressEvent(QMouseEvent* event) {
    if (isValid()) {
        auto ratio = this->screen()->devicePixelRatio();
        auto cam   = viewer_->getCamera();
        auto gc    = cam->getGraphicsContext();
        auto gw    = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            gw->getEventQueue()->mouseButtonPress(event->pos().x() * ratio,
                                                  event->pos().y() * ratio,
                                                  mapToOsgMouseButton(event->button()));
        }
    }

    QOpenGLWidget::mousePressEvent(event);
}

void ViewWidget::mouseReleaseEvent(QMouseEvent* event) {
    if (isValid()) {
        auto ratio = this->screen()->devicePixelRatio();
        auto cam   = viewer_->getCamera();
        auto gc    = cam->getGraphicsContext();
        auto gw    = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            gw->getEventQueue()->mouseButtonRelease(event->pos().x() * ratio,
                                                    event->pos().y() * ratio,
                                                    mapToOsgMouseButton(event->button()));
        }
    }

    QOpenGLWidget::mouseReleaseEvent(event);
}

void ViewWidget::mouseDoubleClickEvent(QMouseEvent* event) {
    if (isValid()) {
        auto ratio = this->screen()->devicePixelRatio();
        auto cam   = viewer_->getCamera();
        auto gc    = cam->getGraphicsContext();
        auto gw    = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            gw->getEventQueue()->mouseDoubleButtonPress(event->pos().x() * ratio,
                                                        event->pos().y() * ratio,
                                                        mapToOsgMouseButton(event->button()));
        }
    }

    QOpenGLWidget::mouseDoubleClickEvent(event);
}

void ViewWidget::mouseMoveEvent(QMouseEvent* event) {
    if (isValid()) {
        auto ratio = this->screen()->devicePixelRatio();
        auto cam   = viewer_->getCamera();
        auto gc    = cam->getGraphicsContext();
        auto gw    = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            gw->getEventQueue()->mouseMotion(event->pos().x() * ratio, event->pos().y() * ratio);
        }
    }

    QOpenGLWidget::mouseMoveEvent(event);
}

void ViewWidget::wheelEvent(QWheelEvent* event) {
    if (isValid()) {
        auto cam = viewer_->getCamera();
        auto gc  = cam->getGraphicsContext();
        auto gw  = dynamic_cast<osgViewer::GraphicsWindow*>(gc);
        if (gw) {
            auto delta  = event->pixelDelta().y();
            auto motion = (delta > 0) ? osgGA::GUIEventAdapter::SCROLL_UP : osgGA::GUIEventAdapter::SCROLL_DOWN;
            gw->getEventQueue()->mouseScroll(motion);
        }
    }

    QOpenGLWidget::wheelEvent(event);
}

bool ViewWidget::event(QEvent* event) {
    auto handled = QOpenGLWidget::event(event);
    switch (event->type()) {
    case QEvent::KeyPress:
    case QEvent::KeyRelease:
    case QEvent::MouseButtonDblClick:
    case QEvent::MouseButtonPress:
    case QEvent::MouseButtonRelease:
    case QEvent::MouseMove:
    case QEvent::Wheel: this->update(); break;
    default: break;
    }
    return handled;
}

bool ViewWidget::isValid() const {
    return viewer_.valid();
}

} // namespace glv
