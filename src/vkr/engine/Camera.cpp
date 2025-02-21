#include <vkr/engine/Camera.h>

#include <glm/ext.hpp>

namespace vkr {
VI_OBJECT_META_IMPL(Camera, Object);

Camera::Camera()
  : clear_depth_(1.0)
  , clear_stencil_(1)
  , clear_color_(0.f, 0.f, 0.f, 1.f)
  , clear_mask_(0)
  , vp_x_(0.)
  , vp_y_(0.)
  , vp_w_(800)
  , vp_h_(600) {
    view_matrix_ = glm::lookAt<double>(Vec3d(10., 10., 10.), Vec3d(0., 0., 0.), Vec3d(-1., 0., 1.));
    proj_matrix_ = glm::perspective<double>(glm::radians(30.0), vp_w_ / vp_h_, 0.1, 1000.0);
}

Vec4f Camera::getClearColor() const {
    return clear_color_;
}
void Camera::setClearColor(const Vec4f& color) {
    clear_color_ = color;
}

double Camera::getClearDepth() const {
    return clear_depth_;
}
void Camera::setClearDepth(double depth) {
    clear_depth_ = depth;
}

int Camera::getClearStencil() const {
    return clear_stencil_;
}
void Camera::setClearStencil(int val) {
    clear_stencil_ = val;
}

int Camera::getClearMask() const {
    return clear_mask_;
}
void Camera::setClearMask(int mask) {
    clear_mask_ = mask;
}

void Camera::setViewMatrixAsLookAt(const Vec3d& posi, const Vec3d& target, const Vec3d& up) {
    view_matrix_ = glm::lookAt(posi, target, up);
}
void Camera::getViewMatrixAsLookAt(Vec3d& o_posi, Vec3d& o_target, Vec3d& o_up, double distance) {
    auto& m  = view_matrix_;
    o_posi   = -Vec3d(m[3][0], m[3][1], m[3][2]);
    o_up     = Vec3d(m[1][0], m[1][1], m[1][2]);
    auto dir = -Vec3d(m[2][0], m[2][1], m[2][2]);
    dir.x *= distance;
    dir.y *= distance;
    dir.z *= distance;
    o_target = o_posi + dir;
}

void Camera::setViewMatrix(const Mat4d& mat) {
    view_matrix_ = mat;
}
Mat4d Camera::getViewMatrix() const {
    return view_matrix_;
}
Mat4d Camera::getInverseViewMatrix() const {
    return glm::inverse(view_matrix_);
}

Vec3d Camera::getViewDir() const {
    return -Vec3d(view_matrix_[2][0], view_matrix_[2][1], view_matrix_[2][2]);
}
Vec3d Camera::getViewPos() const {
    return -Vec3d(view_matrix_[3][0], view_matrix_[3][1], view_matrix_[3][2]);
}

void Camera::getViewport(int& x, int& y, int& w, int& h) const {
    x = vp_x_;
    y = vp_y_;
    w = vp_w_;
    h = vp_h_;
}
void Camera::setViewport(int x, int y, int w, int h) {
    vp_x_ = x;
    vp_y_ = y;
    vp_w_ = w;
    vp_h_ = h;
    // glViewport(x, y, w, h);
}

void Camera::setProjectionMatrix(const Mat4d& mat) {
    proj_matrix_ = mat;
}
Mat4d Camera::getProjectionMatrix() const {
    return proj_matrix_;
}
Mat4d Camera::getViewProjectionMatrix() const {
    // glm 矩阵行优先
    return proj_matrix_ * view_matrix_;
}

void Camera::apply() const {
    applyViewport();
    applyAllExceptViewport();
}
void Camera::applyViewport() const {
    //glViewport(vp_x_, vp_y_, vp_w_, vp_h_);
    //glScissor(vp_x_, vp_y_, vp_w_, vp_h_);
    //glEnable(GL_SCISSOR_TEST);
}
void Camera::applyAllExceptViewport() const {
    //glClearColor(clear_color_.r, clear_color_.g, clear_color_.b, clear_color_.a);
    //glClearDepth(clear_depth_);
    //glClearStencil(clear_stencil_);
    //glClear(clear_mask_);
}
} // namespace vkr