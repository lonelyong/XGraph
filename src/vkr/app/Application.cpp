#include "Application.h"

#include <iostream>

#include <GLFW/glfw3.h>

#include <QApplication>
#include <QSurfaceFormat>

#include <xgcomm/Environment.h>

namespace vkr {
namespace {

bool s_is_glfw_initialized = false;
bool s_is_glad_initialized = false;
bool s_is_qt_initialized   = false;

} // namespace

Application::Application(const AppInitializationParameters& params)
  : params_(params) {
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

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);
    glfwWindowHint(GLFW_DEPTH_BITS, 24);
    glfwWindowHint(GLFW_STENCIL_BITS, 8);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GL_TRUE);

    s_is_glfw_initialized = true;
    return true;
}

bool Application::initQt() {
    if (isQtInitialized()) {
        return true;
    }

    return true;
}

bool Application::isGlfwInitialized() const {
    return s_is_glfw_initialized;
}

bool Application::isQtInitialized() const {
    return s_is_qt_initialized;
}
} // namespace vkr