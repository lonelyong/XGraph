#include <xg/igl/engine/CubeMap.hpp>

#include <xg/igl/engine/GraphicContext.hpp>
#include <xg/igl/engine/Image.hpp>
#include <xg/igl/engine/State.hpp>
#include <xg/igl/io/ImageLoader.hpp>
#include <xg/igl/ogl/GLfuncs.hpp>

namespace xg
{
namespace glr
{

V_OBJECT_META_IMPL(CubeMap, Texture);

CubeMap::CubeMap() = default;

CubeMap::~CubeMap() = default;

void CubeMap::setImages(const std::vector<std::string>& imgs)
{
    ImageLoader         il;
    std::vector<Image*> is;
    is.reserve(imgs.size());
    for (auto img : imgs) { is.push_back(il.loadFile(img)); }
    setImages(is);
}

void CubeMap::setImages(const std::vector<Image*>& imgs)
{
    std::vector<vine::RefPtr<Image>> is;
    is.reserve(imgs.size());
    for (auto img : imgs) is.push_back(img);
    imgs_ = std::move(is);
    dirty();
}

GLuint_t CubeMap::onCreate(State& state)
{
    if (imgs_.size() != 6)
        return 0;

    auto funcs = state.getContext()->getFuncs();

    GLuint_t id = 0;
    funcs->oglGenTextures(1, &id);
    funcs->oglBindTexture(getType(), id);
    funcs->oglTexParameteri(getType(), IGL_TEXTURE_MIN_FILTER, getFilter(MIN_FILTER));
    funcs->oglTexParameteri(getType(), IGL_TEXTURE_MAG_FILTER, getFilter(MAG_FILTER));
    funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_S, getWrap(WRAP_S));
    funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_T, getWrap(WRAP_T));
    funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_R, getWrap(WRAP_R));

    for (int i = 0; i < 6; i++) {
        auto& img = imgs_[i];

        if (img->isNull())
            continue;

        auto w        = img->getWidth();
        auto h        = img->getHeight();
        auto fmt      = img->getInternalTextureFormat();
        auto src_fmt  = imgs_[i]->getDataFormat();
        auto src_type = imgs_[i]->getDataType();
        auto img_data = img->data();

        funcs->oglTexImage2D(IGL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, fmt, w, h, 0, src_fmt, src_type, img_data);
    }

    return id;



    // if (d->imgs.size() != 6) return 0;

    // auto funcs = state.getContext()->getFuncs();

    // GLuint_t id = 0;
    // funcs->oglGenTextures(1, &id);
    // funcs->oglBindTexture(getType(), id);

    // applyParams(funcs);

    // applyStorage(funcs);

    // funcs->oglBindTexture(getType(), 0);

    // return id;
}

bool CubeMap::onUpdate(State& state)
{ return true; }

void CubeMap::applyParams(GLfuncs* funcs)
{
    FilterMode min_filter = getFilter(MIN_FILTER), mag_filter = getFilter(MAG_FILTER);
    WrapMode   wrap_s = getWrap(WRAP_S), wrap_t = getWrap(WRAP_T), wrap_r = getWrap(WRAP_R);

    if (min_filter != FILTER_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_MIN_FILTER, min_filter);
    if (mag_filter != FILTER_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_MAG_FILTER, mag_filter);
    if (wrap_s != WRAP_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_S, wrap_s);
    if (wrap_t != WRAP_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_T, wrap_t);
    if (wrap_r != WRAP_UNSET)
        funcs->oglTexParameteri(getType(), IGL_TEXTURE_WRAP_R, wrap_r);
}

void CubeMap::applyStorage(GLfuncs* funcs)
{
    for (int i = 0; i < 6; ++i) {
        auto& img      = imgs_[i];
        void* img_data = img->data();

        if (img->isNull())
            continue;

        GLsizei_t w = img->getWidth(), h = img->getHeight(), internal_fmt = img->getInternalTextureFormat();
        GLenum_t  src_type = img->getDataType(), src_format = img->getDataFormat();

        funcs->oglTexImage2D(IGL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, internal_fmt, w, h, 0, src_format, src_type, img_data);
    }
}

} // namespace glr
} // namespace xg