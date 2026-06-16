#include <xg/glr/engine/CubeMap.hpp>

#include <xg/glr/engine/GraphicContext.hpp>
#include <xg/glr/engine/Image.hpp>
#include <xg/glr/engine/State.hpp>
#include <xg/glr/igl/GLfuncs.hpp>
#include <xg/glr/io/ImageLoader.hpp>

namespace xg {
namespace glr
{

V_OBJECT_META_IMPL(CubeMap, Texture);

struct CubeMap::Data {
    std::vector<vine::RefPtr<Image>> imgs;
};

CubeMap::CubeMap()
  : d(new Data())
{}

CubeMap::~CubeMap()
{}

Texture::Type CubeMap::getType() const
{
    return Type::TEXTURE_CUBE_MAP;
}

void CubeMap::setImages(const std::vector<std::string>& imgs)
{
    ImageLoader         il;
    std::vector<Image*> is;
    is.reserve(imgs.size());
    for (auto img : imgs) {
        is.push_back(il.loadFile(img));
    }
    setImages(is);
}

void CubeMap::setImages(const std::vector<Image*>& imgs)
{

    std::vector<vine::RefPtr<Image>> is;
    is.reserve(imgs.size());
    for (auto img : imgs) is.push_back(img);
    d->imgs = std::move(is);
    dirty();
}

GLuint_t CubeMap::onCreate(State& state)
{
    if (d->imgs.size() != 6)
        return 0;

    auto funcs = state.getContext()->getFuncs();

    GLuint_t id = 0;
    funcs->iglGenTextures(1, &id);
    funcs->iglBindTexture(getType(), id);
    funcs->iglTexParameteri(getType(), IGL_TEXTURE_MIN_FILTER, getFilter(MIN_FILTER));
    funcs->iglTexParameteri(getType(), IGL_TEXTURE_MAG_FILTER, getFilter(MAG_FILTER));
    funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_S, getWrap(WRAP_S));
    funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_T, getWrap(WRAP_T));
    funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_R, getWrap(WRAP_R));

    for (int i = 0; i < 6; i++) {
        auto& img = d->imgs[i];

        if (img->isNull())
            continue;

        auto w        = img->getWidth();
        auto h        = img->getHeight();
        auto fmt      = img->getInternalTextureFormat();
        auto src_fmt  = d->imgs[i]->getDataFormat();
        auto src_type = d->imgs[i]->getDataType();
        auto img_data = img->data();

        funcs->iglTexImage2D(IGL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, fmt, w, h, 0, src_fmt, src_type, img_data);
    }

    return id;



    // if (d->imgs.size() != 6) return 0;

    // auto funcs = state.getContext()->getFuncs();

    // GLuint_t id = 0;
    // funcs->iglGenTextures(1, &id);
    // funcs->iglBindTexture(getType(), id);

    // applyParams(funcs);

    // applyStorage(funcs);

    // funcs->iglBindTexture(getType(), 0);

    // return id;
}

bool CubeMap::onUpdate(State& state)
{
    return true;
}

void CubeMap::applyParams(GLfuncs* funcs)
{
    FilterMode min_filter = getFilter(MIN_FILTER), mag_filter = getFilter(MAG_FILTER);
    WrapMode   wrap_s = getWrap(WRAP_S), wrap_t = getWrap(WRAP_T), wrap_r = getWrap(WRAP_R);

    if (min_filter != FILTER_UNSET)
        funcs->iglTexParameteri(getType(), IGL_TEXTURE_MIN_FILTER, min_filter);
    if (mag_filter != FILTER_UNSET)
        funcs->iglTexParameteri(getType(), IGL_TEXTURE_MAG_FILTER, mag_filter);
    if (wrap_s != WRAP_UNSET)
        funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_S, wrap_s);
    if (wrap_t != WRAP_UNSET)
        funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_T, wrap_t);
    if (wrap_r != WRAP_UNSET)
        funcs->iglTexParameteri(getType(), IGL_TEXTURE_WRAP_R, wrap_r);
}

void CubeMap::applyStorage(GLfuncs* funcs)
{
    for (int i = 0; i < 6; ++i) {
        auto& img      = d->imgs[i];
        void* img_data = img->data();

        if (img->isNull())
            continue;

        GLsizei_t w = img->getWidth(), h = img->getHeight(), internal_fmt = img->getInternalTextureFormat();
        GLenum_t  src_type = img->getDataType(), src_format = img->getDataFormat();

        funcs->iglTexImage2D(IGL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internal_fmt, w, h, 0, src_format, src_type, img_data);
    }
}

} // namespace glr
} // namespace xg