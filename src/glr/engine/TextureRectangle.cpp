#include <glr/engine/TextureRectangle.h>

#include <glad/glad.h>

#include <vine/core/Ptr.h>

#include <glr/engine/Image.h>
#include <glr/io/ImageLoader.h>

namespace glr {
VI_OBJECT_META_IMPL(TextureRectangle, Texture);

struct TextureRectangle::Data {
    GLsizei_t           w   = 0;
    GLsizei_t           h   = 0;
    vine::RefPtr<Image> img = nullptr;
};

TextureRectangle::TextureRectangle()
  : d(new Data()) {
}

TextureRectangle::~TextureRectangle() {
    delete d;
}

Texture::Type TextureRectangle::getType() const {
    return Type::TEXTURE_RECTANGLE;
}

void TextureRectangle::setWidth(GLsizei_t w) {
    d->w = w;
    dirty();
}

void TextureRectangle::setHeight(GLsizei_t h) {
    d->h = h;
    dirty();
}

GLsizei_t TextureRectangle::getWidth() const {
    return d->w;
}

GLsizei_t TextureRectangle::getHeight() const {
    return d->h;
}

void TextureRectangle::setImage(const std::string& img_file) {
    auto img = ImageLoader().loadFile(img_file);
    setImage(img);
}

void TextureRectangle::setImage(Image* image) {
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

GLuint_t TextureRectangle::onCreate(State& state) {
    GLuint_t id = 0;
    glGenTextures(1, &id);
    glBindTexture(getType(), id);
    glTexParameteri(getType(), GL_TEXTURE_MIN_FILTER, getFilter(MIN_FILTER));
    glTexParameteri(getType(), GL_TEXTURE_MAG_FILTER, getFilter(MAX_FILTER));
    glTexParameteri(getType(), GL_TEXTURE_WRAP_S, getWrap(WRAP_S));
    glTexParameteri(getType(), GL_TEXTURE_WRAP_T, getWrap(WRAP_T));

    void* img_data = nullptr;
    GLint w = d->w, h = d->h, internal_fmt = getInternalFormat(), src_type = 0, src_format = 0;

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
        glTexImage2D(getType(), 0, internal_fmt, w, h, 0, src_format, src_type, img_data);
    }

    float max_anisotropy = getMaxAnisotropy();

    if (max_anisotropy > 1.0) {
        float gl_max_anisotropy;
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &gl_max_anisotropy);
        glTextureParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, std::min(gl_max_anisotropy, max_anisotropy));
    }
    glBindTexture(getType(), 0);
    return id;
}

bool TextureRectangle::onUpdate(State& state) {
    release(state);
    if (!isCreated(state)) {
        create(state);
    }
    return true;
}

} // namespace glr