#include <glr/scene/Geometry.h>

#include <vine/core/Ptr.h>

#include <glr/engine/Shader.h>
#include <glr/engine/State.h>
#include <glr/engine/Texture.h>
#include <glr/engine/VertexArrayObject.h>

namespace glr {
VI_OBJECT_META_IMPL(Geometry, Drawable);

constexpr int VERTEX_LOC    = 0;
constexpr int NORMAL_LOC    = 1;
constexpr int COLOR_LOC     = 2;
constexpr int TEX_COORD_LOC = 10;

struct Geometry::Data {
    vine::RefPtr<VertexArrayObject>             vao;
    std::map<GLuint, vine::RefPtr<ArrayBuffer>> vbos;

    std::vector<std::pair<GLuint, vine::RefPtr<Texture>>> textures;
    std::map<GLuint, GLuint>                              texture_locs;
    std::map<GLuint, std::string>                         texture_names;

    std::vector<vine::RefPtr<PrimitiveSet>> primitives;

    vine::RefPtr<ArrayBuffer>                                 vertex_array;
    vine::RefPtr<ArrayBuffer>                                 normal_array;
    vine::RefPtr<ArrayBuffer>                                 color_array;
    std::vector<std::pair<vine::RefPtr<ArrayBuffer>, int>> tex_coords_arrays;

    int vertex_attrib_loc = -1;
    int normal_attrib_loc = -1;
    int color_attrib_loc  = -1;
};


Geometry::Geometry()
  : d(new Data()) {
}

Geometry::~Geometry() {
    delete d;
}

ArrayBuffer* Geometry::getVertexArray() const {
    return d->vertex_array.get();
}

void Geometry::setVertexArray(ArrayBuffer* data) {
    d->vertex_array = data;
}

ArrayBuffer* Geometry::getNormalArray() const {
    return d->normal_array.get();
}

void Geometry::setNormalArray(ArrayBuffer* data) {
    d->normal_array = data;
}

ArrayBuffer* Geometry::getColorArray() const {
    return d->color_array.get();
}

void Geometry::setColorArray(ArrayBuffer* data) {
    d->color_array = data;
}

int Geometry::getNbTexCoordArrays() const {
    return d->tex_coords_arrays.size();
}

ArrayBuffer* Geometry::getTexCoordArrayAt(int index) const {
    return d->tex_coords_arrays[index].first.get();
}

void Geometry::addTexCoordArray(ArrayBuffer* data) {
    d->tex_coords_arrays.push_back({ data, -1 });
}

void Geometry::removeTexCoordArray(ArrayBuffer* data) {
    auto found_at = std::find_if(d->tex_coords_arrays.begin(), d->tex_coords_arrays.end(), [data](auto& kv) {
        return kv.first.get() == data;
    });
    if (found_at != d->tex_coords_arrays.end()) {
        d->tex_coords_arrays.erase(found_at);
    }
}

void Geometry::clearTexCoordArrays() {
    d->tex_coords_arrays.clear();
}

int Geometry::getVertexAttribLocation() const {
    return d->vertex_attrib_loc;
}

void Geometry::setVertexAttribLocation(int loc) {
    d->vertex_attrib_loc = loc;
}

int Geometry::getNormalAttribLocation() const {
    return d->normal_attrib_loc;
}

void Geometry::setNormalAttribLocation(int loc) {
    d->normal_attrib_loc = loc;
}

int Geometry::getColorAttribLocation() const {
    return d->color_attrib_loc;
}

void Geometry::setColorAttribLocation(int loc) {
    d->color_attrib_loc = loc;
}

int Geometry::getTexCoordAttribLocation(ArrayBuffer* data) const {
    auto found_at = std::find_if(d->tex_coords_arrays.begin(), d->tex_coords_arrays.end(), [data](auto& kv) {
        return kv.first.get() == data;
    });
    if (found_at != d->tex_coords_arrays.end()) {
        return found_at->second;
    }
    return -1;
}

void Geometry::setTexCoordAttribLocation(ArrayBuffer* data, int loc) {
    auto found_at    = std::find_if(d->tex_coords_arrays.begin(), d->tex_coords_arrays.end(), [data](auto& kv) {
        return kv.first.get() == data;
    });
    found_at->second = loc;
}

int Geometry::getNbTextures() const {
    return d->textures.size();
}

Texture* Geometry::getTextureAt(int index) const {
    return d->textures.at(index).second.get();
}

GLuint Geometry::getTextureUnitAt(int index) const {
    return d->textures.at(index).first;
}

void Geometry::addTexture(GLuint unit, GLuint loc, Texture* tex) {
    auto found_at = std::find_if(d->textures.begin(), d->textures.end(), [unit](auto& kv) { return kv.first == unit; });
    if (found_at == d->textures.end()) {
        d->textures.push_back({ unit, tex });
        d->texture_locs.insert({ unit, loc });
    }
    else {
        found_at->second      = tex;
        d->texture_locs[unit] = loc;
    }
}

void Geometry::addTexture(GLuint unit, const std::string& name, Texture* tex) {
    auto found_at = std::find_if(d->textures.begin(), d->textures.end(), [unit](auto& kv) { return kv.first == unit; });
    if (found_at == d->textures.end()) {
        d->textures.push_back({ unit, tex });
        d->texture_names.insert({ unit, name });
    }
    else {
        found_at->second       = tex;
        d->texture_names[unit] = name;
    }
}

void Geometry::setTextureAttribLocation(GLuint unit, GLuint loc) {
    d->texture_locs[unit] = loc;
    d->texture_names.erase(unit);
}

void Geometry::setTextureAttribLocation(GLuint unit, const std::string& loc) {
    d->texture_names[unit] = loc;
    d->texture_locs.erase(unit);
}

void Geometry::removeTexture(Texture* tex) {
    auto textures = d->textures;
    for (auto& kv : textures) {
        if (kv.second == tex) {
            d->textures.erase(
                std::find_if(d->textures.begin(), d->textures.end(), [tex](auto& kv) { return kv.second == tex; }));
            d->texture_locs.erase(kv.first);
            d->texture_names.erase(kv.first);
            return;
        }
    }
}

void Geometry::removetexture(GLuint unit) {
    d->textures.erase(
        std::find_if(d->textures.begin(), d->textures.end(), [unit](auto& kv) { return kv.first == unit; }));
    d->texture_locs.erase(unit);
    d->texture_names.erase(unit);
}

void Geometry::clearTextures() {
    d->textures.clear();
    d->texture_locs.clear();
    d->texture_names.clear();
}

int Geometry::getNbVertexAttribArrays() const {
    return d->vbos.size();
}

ArrayBuffer* Geometry::getVertexAttribArrayAt(int index) const {
    return d->vbos[index].get();
}

void Geometry::addVertexAttribArray(GLuint loc, ArrayBuffer* arr) {
    assert(arr);
    auto found_at = d->vbos.find(loc);
    if (found_at != d->vbos.end()) {
        auto vbo = found_at->second;
        if (vbo == arr) return;
    }
    d->vbos[loc] = arr;
}

void Geometry::removeVertexAttribArray(ArrayBuffer* data) {
    auto vbos = d->vbos;
    for (auto& kv : vbos) {
        if (kv.second == data) {
            d->vbos.erase(kv.first);
            return;
        }
    }
}

void Geometry::removeVertexAttribArray(GLuint loc) {
    d->vbos.erase(loc);
}

void Geometry::clearVertexAttribArrays() {
    d->vbos.clear();
}

int Geometry::getNbPrimitiveSets() const {
    return d->vbos.size();
}

PrimitiveSet* Geometry::getPrimitiveSet(int index) const {
    return d->primitives[index].get();
}

void Geometry::addPrimitiveSet(PrimitiveSet* prim) {
    d->primitives.push_back(prim);
}

void Geometry::removePrimitiveSet(PrimitiveSet* prim) {
    auto found_at = std::find(d->primitives.begin(), d->primitives.end(), prim);
    if (found_at != d->primitives.end()) {
        d->primitives.erase(found_at);
    }
}

void Geometry::clearPrimitiveSets() {
    d->primitives.clear();
}

void Geometry::draw(State& state) {
    // if (d->vbos.empty()) return;
    if (d->primitives.empty()) return;

    auto shader = state.getCurrentShader();
    if (!d->vao) {
        auto vbos = d->vbos;

        if (d->vertex_array.get())
            vbos[d->vertex_attrib_loc == -1 ? VERTEX_LOC : d->vertex_attrib_loc] = d->vertex_array.get();
        if (d->normal_array.get())
            vbos[d->normal_attrib_loc == -1 ? NORMAL_LOC : d->normal_attrib_loc] = d->normal_array.get();
        if (d->color_array.get())
            vbos[d->color_attrib_loc == -1 ? COLOR_LOC : d->color_attrib_loc] = d->color_array.get();

        auto loc = TEX_COORD_LOC;

        for (auto& kv : d->tex_coords_arrays) {
            if (kv.first.get()) {
                if (kv.second == -1)
                    vbos[loc++] = kv.first;
                else
                    vbos[kv.second] = kv.first;
            }
        }

        if (vbos.empty()) {
            return;
        }

        d->vao = new VertexArrayObject();
        d->vao->bind(state);

        // VBOs
        for (auto& kv : vbos) {
            auto  loc = kv.first;
            auto& arr = kv.second;
            if (arr->size() > 1) {
                arr->bind(state);
                auto size_of_item = arr->sizeOfItem();
                glVertexAttribPointer(loc, size_of_item / sizeof(GLfloat), GL_FLOAT, GL_FALSE, size_of_item, 0);
                glEnableVertexAttribArray(loc);
                arr->unbind(state);
            }
            else {
                auto arr_type = arr->getType();
                if (arr_type == ArrayBuffer::ARRAY_VEC2F) {
                    Vec2f val = arr->empty() ? Vec2f(0.f, 0.f) : *(Vec2f*)arr->valueAt(0);
                    glVertexAttrib2f(loc, val.x, val.y);
                }
                else if (arr_type == ArrayBuffer::ARRAY_VEC3F) {
                    Vec3f val = arr->empty() ? Vec3f(0.f, 0.f, 0.f) : *(Vec3f*)arr->valueAt(0);
                    glVertexAttrib3f(loc, val.x, val.y, val.z);
                }
                else if (arr_type == ArrayBuffer::ARRAY_VEC4F) {
                    Vec4f val = arr->empty() ? Vec4f(0.f, 0.f, 0.f, 1.0f) : *(Vec4f*)arr->valueAt(0);
                    glVertexAttrib4f(loc, val.x, val.y, val.z, val.a);
                }
                else {
                    printf("\n Unsupport array type.\n");
                }
            }
        }
    }
    else {
        d->vao->bind(state);
    }
    for (auto& kv : d->textures) {
        auto  unit = kv.first;
        auto& tex  = kv.second;
        glActiveTexture(unit);
        tex->bind(state);
        if (d->texture_locs.contains(unit)) {
            shader->set(state, d->texture_locs[unit], (GLint)unit - GL_TEXTURE0);
        }
        else {
            shader->set(state, d->texture_names[unit], (GLint)unit - GL_TEXTURE0);
        }
    }

    for (auto priv : d->primitives) {
        priv->draw();
    }
    d->vao->unbind(state);
    for (auto& kv : d->textures) {
        auto  unit = kv.first;
        auto& tex  = kv.second;
        if (!tex) continue;
        glActiveTexture(unit);
        tex->unbind(state);
    }
}

void Geometry::onComputeBoundingBox(BoundingBox& bb) const {
}

Geometry* Geometry::createCube(float size, bool create_tex_coord) {
    auto n    = size / 2;
    auto cube = new Geometry();

    auto vertices = new Vec3fArray();
    vertices->emplace_back(-n, -n, -n);
    vertices->emplace_back(n, -n, -n);
    vertices->emplace_back(n, n, -n);
    vertices->emplace_back(n, n, -n);
    vertices->emplace_back(-n, n, -n);
    vertices->emplace_back(-n, -n, -n);

    vertices->emplace_back(-n, -n, n);
    vertices->emplace_back(n, -n, n);
    vertices->emplace_back(n, n, n);
    vertices->emplace_back(n, n, n);
    vertices->emplace_back(-n, n, n);
    vertices->emplace_back(-n, -n, n);

    vertices->emplace_back(-n, n, n);
    vertices->emplace_back(-n, n, -n);
    vertices->emplace_back(-n, -n, -n);
    vertices->emplace_back(-n, -n, -n);
    vertices->emplace_back(-n, -n, n);
    vertices->emplace_back(-n, n, n);

    vertices->emplace_back(n, n, n);
    vertices->emplace_back(n, n, -n);
    vertices->emplace_back(n, -n, -n);
    vertices->emplace_back(n, -n, -n);
    vertices->emplace_back(n, -n, n);
    vertices->emplace_back(n, n, n);

    vertices->emplace_back(-n, -n, -n);
    vertices->emplace_back(n, -n, -n);
    vertices->emplace_back(n, -n, n);
    vertices->emplace_back(n, -n, n);
    vertices->emplace_back(-n, -n, n);
    vertices->emplace_back(-n, -n, -n);

    vertices->emplace_back(-n, n, -n);
    vertices->emplace_back(n, n, -n);
    vertices->emplace_back(n, n, n);
    vertices->emplace_back(n, n, n);
    vertices->emplace_back(-n, n, n);
    vertices->emplace_back(-n, n, -n);

    auto normals = new Vec3fArray();
    normals->emplace_back(0.0f, 0.0f, -1.0f);
    normals->emplace_back(0.0f, 0.0f, -1.0f);
    normals->emplace_back(0.0f, 0.0f, -1.0f);
    normals->emplace_back(0.0f, 0.0f, -1.0f);
    normals->emplace_back(0.0f, 0.0f, -1.0f);
    normals->emplace_back(0.0f, 0.0f, -1.0f);

    normals->emplace_back(0.0f, 0.0f, 1.0f);
    normals->emplace_back(0.0f, 0.0f, 1.0f);
    normals->emplace_back(0.0f, 0.0f, 1.0f);
    normals->emplace_back(0.0f, 0.0f, 1.0f);
    normals->emplace_back(0.0f, 0.0f, 1.0f);
    normals->emplace_back(0.0f, 0.0f, 1.0f);

    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    normals->emplace_back(-1.0f, 0.0f, 0.0f);
    normals->emplace_back(-1.0f, 0.0f, 0.0f);

    normals->emplace_back(1.0f, 0.0f, 0.0f);
    normals->emplace_back(1.0f, 0.0f, 0.0f);
    normals->emplace_back(1.0f, 0.0f, 0.0f);
    normals->emplace_back(1.0f, 0.0f, 0.0f);
    normals->emplace_back(1.0f, 0.0f, 0.0f);
    normals->emplace_back(1.0f, 0.0f, 0.0f);

    normals->emplace_back(0.0f, -1.0f, 0.0f);
    normals->emplace_back(0.0f, -1.0f, 0.0f);
    normals->emplace_back(0.0f, -1.0f, 0.0f);
    normals->emplace_back(0.0f, -1.0f, 0.0f);
    normals->emplace_back(0.0f, -1.0f, 0.0f);
    normals->emplace_back(0.0f, -1.0f, 0.0f);

    normals->emplace_back(0.0f, 1.0f, 0.0f);
    normals->emplace_back(0.0f, 1.0f, 0.0f);
    normals->emplace_back(0.0f, 1.0f, 0.0f);
    normals->emplace_back(0.0f, 1.0f, 0.0f);
    normals->emplace_back(0.0f, 1.0f, 0.0f);
    normals->emplace_back(0.0f, 1.0f, 0.0f);

    // auto tex_coords = new Vec2fArray();
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);
    // tex_coords->emplace_back(1.0f, 1.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(1.0f, 0.0f);
    // tex_coords->emplace_back(0.0f, 0.0f);
    // tex_coords->emplace_back(0.0f, 1.0f);

    if (create_tex_coord) {
        auto tex_coords = new Vec3fArray();
        tex_coords->resize(vertices->size());
        std::copy(vertices->begin(), vertices->end(), tex_coords->begin());
        cube->addTexCoordArray(tex_coords);
    }
    cube->setNormalArray(normals);
    cube->setVertexArray(vertices);
    cube->addPrimitiveSet(new DrawArrays(DrawArrays::MODE_TRIANGLES, 0, vertices->size()));
    return cube;
}

Geometry* Geometry::createTexturedQuad(const vine::ge::Rect2d& rect, const vine::ge::Rect2d& uv_rect) {
    auto vertices = new Vec3fArray();
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
    texcoords->push_back(Vec2f(uv_rect.x, uv_rect.y + uv_rect.h));

    auto geom = new Geometry();
    geom->setVertexArray(vertices);
    geom->setNormalArray(norms);
    geom->addTexCoordArray(texcoords);
    geom->addPrimitiveSet(new DrawArrays(PrimitiveSet::MODE_TRIANGLE_FAN, 0, vertices->size()));
    return geom;
}
} // namespace glr