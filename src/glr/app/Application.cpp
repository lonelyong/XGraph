#include "Application.h"

#include <iostream>

#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <QApplication>
#include <QSurfaceFormat>

#include <xgcomm/Environment.h>

namespace glr {
namespace {

bool s_is_glfw_initialized = false;
bool s_is_glad_initialized = false;
bool s_is_qt_initialized   = false;

} // namespace

Application::Application(const AppInitializationParameters& params)
  : params_(params) {
    if (params.mesa_always_software) {
#ifdef __WIN32
        _putenv_s("LIBGL_ALWAYS_SOFTWARE", "1");
        _putenv_s("MESA_LOADER_DRIVER_OVERRIDE", "swrast");
#endif
    }
}

bool Application::initGlfw() {
    if (isGlfwInitialized()) {
        return true;
    }

    if (glfwInit() == GLFW_FALSE) {
        std::cout << "Failed to initialize GLFW." << std::endl;
        return false;
    }

    printf("Initialization of GLFW succeeded\n");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, params_.gl_ver_maj);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, params_.gl_ver_min);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_STENCIL_BITS, 8);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);

    if (params_.gl_use_core_profile) {
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
    else {
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
    }

    s_is_glfw_initialized = true;
    return true;
}

bool Application::initGlad() {
    if (isGladInitialized()) {
        return true;
    }
    if (!initGlfw()) return false;
    auto wnd = glfwCreateWindow(1, 1, "GladAppInitializer", NULL, NULL);

    if (!wnd) {
        std::cout << "Failed to create window using glfw." << std::endl;
        return false;
    }

    glfwMakeContextCurrent(wnd);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwDestroyWindow(wnd);
        std::cout << "Failed to initialize GLAD." << std::endl;
        return false;
    }

    printf("GL Version:%s\n", glGetString(GL_VERSION));
    printf("GL Vendor:%s\n", glGetString(GL_VENDOR));
    glfwMakeContextCurrent(nullptr);
    glfwDestroyWindow(wnd);
    printf("Initialization of GLAD succeeded\n");



    return true;
}

bool Application::initQt() {
    if (isQtInitialized()) {
        return true;
    }
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setSamples(4);
    format.setVersion(params_.gl_ver_maj, params_.gl_ver_min);
    format.setDepthBufferSize(24);
    format.setStencilBufferSize(8);
    format.setColorSpace(QSurfaceFormat::ColorSpace::DefaultColorSpace);
    format.setRenderableType(QSurfaceFormat::RenderableType::OpenGL);

    QSurfaceFormat::setDefaultFormat(format);
    QApplication::setAttribute(Qt::AA_ShareOpenGLContexts, false);
    return true;
}

bool Application::isGlfwInitialized() const {
    return s_is_glfw_initialized;
}

bool Application::isGladInitialized() const {
    return s_is_glad_initialized;
}

bool Application::isQtInitialized() const {
    return s_is_qt_initialized;
}
} // namespace glr