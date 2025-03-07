#include <glr/engine/Texture2D.h>

#include <vine/core/Ptr.h>

#include <glr/engine/Image.h>
#include <glr/io/ImageLoader.h>

namespace glr {
VI_OBJECT_META_IMPL(Texture2D, Texture);

struct Texture2D::Data {
    GLsizei             w   = 0;
    GLsizei             h   = 0;
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

void Texture2D::setWidth(GLsizei w) {
    d->w = w;
    dirty();
}

void Texture2D::setHeight(GLsizei h) {
    d->h = h;
    dirty();
}

GLsizei Texture2D::getWidth() const {
    return d->w;
}

GLsizei Texture2D::getHeight() const {
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

GLuint Texture2D::onCreate(State& state) {
    GLuint id = 0;
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
    if (getGenerateMipmapLevels()) {
        glGenerateMipmap(GL_TEXTURE_2D);
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

bool Texture2D::onUpdate(State& state) {
    release(state);
    if (!isCreated(state)) {
        create(state);
    }
    return true;
}

} // namespace glr