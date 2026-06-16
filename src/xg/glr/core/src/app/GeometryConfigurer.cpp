#include <xg/glr/app/GeometryConfigurer.h>

#include <xg/glr/engine/StateSet.h>
#include <xg/glr/engine/Subroutine.h>
#include <xg/glr/engine/Texture.h>
#include <xg/glr/scene/Geometry.h>

namespace xg {
namespace glr {

void GeometryConfigurer::configureStdPhong(Geometry* geom, StateSet* ss /*= nullptr*/) {
    if (!geom) return;

    auto subroutine = "fetchMaterialColor";

    if (geom->getVertexArray()) {
        geom->setVertexAttribLocation(0);
    }
    if (geom->getNormalArray()) {
        geom->setNormalAttribLocation(1);
    }
    if (geom->getColorArray()) {
        geom->setColorAttribLocation(2);
        subroutine = "fetchVertexColor";
    }

    if (geom->getNumTexCoordArrays() > 0) {
        auto arr      = geom->getTexCoordArrayAt(0);
        auto arr_type = arr->getType();
        if (arr_type == ArrayBuffer::ARRAY_VEC2F) {
            geom->setTexCoordAttribLocation(arr, 3);
        }
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
            subroutine  = "fetchTexture2D";
            tex_uniform = "tex_2d";
        }
        else if (tex_type == Texture::TEXTURE_3D) {
            subroutine  = "fetchTexture3D";
            tex_uniform = "tex_3d";
        }
        else if (tex_type == Texture::TEXTURE_CUBE_MAP) {
            subroutine  = "fetchTextureCube";
            tex_uniform = "tex_cube";
        }

        geom->setTextureAttribLocation(tex_unit, tex_uniform);
    }
    if (ss == nullptr) {
        ss = geom->getOrCreateStateSet();
    }
    ss->setAttribute(new Subroutine(Subroutine::FRAGMENT_SHADER, subroutine));
}

} // namespace glr
} // namespace xg
