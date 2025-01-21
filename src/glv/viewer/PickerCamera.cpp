#include <glad/glad.h>

#include "PickerCamera.h"

#include <fstream>
#include <iosfwd>
#include <sstream>

#include <osg/RenderInfo>
#include <osg/Texture2D>
#include <osgDB/WriteFile>

#include <xgcomm/Resources.h>

namespace glv {
namespace {
struct CameraPostDrawCallback : public osg::Camera::DrawCallback {
    virtual void operator()(osg::RenderInfo& renderInfo) const;
};
} // namespace

struct PickerCamera::Data {
    osg::ref_ptr<osg::Texture2D> tex_color_buf0;
};

PickerCamera::PickerCamera()
  : d(new Data()) {
    auto fn_create_shader = [](const char* file) {
        std::ifstream ifs(file);
        if (ifs.is_open()) {
            std::ostringstream ss;
            ss << ifs.rdbuf();
            return ss.str();
        }
        return std::string();
    };

    auto prog = new osg::Program();
    prog->addShader(new osg::Shader(osg::Shader::VERTEX, fn_create_shader(XG_RES("shaders/phong_comp.vs.glsl"))));
    prog->addShader(new osg::Shader(osg::Shader::FRAGMENT, fn_create_shader(XG_RES("shaders/phong_comp.fs.glsl"))));

    setViewport(0, 0, 1280, 720);
    setRenderOrder(osg::Camera::POST_RENDER);
    setClearColor(osg::Vec4(0, 0, 0, 1));
    setClearMask(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    getOrCreateStateSet()->setAttributeAndModes(prog, osg::StateAttribute::ON | osg::StateAttribute::PROTECTED);
    setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
    setPostDrawCallback(new CameraPostDrawCallback());

    // auto depth_buffer = new osg::RenderBuffer(1280, 720, GL_DEPTH_COMPONENT24);
    // auto color_buffer = new osg::RenderBuffer(1280, 720, GL_RGBA8);
    //  auto fbo = new osg::FrameBufferObject();
    //  fbo->setAttachment(osg::Camera::DEPTH_BUFFER, osg::FrameBufferAttachment(depth_buffer));
    //  fbo->setAttachment(osg::Camera::COLOR_BUFFER0, osg::FrameBufferAttachment(color_buffer));
    //  cam->getOrCreateStateSet()->setAttributeAndModes(fbo);

    // auto depth_buffer = new osg::Texture2D();
    // depth_buffer->setInternalFormat(GL_DEPTH_COMPONENT24);
    // depth_buffer->setTextureSize(1280, 720);

    // auto color_buffer = new osg::Texture2D();
    // color_buffer->setInternalFormat(GL_RGBA8);


    // auto color_img = new osg::Image;
    // color_img->allocateImage(1280, 720, 1, GL_RGBA, GL_FLOAT);
    // color_img->setInternalTextureFormat(GL_RGBA8);
    // color_buffer->setImage(color_img);

    auto tex_color_buffer = osg::ref_ptr(new osg::Texture2D());
    tex_color_buffer->setInternalFormat(GL_RGBA8);

    attach(osg::Camera::DEPTH_BUFFER, GL_DEPTH_COMPONENT24);
    // attach(osg::Camera::COLOR_BUFFER0, GL_RGBA8);
    attach(osg::Camera::COLOR_BUFFER0, tex_color_buffer);

    d->tex_color_buf0 = tex_color_buffer;
}

PickerCamera::~PickerCamera() {
    delete d;
}

void CameraPostDrawCallback::operator()(osg::RenderInfo& renderInfo) const {
    static bool is_first_frame = true;
    if (is_first_frame) {
        is_first_frame = false;
        auto cam       = renderInfo.getCurrentCamera();
        auto vp        = cam->getViewport();
        auto img       = osg::ref_ptr(new osg::Image());

        GLint fbo_id;
        glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo_id);
        // �ڵ���DrawCallback֮ǰ��GL_FRAMEBUFFER�Ѿ�Reset��Default
        glBindFramebuffer(GL_FRAMEBUFFER, 1);
        glReadBuffer(GL_COLOR_ATTACHMENT0);
        img->readPixels(0, 0, vp->width(), vp->height(), GL_RGBA, GL_UNSIGNED_BYTE);

        // glBindFramebuffer(GL_FRAMEBUFFER, 0);
        osgDB::writeImageFile(*img, "d:/1.bmp");
    }
}
} // namespace glv