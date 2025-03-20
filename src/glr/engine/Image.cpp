#include <glr/engine/Image.h>

#include <memory>

#include <vine/core/Exception.h>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>
#include <glr/igl/GLfuncs.h>

namespace glr {
namespace {
inline int getNbChannelsOfFormat(Image::Format format) {
    switch (format) {
    case Image::R8:
    case Image::G8:
    case Image::B8: return 1;
    case Image::RGB888: return 3;
    case Image::RGBA8888: return 4;
    default: return 0;
    }
}

inline int getPixelSizeOfFormat(Image::Format format) {
    switch (format) {
    case Image::R8:
    case Image::G8:
    case Image::B8: return 1;
    case Image::RGB888: return 3;
    case Image::RGBA8888: return 4;
    default: return 0;
    }
}
} // namespace

VI_OBJECT_META_IMPL(Image, Object);

struct Image::Data {
    unsigned char* data   = nullptr;
    Format         format = Format::Unknown;
    int            w      = 0;
    int            h      = 0;
};

Image::Image()
  : d(new Data()) {
}

void Image::setImage(int w, int h, Format format, const unsigned char* data) {
    auto& id = d->data;
    if (id) {
        free(id);
        id        = nullptr;
        d->w      = 0;
        d->h      = 0;
        d->format = Unknown;
    }

    if (w <= 0 || h <= 0 || format == Unknown) return;

    d->w      = w;
    d->h      = h;
    d->format = format;

    auto size_of_pixel = getPixelSizeOfFormat(format);
    auto size_of_img   = static_cast<size_t>(w) * h * size_of_pixel;
    id                 = static_cast<unsigned char*>(malloc(size_of_img));
    memcpy(id, data, size_of_img);
}

void Image::setImage(int w, int h, Format format, const unsigned char* data, int stride, int offset) {
    auto& id = d->data;
    if (id) {
        free(id);
        id        = nullptr;
        d->w      = 0;
        d->h      = 0;
        d->format = Unknown;
    }

    if (w <= 0 || h <= 0 || format == Unknown) return;

    if ((format == RGB888 && stride < 3) || (format == RGBA8888 && stride < 4) || offset >= stride)
        throw vine::Exception(vine::Exception::INVALID_ARGUMENTS);

    d->w      = w;
    d->h      = h;
    d->format = format;

    auto size_of_pixel = getPixelSizeOfFormat(format);
    auto size_of_img   = static_cast<size_t>(w) * h * size_of_pixel;
    id                 = static_cast<unsigned char*>(malloc(size_of_img));

    auto pix = data;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; w++) {
            memccpy(id, pix + offset, 0, size_of_pixel);
            id += size_of_pixel;
            pix += stride;
        }
    }
}

Image::Format Image::getFormat() const {
    return d->format;
}

int Image::getInternalTextureFormat() const {
    switch (d->format) {
    case R8: return IGL_R8;
    case G8: return IGL_R8;
    case B8: return IGL_R8;
    case RGB888: return IGL_RGB8;
    case RGBA8888: return IGL_RGBA8;
    default: return IGL_ZERO;
    }
}

int Image::getDataFormat() const {
    switch (d->format) {
    case R8: return IGL_RED;
    case G8: return IGL_RED;
    case B8: return IGL_RED;
    case RGB888: return IGL_RGB;
    case RGBA8888: return IGL_RGBA;
    default: return IGL_ZERO;
    }
}

int Image::getDataType() const {
    return IGL_UNSIGNED_BYTE;
}

int Image::getWidth() const {
    return d->w;
}

int Image::getHeight() const {
    return d->h;
}

int Image::getChannels() const {
    return getNbChannelsOfFormat(d->format);
}

unsigned char* Image::data() const {
    return d->data;
}

int Image::size() const {
    return d->w * d->h * getPixelSizeOfFormat(d->format);
}

bool Image::isNull() const {
    return d->data == nullptr;
}

Image* Image::readPixels(State& state, int x, int y, int w, int h, int fmt, int type) {
    auto buffer = new unsigned char[w * h * 4];
    auto funcs  = state.getContext()->getFuncs();
    funcs->iglReadPixels(x, y, w, h, fmt, type, buffer);
    auto img = new Image();
    img->setImage(w, h, RGBA8888, buffer);

    return img;
}
} // namespace glr