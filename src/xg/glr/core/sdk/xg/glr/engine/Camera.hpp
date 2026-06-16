#pragma once

#include <xg/glr/glr_global.hpp>

#include <xg/glr/engine/Object.h>
#include <xg/glr/engine/types.h>
#include <xg/glr/igl/GLdefs.h>

namespace xg {
namespace glr {
class State;
class GLR_API Camera : public Object {
    V_OBJECT_META_DECL

  public:
    Camera();

  public:
    Vec4f getClearColor() const;
    void  setClearColor(const Vec4f& color);

    GLdouble_t getClearDepth() const;
    void       setClearDepth(GLdouble_t depth);

    GLint_t getClearStencil() const;
    void    setClearStencil(GLint_t val);

    GLbitfield_t getClearMask() const;
    void         setClearMask(GLbitfield_t mask);

    void getViewMatrixAsLookAt(Vec3d& o_posi, Vec3d& o_target, Vec3d& o_up, double distance = 1.);
    void setViewMatrixAsLookAt(const Vec3d& posi, const Vec3d& target, const Vec3d& up);

    void  setViewMatrix(const Mat4d& mat);
    Mat4d getViewMatrix() const;

    Vec3d getViewPos() const;
    Vec3d getViewDir() const;
    Mat4d getInverseViewMatrix() const;

    void  setProjectionMatrix(const Mat4d& mat);
    Mat4d getProjectionMatrix() const;

    Mat4d getViewProjectionMatrix() const;

    void setViewport(int x, int y, int w, int h);
    void getViewport(int& x, int& y, int& w, int& h) const;

    void apply(State& state) const;
    void applyViewport(State& state) const;
    void applyAllExceptViewport(State& state) const;

  private:
    Mat4d        view_matrix_;
    Mat4d        proj_matrix_;
    Vec4f        clear_color_;
    GLdouble_t   clear_depth_;
    GLint_t      clear_stencil_;
    GLbitfield_t clear_mask_;
    GLint_t      vp_x_, vp_y_;
    GLsizei_t    vp_w_, vp_h_;
};
} // namespace glr
} // namespace xg