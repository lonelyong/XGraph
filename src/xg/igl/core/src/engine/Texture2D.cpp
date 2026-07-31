#include <xg/igl/engine/Texture2D.hpp>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Image.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

#include <xg/igl/io/ImageLoader.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(Texture2D, Texture);

Texture2D::Texture2D() = default;

Texture2D::~Texture2D() = default;

void Texture2D::setWidth(GLsizei_t w)
{
    w_ = w;
    dirty();
}

void Texture2D::setHeight(GLsizei_t h)
{
    h_ = h;
    dirty();
}

void Texture2D::setImage(const std::string& img_file)
{
    auto img = ImageLoader().loadFile(img_file);
    setImage(img);
}

void Texture2D::setImage(Image* image)
{
    if (image == img_)
        return;

    img_ = image;
    if (image) {
        w_ = image->getWidth();
        h_ = image->getHeight();
    }
    else {
        w_ = 0;
        h_ = 0;
    }
    dirty();
}

GLuint_t Texture2D::onCreate(State& state)
{
    auto     funcs = state.getContext()->getFuncs();
    GLuint_t id    = 0;
    funcs->oglGenTextures(1, &id);
    funcs->oglBindTexture(getType(), id);

    applyParams(funcs);

    applyStorage(funcs);

    if (getGenerateMipmapLevels()) { funcs->oglGenerateMipmap(IGL_TEXTURE_2D); }

    float max_anisotropy = getMaxAnisotropy();

    if (max_anisotropy > 1.0) {
        float gl_max_anisotropy;
        funcs->oglGetFloatv(IGL_MAX_TEXTURE_MAX_ANISOTROPY, &gl_max_anisotropy);
        funcs->oglTextureParameterf(IGL_TEXTURE_2D, IGL_TEXTURE_MAX_ANISOTROPY, std::min(gl_max_anisotropy, max_anisotropy));
    }

    funcs->oglBindTexture(getType(), 0);
    return id;
}

bool Texture2D::onUpdate(State& state)
{
    release(state);
    if (!isCreated(state)) { create(state); }
    return true;
}

void Texture2D::applyParams(GLfuncs* funcs)
{
    FilterMode min_filter = getFilter(MIN_FILTER), mag_filter = getFilter(MAG_FILTER);
    WrapMode   wrap_s = getWrap(WRAP_S), wrap_t = getWrap(WRAP_T);

    if (min_filter != FILTER_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_MIN_FILTER, min_filter);
    if (mag_filter != FILTER_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_MAG_FILTER, mag_filter);
    if (wrap_s != WRAP_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_S, wrap_s);
    if (wrap_t != WRAP_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_T, wrap_t);
}

void Texture2D::applyStorage(GLfuncs* funcs)
{
    void*     img_data = nullptr;
    GLsizei_t w = w_, h = h_, internal_fmt = getInternalFormat();
    GLenum_t  src_type = 0, src_format = 0;

    if (img_.get()) {
        img_data     = img_->data();
        w            = img_->getWidth();
        h            = img_->getHeight();
        internal_fmt = img_->getInternalTextureFormat();
        src_type     = img_->getDataType();
        src_format   = img_->getDataFormat();
    }
    else {
        src_format = computeDataFormat(InternalFormat(internal_fmt));
        src_type   = computeDataType(InternalFormat(internal_fmt));
    }
    if (w && h) { funcs->oglTexImage2D(getType(), 0, internal_fmt, w, h, 0, src_format, src_type, img_data); }
}

} // namespace glr
} // namespace xg