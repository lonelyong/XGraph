#include <glr/engine/CullFace.h>

namespace glr {

VI_OBJECT_META_IMPL(CullFace, StateAttribute);

struct CullFace::Data {};

CullFace::CullFace()
  : d(new Data()) {
}

CullFace::~CullFace() {
}

CullFace::Type CullFace::getType() const {
    return CULL_FACE;
}

void CullFace::apply(State& state) const {
}

} // namespace glr