#include <xg/igl/engine/TextureRectangle.hpp>

#include <vine/Ptr.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Image.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/io/ImageLoader.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(TextureRectangle, Texture);

struct TextureRectangle::Data {
    GLsizei_t           w   = 0;
    GLsizei_t           h   = 0;
    vine::RefPtr<Image> img = nullptr;
};

TextureRectangle::TextureRectangle()
  : d(new Data())
{}

TextureRectangle::~TextureRectangle()
{ delete d; }

Texture::Type TextureRectangle::getType() const
{ return Type::TEXTURE_RECTANGLE; }

void TextureRectangle::setWidth(GLsizei_t w)
{
    d->w = w;
    dirty();
}

void TextureRectangle::setHeight(GLsizei_t h)
{
    d->h = h;
    dirty();
}

GLsizei_t TextureRectangle::getWidth() const
{ return d->w; }

GLsizei_t TextureRectangle::getHeight() const
{ return d->h; }

void TextureRectangle::setImage(const std::string& img_file)
{
    auto img = ImageLoader().loadFile(img_file);
    setImage(img);
}

void TextureRectangle::setImage(Image* image)
{
    if (image == d->img)
        return;

    d->img = image;
    if (image) {
        d->w = image->getWidth();
        d->h = image->getHeight();
    }
    else {
        d->w = 0;
        d->h = 0;
    }
    dirty();
}

GLuint_t TextureRectangle::onCreate(State& state)
{
    auto     funcs = state.getContext()->getFuncs();
    GLuint_t id    = 0;
    funcs->oglGenTextures(1, &id);
    funcs->oglBindTexture(getType(), id);

    applyParams(funcs);

    applyStorage(funcs);

    float max_anisotropy = getMaxAnisotropy();

    if (max_anisotropy > 1.0) {
        float gl_max_anisotropy;
        funcs->oglGetFloatv(IGL_MAX_TEXTURE_MAX_ANISOTROPY, &gl_max_anisotropy);
        funcs->oglTextureParameterf(IGL_TEXTURE_2D, IGL_TEXTURE_MAX_ANISOTROPY, std::min(gl_max_anisotropy, max_anisotropy));
    }
    funcs->oglBindTexture(getType(), 0);
    return id;
}

bool TextureRectangle::onUpdate(State& state)
{
    release(state);
    if (!isCreated(state)) { create(state); }
    return true;
}

void TextureRectangle::applyParams(GLfuncs* funcs)
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

void TextureRectangle::applyStorage(GLfuncs* funcs)
{
    void*     img_data = nullptr;
    GLsizei_t w = d->w, h = d->h, internal_fmt = getInternalFormat();
    GLenum_t  src_type = 0, src_format = 0;

    if (d->img.get()) {
        img_data     = d->img->data();
        w            = d->img->getWidth();
        h            = d->img->getHeight();
        internal_fmt = d->img->getInternalTextureFormat();
        src_type     = d->img->getDataType();
        src_format   = d->img->getDataFormat();
    }
    else {
        src_format = computeDataFormat(InternalFormat(internal_fmt));
        src_type   = computeDataType(InternalFormat(internal_fmt));
    }
    if (w && h) { funcs->oglTexImage2D(getType(), 0, internal_fmt, w, h, 0, src_format, src_type, img_data); }
}

} // namespace glr
} // namespace xg