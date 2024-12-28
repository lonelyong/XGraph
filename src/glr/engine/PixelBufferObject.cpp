#include "PixelBufferObject.h"

#include <map>

#include <glr/engine/GraphicContext.h>
#include <glr/engine/State.h>

namespace glr {
VI_OBJECT_META_IMPL(PixelBufferObject, BufferObject);

struct PixelBufferObject::Data {
    std::map<int, bool> dirties;
    Mode                m = MODE_PACK;
};

PixelBufferObject::PixelBufferObject(Mode m)
  : d(new Data()) {
    d->m = m;
}

BufferObject::Target PixelBufferObject::getTarget() const {
    return d->m == MODE_PACK ? TARGET_PIXEL_PACK_BUFFER : TARGET_PIXEL_UNPACK_BUFFER;
}

BufferObject::Usage PixelBufferObject::getUsage() const {
    return USAGE_STREAM_READ;
}

GLuint PixelBufferObject::onCreate(State& state) {
    auto id = BufferObject::onCreate(state);
    if (id != GL_ZERO) {
        if (getTarget() == TARGET_PIXEL_PACK_BUFFER) {
            
        }
    }
    return id;
}

bool PixelBufferObject::onUpdate(State& state) {
}
} // namespace glr