#pragma once

#include <glr/glr_global.h>

#include <glad/glad.h>

#include <glr/engine/Object.h>
#include <glr/engine/types.h>

namespace glr {
class GLR_API Camera : public Object {
    VI_OBJECT_META;

  public:
    Camera();

  public:
    Vec4f getClearColor() const;
    void  setClearColor(const Vec4f& color);

    GLdouble getClearDepth() const;
    void     setClearDepth(GLdouble depth);

    GLint getClearStencil() const;
    void  setClearStencil(GLint val);

    GLbitfield getClearMask() const;
    void       setClearMask(GLbitfield mask);

    void getViewMatrixAsLookAt(Vec3d& o_posi, Vec3d& o_target, Vec3d& o_up, double distance = 1.);
    void setViewMatrixAsLookAt(const Vec3d& posi, const Vec3d& target, const Vec3d& up);

    void  setViewMatrix(const Mat4d& mat);
    Mat4d getViewMatrix() const;

    Vec3d getViewDir() const;
    Vec3d getViewPos() const;
    Mat4d getInverseViewMatrix() const;

    void  setProjectionMatrix(const Mat4d& mat);
    Mat4d getProjectionMatrix() const;

    Mat4d getViewProjectionMatrix() const;

    void setViewport(int x, int y, int w, int h);
    void getViewport(int& x, int& y, int& w, int& h) const;

    void apply() const;
    void applyViewport() const;
    void applyAllExceptViewport() const;

  private:
    Mat4d      view_matrix_;
    Mat4d      proj_matrix_;
    Vec4f      clear_color_;
    GLdouble   clear_depth_;
    GLint      clear_stencil_;
    GLbitfield clear_mask_;
    GLint      vp_x_, vp_y_;
    GLsizei    vp_w_, vp_h_;
};
} // namespace glr