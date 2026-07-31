#include <xg/igl/engine/Image.hpp>

#include <cstring>

#include <vine/Exception.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{
namespace
{

inline int getNumChannelsOfFormat(Image::Format format)
{
    switch (format) {
    case Image::R8:
    case Image::G8:
    case Image::B8: return 1;
    case Image::RGB888: return 3;
    case Image::RGBA8888: return 4;
    default: return 0;
    }
}

inline int getPixelSizeOfFormat(Image::Format format)
{
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

V_OBJECT_META_IMPL(Image, Object);

Image::Image() = default;

void Image::setImage(int w, int h, Format format, const unsigned char* data)
{
    auto& id = data_;
    if (id) {
        free(id);
        id      = nullptr;
        w_      = 0;
        h_      = 0;
        format_ = Unknown;
    }

    if (w <= 0 || h <= 0 || format == Unknown)
        return;

    w_      = w;
    h_      = h;
    format_ = format;

    auto size_of_pixel = getPixelSizeOfFormat(format);
    auto size_of_img   = static_cast<size_t>(w) * h * size_of_pixel;
    id                 = static_cast<unsigned char*>(malloc(size_of_img));
    memcpy(id, data, size_of_img);
}

void Image::setImage(int w, int h, Format format, const unsigned char* data, int stride, int offset)
{
    auto& id = data_;
    if (id) {
        free(id);
        id      = nullptr;
        w_      = 0;
        h_      = 0;
        format_ = Unknown;
    }

    if (w <= 0 || h <= 0 || format == Unknown)
        return;

    if ((format == RGB888 && stride < 3) || (format == RGBA8888 && stride < 4) || offset >= stride)
        throw vine::Exception(vine::Exception::INVALID_ARGUMENTS);

    w_      = w;
    h_      = h;
    format_ = format;

    auto size_of_pixel = getPixelSizeOfFormat(format);
    auto size_of_img   = static_cast<size_t>(w) * h * size_of_pixel;
    id                 = static_cast<unsigned char*>(malloc(size_of_img));

    auto pix = data;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            memccpy(id, pix + offset, 0, size_of_pixel);
            id += size_of_pixel;
            pix += stride;
        }
    }
}

int Image::getInternalTextureFormat() const
{
    switch (format_) {
    case R8: return IGL_R8;
    case G8: return IGL_R8;
    case B8: return IGL_R8;
    case RGB888: return IGL_RGB8;
    case RGBA8888: return IGL_RGBA8;
    default: return IGL_ZERO;
    }
}

int Image::getDataFormat() const
{
    switch (format_) {
    case R8: return IGL_RED;
    case G8: return IGL_RED;
    case B8: return IGL_RED;
    case RGB888: return IGL_RGB;
    case RGBA8888: return IGL_RGBA;
    default: return IGL_ZERO;
    }
}

int Image::getChannels() const
{ return getNumChannelsOfFormat(format_); }

int Image::size() const
{ return w_ * h_ * getPixelSizeOfFormat(format_); }

Image* Image::readPixels(State& state, int x, int y, int w, int h, int fmt, int type)
{
    auto buffer = new unsigned char[w * h * 4];
    auto funcs  = state.getContext()->getFuncs();
    funcs->oglReadPixels(x, y, w, h, fmt, type, buffer);
    auto img = new Image();
    img->setImage(w, h, RGBA8888, buffer);

    return img;
}

} // namespace glr
} // namespace xg