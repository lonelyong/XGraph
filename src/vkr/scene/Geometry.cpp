#include <vkr/scene/Geometry.h>

#include <vine/core/Ptr.h>

#include <vkr/engine/Shader.h>
#include <vkr/engine/State.h>

namespace vkr {
VI_OBJECT_META_IMPL(Geometry, Drawable);

struct Geometry::Data {
    // std::map<GLuint, vine::RefPtr<Texture>>     textures;
    std::map<int, int>                      texture_locs;
    std::map<int, std::string>              texture_names_;
    std::vector<vine::RefPtr<PrimitiveSet>> primitives;
};

Geometry::Geometry()
  : d(new Data()) {
}

Geometry::~Geometry() {
    delete d;
}

void Geometry::addTexture(int unit, int loc, Texture* tex) {
    // auto found_at = d->textures.find(unit);
    // if (found_at != d->textures.end()) {
    //     auto t = found_at->second;
    //     if (t == tex) return;
    // }
    // d->textures[unit]     = tex;
    // d->texture_locs[unit] = loc;
}

void Geometry::addTexture(int unit, const std::string& name, Texture* tex) {
    // auto found_at = d->textures.find(unit);
    // if (found_at != d->textures.end()) {
    //     auto t = found_at->second;
    //     if (t == tex) return;
    // }
    // d->textures[unit]       = tex;
    // d->texture_names_[unit] = name;
}

void Geometry::addVertexAttribArray(int loc, ArrayBuffer* arr) {
    assert(arr);
    // auto found_at = d->vbos.find(loc);
    // if (found_at != d->vbos.end()) {
    //     auto vbo = found_at->second;
    //     if (vbo == arr) return;
    // }
    // d->vbos[loc] = arr;
}

void Geometry::addPrimitiveSet(PrimitiveSet* prim) {
    d->primitives.push_back(prim);
}

void Geometry::draw(State& state) {
    // if (d->vbos.empty()) return;
    // if (d->primitives.empty()) return;
}

void Geometry::onComputeBoundingBox(BoundingBox& bb) const {
}

Geometry*
Geometry::createCube(float size, int vertices_loc, int normals_loc, int tex_2d_coords_loc, int cube_map_coords_loc) {
    auto n    = size / 2;
    auto cube = new Geometry();

    // auto vertices = new Vec3fArray();
    // vertices->emplace_back(-n, -n, -n);
    // vertices->emplace_back(n, -n, -n);
    // vertices->emplace_back(n, n, -n);
    // vertices->emplace_back(n, n, -n);
    // vertices->emplace_back(-n, n, -n);
    // vertices->emplace_back(-n, -n, -n);

    // vertices->emplace_back(-n, -n, n);
    // vertices->emplace_back(n, -n, n);
    // vertices->emplace_back(n, n, n);
    // vertices->emplace_back(n, n, n);
    // vertices->emplace_back(-n, n, n);
    // vertices->emplace_back(-n, -n, n);

    // vertices->emplace_back(-n, n, n);
    // vertices->emplace_back(-n, n, -n);
    // vertices->emplace_back(-n, -n, -n);
    // vertices->emplace_back(-n, -n, -n);
    // vertices->emplace_back(-n, -n, n);
    // vertices->emplace_back(-n, n, n);

    // vertices->emplace_back(n, n, n);
    // vertices->emplace_back(n, n, -n);
    // vertices->emplace_back(n, -n, -n);
    // vertices->emplace_back(n, -n, -n);
    // vertices->emplace_back(n, -n, n);
    // vertices->emplace_back(n, n, n);

    // vertices->emplace_back(-n, -n, -n);
    // vertices->emplace_back(n, -n, -n);
    // vertices->emplace_back(n, -n, n);
    // vertices->emplace_back(n, -n, n);
    // vertices->emplace_back(-n, -n, n);
    // vertices->emplace_back(-n, -n, -n);

    // vertices->emplace_back(-n, n, -n);
    // vertices->emplace_back(n, n, -n);
    // vertices->emplace_back(n, n, n);
    // vertices->emplace_back(n, n, n);
    // vertices->emplace_back(-n, n, n);
    // vertices->emplace_back(-n, n, -n);

    // if (normals_loc >= 0) {
    //     auto normals = new Vec3fArray();
    //     normals->emplace_back(0.0f, 0.0f, -1.0f);
    //     normals->emplace_back(0.0f, 0.0f, -1.0f);
    //     normals->emplace_back(0.0f, 0.0f, -1.0f);
    //     normals->emplace_back(0.0f, 0.0f, -1.0f);
    //     normals->emplace_back(0.0f, 0.0f, -1.0f);
    //     normals->emplace_back(0.0f, 0.0f, -1.0f);

    //    normals->emplace_back(0.0f, 0.0f, 1.0f);
    //    normals->emplace_back(0.0f, 0.0f, 1.0f);
    //    normals->emplace_back(0.0f, 0.0f, 1.0f);
    //    normals->emplace_back(0.0f, 0.0f, 1.0f);
    //    normals->emplace_back(0.0f, 0.0f, 1.0f);
    //    normals->emplace_back(0.0f, 0.0f, 1.0f);

    //    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(-1.0f, 0.0f, 0.0f);

    //    normals->emplace_back(1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(1.0f, 0.0f, 0.0f);
    //    normals->emplace_back(1.0f, 0.0f, 0.0f);

    //    normals->emplace_back(0.0f, -1.0f, 0.0f);
    //    normals->emplace_back(0.0f, -1.0f, 0.0f);
    //    normals->emplace_back(0.0f, -1.0f, 0.0f);
    //    normals->emplace_back(0.0f, -1.0f, 0.0f);
    //    normals->emplace_back(0.0f, -1.0f, 0.0f);
    //    normals->emplace_back(0.0f, -1.0f, 0.0f);

    //    normals->emplace_back(0.0f, 1.0f, 0.0f);
    //    normals->emplace_back(0.0f, 1.0f, 0.0f);
    //    normals->emplace_back(0.0f, 1.0f, 0.0f);
    //    normals->emplace_back(0.0f, 1.0f, 0.0f);
    //    normals->emplace_back(0.0f, 1.0f, 0.0f);
    //    normals->emplace_back(0.0f, 1.0f, 0.0f);
    //    cube->addVertexAttribArray(normals_loc, normals);
    //}
    // if (tex_2d_coords_loc >= 0) {
    //    auto tex_coords = new Vec2fArray();
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);
    //    tex_coords->emplace_back(1.0f, 1.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(1.0f, 0.0f);
    //    tex_coords->emplace_back(0.0f, 0.0f);
    //    tex_coords->emplace_back(0.0f, 1.0f);

    //    cube->addVertexAttribArray(tex_2d_coords_loc, tex_coords);
    //}
    // if (cube_map_coords_loc >= 0) {
    //    auto tex_coords = new Vec3fArray();
    //    tex_coords->resize(vertices->size());
    //    std::copy(vertices->begin(), vertices->end(), tex_coords->begin());
    //    cube->addVertexAttribArray(cube_map_coords_loc, tex_coords);
    //}
    // cube->addVertexAttribArray(vertices_loc, vertices);
    // cube->addPrimitiveSet(new DrawArrays(DrawArrays::MODE_TRIANGLES, 0, vertices->size()));
    return cube;
}

Geometry* Geometry::createTexturedQuad(int                     vertices_loc,
                                       int                     norms_loc,
                                       int                     tex_coords_loc,
                                       const vine::ge::Rect2d& rect,
                                       const vine::ge::Rect2d& uv_rect) {
    /*auto vertices = new Vec3fArray();
    vertices->push_back(Vec3f(rect.x, rect.y, 0));
    vertices->push_back(Vec3f(rect.x + rect.w, rect.y, 0));
    vertices->push_back(Vec3f(rect.x + rect.w, rect.y + rect.h, 0));
    vertices->push_back(Vec3f(rect.x, rect.y + rect.h, 0));

    auto norms = new Vec3fArray();
    norms->push_back(Vec3f(0, 0, 1));

    auto texcoords = new Vec2fArray();
    texcoords->push_back(Vec2f(uv_rect.x, uv_rect.y));
    texcoords->push_back(Vec2f(uv_rect.x + uv_rect.w, uv_rect.y));
    texcoords->push_back(Vec2f(uv_rect.x + uv_rect.w, uv_rect.y + uv_rect.h));
    texcoords->push_back(Vec2f(uv_rect.x, uv_rect.y + uv_rect.h));*/

    auto geom = new Geometry();
    // geom->addVertexAttribArray(vertices_loc, vertices);
    // geom->addVertexAttribArray(norms_loc, norms);
    // geom->addVertexAttribArray(tex_coords_loc, texcoords);
    // geom->addPrimitiveSet(new DrawArrays(PrimitiveSet::MODE_TRIANGLE_FAN, 0, vertices->size()));
    return geom;
}
} // namespace vkr