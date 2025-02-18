#pragma once

#include <glr/glrenderer_global.h>

#include <glr/engine/Event.h>
#include <glr/engine/Object.h>
#include <glr/engine/types.h>

namespace glr {
class Camera;
class GLR_API CameraManipulator : public Object {
    VI_OBJECT_META;

  public:
    enum ProjectionType
    {
        Perspective,
        Orthographic
    };

    enum ViewMode
    {
        Top,
        Bottom,
        Left,
        Right,
        Front,
        Back
    };

  public:
    virtual bool handleEvent(Event* e) = 0;

    virtual ProjectionType getProjectionType() const              = 0;
    virtual void           setProjectionType(ProjectionType type) = 0;

    virtual double getFov() const     = 0;
    virtual void   setFov(double fov) = 0;

    virtual void getViewAsLookAt(Vec3d& eye, Vec3d& target, Vec3d& up)                   = 0;
    virtual void setViewAsLookAt(const Vec3d& eye, const Vec3d& target, const Vec3d& up) = 0;

    virtual void setViewMode(ViewMode mode) = 0;

    virtual Camera* getCamera() const = 0;

    virtual void setVerticalAxisFixed(bool fixed) = 0;
    virtual bool getVerticalAxisFixed() const     = 0;

    virtual void setHomePosition(const Vec3d& eye, const Vec3d& target, const Vec3d& up) = 0;
    virtual void getHomePosition(Vec3d& eye, Vec3d& target, Vec3d& up)                   = 0;
};

class GLR_API StandardCameraManipulator final : public CameraManipulator {
    VI_OBJECT_META;

  public:
    StandardCameraManipulator(Camera* cam);
    virtual ~StandardCameraManipulator();

  public:
    virtual bool handleEvent(Event* e) override;

    virtual ProjectionType getProjectionType() const override;
    virtual void           setProjectionType(ProjectionType type) override;

    virtual double getFov() const override;
    virtual void   setFov(double fov) override;

    virtual void getViewAsLookAt(Vec3d& eye, Vec3d& target, Vec3d& up) override;
    virtual void setViewAsLookAt(const Vec3d& eye, const Vec3d& target, const Vec3d& up) override;

    virtual void setViewMode(ViewMode mode) override;

    virtual Camera* getCamera() const override;

    virtual void setVerticalAxisFixed(bool fixed) override;
    virtual bool getVerticalAxisFixed() const override;

    virtual void setHomePosition(const Vec3d& eye, const Vec3d& target, const Vec3d& up) override;
    virtual void getHomePosition(Vec3d& eye, Vec3d& target, Vec3d& up) override;

    virtual void init(int w, int h);

  protected:
    virtual bool onUpdateViewport(int w, int h, int& vx, int& vy, int& vw, int& vh);

  private:
    virtual Mat4d computeViewMatrix() const;
    virtual Mat4d computeProjectionMatrix() const;

    void handleMousePressed(MouseButton btn, int x, int y);
    void handleMouseReleased(MouseButton btn, int x, int y);
    void handleMouseMoved(int x, int y);
    void handleMouseScrolled(int delta);
    void handleResized(int w, int h);

  private:
    VI_OBJECT_DATA;
};

} // namespace glr
