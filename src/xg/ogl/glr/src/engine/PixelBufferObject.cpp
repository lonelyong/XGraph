#include "PixelBufferObject.h"

#include <map>

#include <xg/glr/engine/GraphicContext.h>
#include <xg/glr/engine/Image.h>
#include <xg/glr/engine/State.h>

namespace glr {
V_OBJECT_META_IMPL(PixelBufferObject, BufferObject);

struct PixelBufferObject::Data {
    std::map<int, bool> dirties;
    Mode                m = MODE_PACK;
    vine::RefPtr<Image> img;
};

PixelBufferObject::PixelBufferObject(Mode m)
  : d(new Data()) {
    d->m = m;
}

BufferObject::Target PixelBufferObject::getTarget() const {
    return d->m == MODE_PACK ? PIXEL_PACK_BUFFER : PIXEL_UNPACK_BUFFER;
}

BufferObject::Usage PixelBufferObject::getUsage() const {
    return STREAM_READ;
}

GLuint_t PixelBufferObject::onCreate(State& state) {
    auto id = BufferObject::onCreate(state);
    if (id != IGL_ZERO) {
        if (getTarget() == PIXEL_PACK_BUFFER) {
        }
    }
    return id;
}

bool PixelBufferObject::setImage(Image* img) {
    if (d->m == MODE_PACK) return false;
    if (d->img == img) return true;
    d->img = img;
}

bool PixelBufferObject::onUpdate(State& state) {
    return true;
}
} // namespace glr