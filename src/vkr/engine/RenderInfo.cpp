#include <vkr/engine/RenderInfo.h>

#include <vkr/engine/Renderer.h>

namespace vkr {
VI_OBJECT_META_IMPL(RenderInfo, Object);

struct RenderInfo::Data {
    vine::RefPtr<Renderer> master_renderer;
};

RenderInfo::RenderInfo(Renderer* master_renderer)
  : d(new Data()) {
    d->master_renderer = master_renderer;
}

RenderInfo::~RenderInfo() {
    delete d;
}

Renderer* RenderInfo::getMasterRenderer() const {
    return d->master_renderer.get();
}
} // namespace vkr