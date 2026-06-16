#include <xg/glr/engine/Texture2D.hpp>

#include <vine/Ptr.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/Image.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>

#include <xg/glr/io/ImageLoader.hpp>

namespace xg {
namespace glr {
V_OBJECT_META_IMPL(Texture2D, Texture);

struct Texture2D::Data {
    GLsizei_t           w   = 0;
    GLsizei_t           h   = 0;
    vine::RefPtr<Image> img = nullptr;
};

Texture2D::Texture2D()
  : d(new Data()) {
}

Texture2D::~Texture2D() {
    delete d;
}

Texture::Type Texture2D::getType() const {
    return Type::TEXTURE_2D;
}

void Texture2D::setWidth(GLsizei_t w) {
    d->w = w;
    dirty();
}

void Texture2D::setHeight(GLsizei_t h) {
    d->h = h;
    dirty();
}

GLsizei_t Texture2D::getWidth() const {
    return d->w;
}

GLsizei_t Texture2D::getHeight() const {
    return d->h;
}

void Texture2D::setImage(const std::string& img_file) {
    auto img = ImageLoader().loadFile(img_file);
    setImage(img);
}

void Texture2D::setImage(Image* image) {
    if (image == d->img) return;

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

GLuint_t Texture2D::onCreate(State& state) {
    auto     funcs = state.getContext()->getFuncs();
    GLuint_t id    = 0;
    funcs->iglGenTextures(1, &id);
    funcs->iglBindTexture(getType(), id);

    applyParams(funcs);

    applyStorage(funcs);

    if (getGenerateMipmapLevels()) {
        funcs->iglGenerateMipmap(IGL_TEXTURE_2D);
    }

    float max_anisotropy = getMaxAnisotropy();

    if (max_anisotropy > 1.0) {
        float gl_max_anisotropy;
        funcs->iglGetFloatv(IGL_MAX_TEXTURE_MAX_ANISOTROPY, &gl_max_anisotropy);
        funcs->iglTextureParameterf(IGL_TEXTURE_2D,
                                    IGL_TEXTURE_MAX_ANISOTROPY,
                                    std::min(gl_max_anisotropy, max_anisotropy));
    }

    funcs->iglBindTexture(getType(), 0);
    return id;
}

bool Texture2D::onUpdate(State& state) {
    release(state);
    if (!isCreated(state)) {
        create(state);
    }
    return true;
}

void Texture2D::applyParams(GLfuncs* funcs) {
    FilterMode min_filter = getFilter(MIN_FILTER), mag_filter = getFilter(MAG_FILTER);
    WrapMode   wrap_s = getWrap(WRAP_S), wrap_t = getWrap(WRAP_T);

    if (min_filter != FILTER_UNSET) funcs->iglTexParameteri(getType(), IGL_TEXTURE_MIN_FILTER, min_filter);
    if (mag_filter != FILTER_UNSET) funcs->iglTexParameteri(getType(), IGL_TEXTURE_MAG_FILTER, mag_filter);
    if (wrap_s != WRAP_UNSET) funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_S, wrap_s);
    if (wrap_t != WRAP_UNSET) funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_T, wrap_t);
}

void Texture2D::applyStorage(GLfuncs* funcs) {
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
    if (w && h) {
        funcs->iglTexImage2D(getType(), 0, internal_fmt, w, h, 0, src_format, src_type, img_data);
    }
}

} // namespace glr
} // namespace xg