#include "MeshLoader.h"

#include <filesystem>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

#include <glr/engine/ArrayBuffer.h>
#include <glr/scene/Geometry.h>
#include <glr/scene/Model.h>

namespace glr {

namespace ai = Assimp;
namespace {
Vec4f s_default_face_color = Vec4f(0.88, 0.88, 0.88, 1.0);

void aiProcessNode(Model* group, const aiScene* scene, aiNode* node) {
    for (int i = 0; i < node->mNumMeshes; i++) {
        auto        mesh = scene->mMeshes[node->mMeshes[i]];
        auto        geom = new Geometry();
        BoundingBox bb;
        if (mesh->HasPositions()) {
            auto vertices = new Vec3fArray();
            vertices->reserve(mesh->mNumVertices);
            Vec4f prev_vertex_color = s_default_face_color;
            for (int j = 0; j < mesh->mNumVertices; j++) {
                vertices->push_back(Vec3f(mesh->mVertices[j].x, mesh->mVertices[j].y, mesh->mVertices[j].z));
                bb.expandBy(vertices->back());
            }
            geom->setVertexArray(vertices);
        }
        if (mesh->HasVertexColors(0)) {
            auto colors = new Vec4fArray();
            colors->reserve(mesh->mNumVertices);
            auto data = mesh->mColors[0];
            for (int j = 0; j < mesh->mNumVertices; j++) {
                colors->push_back(Vec4f(data[j].r, data[j].g, data[j].b, data[j].a));
            }
            geom->setColorArray(colors);
        }
        else {
            auto colors = new Vec4fArray();
            colors->push_back(s_default_face_color);
            geom->setColorArray(colors);
        }
        if (mesh->HasTextureCoords(0)) {
            // todo
        }
        if (mesh->HasNormals()) {
            auto norms = new Vec3fArray();
            norms->reserve(mesh->mNumVertices);
            for (int j = 0; j < mesh->mNumVertices; j++) {
                norms->push_back(Vec3f(mesh->mNormals[j].x, mesh->mNormals[j].y, mesh->mNormals[j].z));
            }
            geom->setNormalArray(norms);
        }

        if (mesh->HasFaces()) {
            auto indices = std::vector<GLuint_t>();
            indices.reserve(mesh->mNumFaces * 3);
            for (auto j = 0; j < mesh->mNumFaces; j++) {
                auto face = mesh->mFaces[j];
                if (face.mNumIndices == 3) {
                    indices.push_back(face.mIndices[0]);
                    indices.push_back(face.mIndices[1]);
                    indices.push_back(face.mIndices[2]);
                }
            }
            auto prim = new DrawElementsUInt(PrimitiveSet::MODE_TRIANGLES);
            prim->setIndices(indices);
            geom->addPrimitiveSet(prim);
        }
        geom->setBoundingBox(bb);
        group->addDrawable(geom);
    }
    for (int i = 0; i < node->mNumChildren; i++) {
        auto child_node = node->mChildren[i];
        aiProcessNode(group, scene, child_node);
    }
}
} // namespace

bool MeshLoader::isSupported(const std::string& file) {
    namespace fs = std::filesystem;
    fs::path path(file);
    if (!path.has_extension()) return false;
    auto                         file_ext = path.extension().string();
    static std::set<std::string> exts     = { ".stl", ".obj", ".gltf", ".3mf", ".3ds", ".dxf",
                                              ".ifc", ".ac",  ".ac3d", ".lxo", ".fbx", ".dae" };
    return exts.contains(file_ext);
}

Model* MeshLoader::loadFile(const std::string& file) {
    ai::Importer im;
    auto scene = im.ReadFile(file, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_GenSmoothNormals);
    if (scene) {
        auto model = new Model();

        aiProcessNode(model, scene, scene->mRootNode);
        return model;
    }
    return nullptr;
}
} // namespace glr