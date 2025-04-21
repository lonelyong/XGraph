#include "CameraPicker.h"

#include <fstream>
#include <iosfwd>
#include <sstream>

#include <osg/RenderInfo>
#include <osg/Texture2D>
#include <osgDB/WriteFile>
#include <osgUtil/RenderBin>
#include <osgUtil/RenderStage>

#include <xgcomm/Resources.h>

#include <glr/igl/GLfuncs.h>

#include <glv/utils/GLfuncsManager.h>

namespace glv {
namespace {

struct PostDrawCallback : public osg::Camera::DrawCallback {
    virtual void operator()(osg::RenderInfo& renderInfo) const;
};
} // namespace

CameraPicker::CameraPicker() {
    setViewport(0, 0, 1280, 720);
    setRenderOrder(osg::Camera::POST_RENDER);
    setClearColor(osg::Vec4(1, 1, 1, 1));
    setClearMask(IGL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
    setPostDrawCallback(new PostDrawCallback());

    // auto depth_buffer = new osg::RenderBuffer(1280, 720, GL_DEPTH_COMPONENT24);
    // auto color_buffer = new osg::RenderBuffer(1280, 720, GL_RGBA8);
    //  auto fbo = new osg::FrameBufferObject();
    //  fbo->setAttachment(osg::Camera::DEPTH_BUFFER, osg::FrameBufferAttachment(depth_buffer));
    //  fbo->setAttachment(osg::Camera::COLOR_BUFFER0, osg::FrameBufferAttachment(color_buffer));
    //  cam->getOrCreateStateSet()->setAttributeAndModes(fbo);

    // auto depth_buffer = new osg::Texture2D();
    // depth_buffer->setInternalFormat(IGL_DEPTH_COMPONENT24);
    // depth_buffer->setTextureSize(1280, 720);

    // auto color_buffer = new osg::Texture2D();
    // color_buffer->setInternalFormat(IGL_RGBA8);


    // auto color_img = new osg::Image;
    // color_img->allocateImage(1280, 720, 1, GL_RGBA, GL_FLOAT);
    // color_img->setInternalTextureFormat(IGL_RGBA8);
    // color_buffer->setImage(color_img);

    auto color_buffer0 = osg::ref_ptr(new osg::Texture2D());
    color_buffer0->setInternalFormat(IGL_RGBA8);

    auto depth_buf = osg::ref_ptr(new osg::Texture2D());
    depth_buf->setInternalFormat(IGL_DEPTH_COMPONENT24);

    attach(osg::Camera::DEPTH_BUFFER, depth_buf);
    // attach(osg::Camera::COLOR_BUFFER0, GL_RGBA8);
    attach(osg::Camera::COLOR_BUFFER0, color_buffer0);

    color_buf0 = color_buffer0;
    depth_buf  = depth_buf;
}

CameraPicker::~CameraPicker() {
}

void PostDrawCallback::operator()(osg::RenderInfo& renderInfo) const {
    static bool is_first_frame = true;
    
    auto bin =renderInfo.getRenderBinStack().back();
    bin->getStage()->getFrameBufferObject();

    auto cam = renderInfo.getCurrentCamera();
    auto vp  = cam->getViewport();
    if (is_first_frame) {
        is_first_frame = false;

        auto img = osg::ref_ptr(new osg::Image());

        auto funcs = GLfuncsManager::instance().getOrRegisterByContext(renderInfo.getState()->getGraphicsContext());
        if (!funcs) return;

        GLint fbo_id;
        funcs->iglGetIntegerv(IGL_FRAMEBUFFER_BINDING, &fbo_id);
        // 相机的drawcallback调用之后，会reset FBO to default
        funcs->iglBindFramebuffer(IGL_FRAMEBUFFER, 1);
        glReadBuffer(IGL_COLOR_ATTACHMENT0);
        img->readPixels(0, 0, vp->width(), vp->height(), GL_RGBA, GL_UNSIGNED_BYTE);

        // glBindFramebuffer(IGL_FRAMEBUFFER, 0);
        osgDB::writeImageFile(*img, "d:/1.bmp");
    }
}
} // namespace glv