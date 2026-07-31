#include <xg/igl/app/GeometryConfigurer.hpp>

#include <xg/igl/engine/StateSet.hpp>
#include <xg/igl/engine/Texture.hpp>
#include <xg/igl/engine/Uniform.hpp>
#include <xg/igl/scene/Geometry.hpp>

namespace xg
{
namespace glr
{

namespace
{

/** @brief tex_mode values — must match the #defines in StdPhong.fs.glsl. */
enum TexMode : int
{
    TEX_MODE_VERTEX       = 0,
    TEX_MODE_MATERIAL     = 1,
    TEX_MODE_TEXTURE_2D   = 2,
    TEX_MODE_TEXTURE_CUBE = 3,
    TEX_MODE_TEXTURE_3D   = 4,
};

} // namespace

void GeometryConfigurer::configureStdPhong(Geometry* geom, StateSet* ss /*= nullptr*/)
{
    if (!geom)
        return;

    int tex_mode = TEX_MODE_MATERIAL;

    if (geom->getVertexArray()) { geom->setVertexAttribLocation(0); }
    if (geom->getNormalArray()) { geom->setNormalAttribLocation(1); }
    if (geom->getColorArray()) {
        geom->setColorAttribLocation(2);
        tex_mode = TEX_MODE_VERTEX;
    }

    if (geom->getNumTexCoordArrays() > 0) {
        auto arr      = geom->getTexCoordArrayAt(0);
        auto arr_type = arr->getType();
        if (arr_type == ArrayBuffer::ARRAY_VEC2F) { geom->setTexCoordAttribLocation(arr, 3); }
        else if (arr_type == ArrayBuffer::ARRAY_VEC3F) {
            geom->setTexCoordAttribLocation(arr, 4);
        }
    }

    if (geom->getNumTextures() > 0) {
        auto tex         = geom->getTextureAt(0);
        auto tex_unit    = geom->getTextureUnitAt(0);
        auto tex_type    = tex->getType();
        auto tex_uniform = "";

        if (tex_type == Texture::TEXTURE_2D) {
            tex_mode    = TEX_MODE_TEXTURE_2D;
            tex_uniform = "tex_2d";
        }
        else if (tex_type == Texture::TEXTURE_3D) {
            tex_mode    = TEX_MODE_TEXTURE_3D;
            tex_uniform = "tex_3d";
        }
        else if (tex_type == Texture::TEXTURE_CUBE_MAP) {
            tex_mode    = TEX_MODE_TEXTURE_CUBE;
            tex_uniform = "tex_cube";
        }

        geom->setTextureAttribLocation(tex_unit, tex_uniform);
    }
    if (ss == nullptr) { ss = geom->getOrCreateStateSet(); }
    ss->setAttribute(new Uniform("tex_mode", tex_mode));
}

} // namespace glr
} // namespace xg
