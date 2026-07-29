#include <xg/igl/engine/CameraManipulator.hpp>

#include <functional>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/ext.hpp>
#include <glm/gtx/norm.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/Camera.hpp>
#include <xg/igl/engine/Math.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(CameraManipulator, Object);
V_OBJECT_META_IMPL(StandardCameraManipulator, CameraManipulator);

static void fixVerticalAxis(Mat4d& mat);
static void fixVerticalAxis(Camera* cam);

struct StandardCameraManipulator::Data {
    vine::RefPtr<Camera> camera;
    bool                 is_rotation_started    = false;
    bool                 is_pan_started         = false;
    bool                 is_cursor_move_started = false;
    bool                 is_vertical_axis_fixed = false;
    int                  width = 800, height = 600;
    int                  vx = 0, vy = 0, vw = 800, vh = 600;
    double               near = 1., far = 4000., fov = 30.;
    ProjectionType       proj_type = Perspective;
    Vec2i                prev_cursor_pt;
    Vec2i                first_cursor_pt;
    Vec3d                eye, target, up;
    Vec3d                home_eye, home_target, home_up;
    // 默认以世界原点为center
    Vec3d rotation_center_world;
    Mat4d first_view_matrix;
};

StandardCameraManipulator::StandardCameraManipulator(Camera* cam)
  : d(new Data())
{
    d->camera = cam;
    if (d->is_vertical_axis_fixed) { fixVerticalAxis(cam); }
    d->camera->getViewMatrixAsLookAt(d->eye, d->target, d->up, d->far);
    d->camera->getViewport(d->vx, d->vy, d->vw, d->vh);

    d->home_eye    = d->eye;
    d->home_target = d->target;
    d->home_up     = d->up;
}

StandardCameraManipulator::~StandardCameraManipulator()
{ delete d; }

bool StandardCameraManipulator::handleEvent(Event* e)
{
    switch (e->getType()) {
    case EventType::EVENT_MOUSE_BUTTON_PRESS:
    {
        handleEVENT_MOUSE_BUTTON_PRESSed(e->getMouseButton(), e->getMouseX(), e->getMouseY());
        break;
    }
    case EventType::EVENT_MOUSE_MOVE:
    {
        handleEVENT_MOUSE_BUTTON_MOVEd(e->getMouseX(), e->getMouseY());
        break;
    }
    case EventType::EVENT_MOUSE_BUTTON_RELEASE:
    {
        handleEVENT_MOUSE_BUTTON_RELEASEd(e->getMouseButton(), e->getMouseX(), e->getMouseY());
        break;
    }
    case EventType::EVENT_MOUSE_WHEEL:
    {
        handleMouseScrolled(e->getMouseDelta());
        break;
    }
    case EventType::EVENT_WINDOW_RESIZE:
    {
        handleEVENT_WINDOW_RESIZEd(e->getWidth(), e->getHeight());
        break;
    }
    default: break;
    }
    return false;
}

CameraManipulator::ProjectionType StandardCameraManipulator::getProjectionType() const
{ return d->proj_type; };

void StandardCameraManipulator::setProjectionType(ProjectionType type)
{ d->proj_type = type; };

double StandardCameraManipulator::getFov() const
{ return d->fov; };

void StandardCameraManipulator::setFov(double fov)
{ d->fov = fov; };

void StandardCameraManipulator::getViewAsLookAt(Vec3d& eye, Vec3d& target, Vec3d& up)
{
    eye    = d->eye;
    target = d->target;
    up     = d->up;
};

void StandardCameraManipulator::setViewAsLookAt(const Vec3d& eye, const Vec3d& target, const Vec3d& up)
{
    d->eye    = eye;
    d->target = target;
    d->up     = up;
    d->camera->setViewMatrix(computeViewMatrix());
};

void StandardCameraManipulator::setViewMode(ViewMode mode)
{}

Camera* StandardCameraManipulator::getCamera() const
{ return d->camera.get(); }

void StandardCameraManipulator::setVerticalAxisFixed(bool fixed)
{
    d->is_vertical_axis_fixed = fixed;
    if (fixed) { fixVerticalAxis(d->camera.get()); }
}

bool StandardCameraManipulator::getVerticalAxisFixed() const
{ return d->is_vertical_axis_fixed; }

void StandardCameraManipulator::setHomePosition(const Vec3d& eye, const Vec3d& target, const Vec3d& up)
{
    d->home_eye    = eye;
    d->home_target = target;
    d->home_up     = up;
}

void StandardCameraManipulator::getHomePosition(Vec3d& eye, Vec3d& target, Vec3d& up)
{
    eye    = d->eye;
    target = d->target;
    up     = d->up;
};

bool StandardCameraManipulator::onUpdateViewport(int w, int h, int& vx, int& vy, int& vw, int& vh)
{
    vx = 0;
    vy = 0;
    vw = w;
    vh = h;
    return true;
}

Mat4d StandardCameraManipulator::computeViewMatrix() const
{ return glm::lookAt<double>(d->eye, d->target, d->up); }

Mat4d StandardCameraManipulator::computeProjectionMatrix() const
{
    if (d->proj_type == Perspective)
        return glm::perspective<double>(glm::radians<double>(d->fov), ((double)d->vw) / d->vh, d->near, d->far);
    else
        return glm::ortho<double>(-d->vw / 100., d->vw / 100., -d->vh / 100., d->vh / 100., d->near, d->far);
}

void StandardCameraManipulator::init(int w, int h)
{ handleEVENT_WINDOW_RESIZEd(w, h); }

void StandardCameraManipulator::handleEVENT_MOUSE_BUTTON_PRESSed(MouseButton btn, int x, int y)
{
    d->prev_cursor_pt.x  = x;
    d->prev_cursor_pt.y  = y;
    d->first_cursor_pt.x = x;
    d->first_cursor_pt.y = y;
    d->first_view_matrix = d->camera->getViewMatrix();

    switch (btn) {
    case MouseButton::BUTTON_LEFT:
    {
        d->is_rotation_started = true;
        d->is_pan_started      = false;
    } break;
    case MouseButton::BUTTON_MIDDLE:
    {
        d->is_pan_started      = true;
        d->is_rotation_started = false;
    } break;
    case MouseButton::BUTTON_RIGHT:
    {
    } break;
    default: break;
    }
}

void StandardCameraManipulator::handleEVENT_MOUSE_BUTTON_MOVEd(int x, int y)
{
    if (!d->is_pan_started && !d->is_rotation_started) { return; }

    auto xx = static_cast<double>(x);
    auto yy = static_cast<double>(y);
    auto dx = xx - d->first_cursor_pt.x;
    auto dy = yy - d->first_cursor_pt.y;
    auto vm = d->first_view_matrix;

    vm = d->camera->getViewMatrix();

    dx = xx - d->prev_cursor_pt.x;
    dy = yy - d->prev_cursor_pt.y;

    auto cam_in_world = glm::inverse(vm);
    //// 相机在世界坐标系中的姿态
    // auto cam_ori  = cam_in_world;
    // cam_ori[3][0] = 0;
    // cam_ori[3][1] = 0;
    // cam_ori[3][2] = 0;

    auto cam_ori         = glm::quat_cast(cam_in_world);
    auto cam_pos         = Vec3d(cam_in_world[3]);
    auto cam_up_local    = Vec3d(0, 1, 0);
    auto cam_right_local = Vec3d(1, 0, 0);
    auto cam_up_world    = cam_ori * cam_up_local;
    auto cam_right_world = cam_ori * cam_right_local;

    if (d->is_pan_started) {
        auto offset = Vec3d(dx / 100., -dy / 100., 0);
        // vm     = glm::translate(Mat4d(1.0), offset) * vm;
        vm          = glm::inverse(cam_in_world * glm::translate(Mat4d(1.0), -offset));
        d->camera->setViewMatrix(vm);
    }

    if (d->is_rotation_started) {
#if 0
        // Mat4d rotate_yaw(1.0);
        // Mat4d rotate_pitch(1.0);
        // rotate_yaw = glm::rotate(rotate_yaw, -glm::radians(dx / 10), Vec3d(cam_up_local.x, cam_up_local.y,
        // cam_up_local.z)); rotate_pitch =
        //     glm::rotate(rotate_pitch, -glm::radians(dy / 10), Vec3d(cam_right_local.x, cam_right_local.y,
        //     cam_right_local.z));

        //auto rotate_yaw   = glm::angleAxis(-glm::radians(dx / 10), cam_up_local);
        //auto rotate_pitch = glm::angleAxis(-glm::radians(dy / 10), cam_right_local);

        //if (d->is_vertical_axis_fixed) {
        //    // fixVerticalAxis(m);
        //}
        ////auto new_cam_ori      = cam_ori * rotate_yaw * rotate_pitch;
        ////// 沿自身z轴方向移动
        ////auto t                = glm::translate(Mat4d(1), Vec3d(0, 0, glm::length(cam_pos)));
        ////auto new_cam_in_world = glm::toMat4(new_cam_ori) * t;

        //auto move_to_origin = glm::translate(Mat4d(), -cam_pos);
        //auto                           m              = glm::toMat4(rotate_yaw * rotate_pitch);
        //auto new_cam_pos = m * 
        //move_to_origin* cam_in_world* m * glm::translate();
#else
        Mat4d rotate_yaw(1.0);
        Mat4d rotate_pitch(1.0);
        Mat4d new_cam_in_world(1.0);

#    if 0
        rotate_yaw       = glm::rotate(rotate_yaw, glm::radians(-dx / 10), cam_up_world);
        rotate_pitch     = glm::rotate(rotate_pitch, glm::radians(-dy / 10), Vec3d(cam_right_world));
        new_cam_in_world = rotate_pitch * rotate_yaw * cam_in_world;

        // 绕世界坐标系原点旋转
        // vm = vm * rotate_yaw * rotate_pitch;
#    else
        Vec3d z(0, 0, 1);

        rotate_yaw = glm::rotate(rotate_yaw, glm::radians(-dx / 10), d->is_vertical_axis_fixed ? z : cam_up_world);

        auto _dy = glm::radians(-dy / 10);
        auto i   = 0;

        do {
            rotate_pitch = glm::rotate(Mat4d(1.), _dy, cam_right_world);

            auto m = rotate_pitch * rotate_yaw * cam_in_world;
            if (d->is_vertical_axis_fixed) { fixVerticalAxis(m); }

            if (glm::dot(Vec3d(m[1]), z) > 1e-6) {

                // apply new rotation
                new_cam_in_world = m;
                break;
            }

            _dy /= 2.;
            if (++i == 20) {
                new_cam_in_world = rotate_yaw * cam_in_world;
                break;
            }
        }
        while (true);

#    endif
        vm = glm::inverse(new_cam_in_world);
#endif

        d->camera->setViewMatrix(vm);
    }

    d->prev_cursor_pt.x = xx;
    d->prev_cursor_pt.y = yy;
}

void StandardCameraManipulator::handleEVENT_MOUSE_BUTTON_RELEASEd(MouseButton btn, int x, int y)
{
    if (d->is_pan_started || d->is_rotation_started) { d->camera->getViewMatrixAsLookAt(d->eye, d->target, d->up, d->far); }

    d->is_pan_started         = false;
    d->is_rotation_started    = false;
    d->is_cursor_move_started = false;
    d->prev_cursor_pt.x       = 0;
    d->prev_cursor_pt.y       = 0;
    d->first_cursor_pt.x      = 0;
    d->first_cursor_pt.y      = 0;
}

void StandardCameraManipulator::handleMouseScrolled(int delta)
{
    auto vm = d->camera->getViewMatrix();

#if 0 // 在世界坐标系中沿相机z轴方向移动
    // Vec3f p, t, u, dir;
    // d->camera->getViewMatrixAsLookAt(p, t, u);
    // dir = t - p;
    // dir = dir * (delta / 10.f);
    // Mat4d m(1.0);
    // m = glm::translate(m, dir);
    // vm *= m;
#else // 在相机坐标系中沿相机z轴方向移动
    Vec3d dir(0, 0, 1);
    dir = dir * (delta / 20.);

    Mat4d m(1.0);

#    if 0

    m = glm::translate(m, -dir);

    auto cam_in_world  = glm::inverse(vm);
    auto cam_in_world2 = cam_in_world * m;
    vm                 = glm::inverse(cam_in_world2);

#    else

    m  = glm::translate(m, dir);
    vm = m * vm;

#    endif

#endif

    d->camera->setViewMatrix(vm);
    d->camera->getViewMatrixAsLookAt(d->eye, d->target, d->up, d->far);
}

void StandardCameraManipulator::handleEVENT_WINDOW_RESIZEd(int w, int h)
{
    d->width  = w;
    d->height = h;

    int vx = 0, vy = 0, vw = w, vh = h;

    if (onUpdateViewport(w, h, vx, vy, vw, vh)) {
        d->vx = vx;
        d->vy = vy;
        d->vw = vw;
        d->vh = vh;
        d->camera->setViewport(vx, vy, vw, vh);
        d->camera->setProjectionMatrix(computeProjectionMatrix());
    }
}

static void fixVerticalAxis(Mat4d& mat)
{
    auto  quat = glm::quat_cast(mat);
    Vec3d z(0., 0., 1.);
    Vec3d up      = quat * Vec3d(0., 1., 0.);
    Vec3d right   = quat * Vec3d(1., 0., 0.);
    Vec3d forward = quat * Vec3d(0., 0., -1.);

    Vec3d new_right1 = glm::cross(forward, z);
    Vec3d new_right2 = glm::cross(up, z);
    // 两向量夹角越小，叉乘结果的模越小
    Vec3d new_right  = (glm::length2(new_right1) > glm::length2(new_right2)) ? new_right1 : new_right2;

    // new_right = new_right1;
    // if (glm::length2(new_right) < 1e-6) return;

    // 夹角大于90度
    if (glm::dot(new_right, right) < 0.) { new_right = -new_right; }

    Quatd r(right, new_right);
    quat = r * quat;

    // 这种计算方式有问题
    // auto new_mat = glm::toMat4(quat);
    // new_mat[3]   = mat[3];
    // mat          = new_mat;

    mat = glm::toMat4(r) * mat;
}

static void fixVerticalAxis(Camera* cam)
{
    if (!cam)
        return;
    auto m = cam->getInverseViewMatrix();
    fixVerticalAxis(m);
    cam->setViewMatrix(glm::inverse(m));
}

} // namespace glr
} // namespace xg