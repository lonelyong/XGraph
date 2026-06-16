#include <xg/glr/app/Application.h>

#include <iostream>

#include <GLFW/glfw3.h>

#include <xgcomm/Environment.h>

namespace xg {
namespace glr {
namespace {

bool s_is_glfw_initialized = false;

static Application* s_app_inst = nullptr;

} // namespace

Application::Application(const AppParameters& params)
  : params_(params) {
    if (s_app_inst) {
        throw std::runtime_error("There should be only one application object.");
    }

    if (params.mesa_always_software) {
#ifdef _WIN32
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

bool Application::isGlfwInitialized() const {
    return s_is_glfw_initialized;
}

Application* Application::current() {
    return s_app_inst;
}
} // namespace glr
} // namespace xg