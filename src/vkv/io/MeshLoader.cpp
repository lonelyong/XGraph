//#include "MeshLoader.h"
//
//#include <assimp/Importer.hpp>
//#include <assimp/postprocess.h>
//#include <assimp/scene.h>
//#include <filesystem>
//
//#include <osg/Geode>
//#include <osg/Geometry>
//#include <osg/Material>
//#include <osg/MatrixTransform>
//#include <osgUtil/SmoothingVisitor>
//
//#include "vkv/modeling/ModelDefs.h"
//
//namespace vkv {
//
//namespace ai = Assimp;
//namespace {
//vsg::dvec4 s_default_face_color = vsg::dvec4(0.88, 0.88, 0.88, 1.0);
//
//void aiProcessNode(vsg::MatrixTransform** model, const aiScene* scene, aiNode* node) {
//    auto geod = new vsg::Geode();
//    for (int i = 0; i < node->mNumMeshes; i++) {
//        auto mesh = scene->mMeshes[node->mMeshes[i]];
//        auto geom = new vsg::Geometry();
//        if (mesh->HasPositions()) {
//            auto vertices = new vsg::Vec3Array();
//            vertices->reserve(mesh->mNumVertices);
//            vsg::dvec4 prev_vertex_color = s_default_face_color;
//            for (int j = 0; j < mesh->mNumVertices; j++) {
//                vertices->push_back(vsg::dvec3(mesh->mVertices[j].x, mesh->mVertices[j].y, mesh->mVertices[j].z));
//            }
//            geom->setVertexArray(vertices);
//        }
//        if (mesh->HasVertexColors(0)) {
//            auto colors = new vsg::Vec4Array();
//            colors->reserve(mesh->mNumVertices);
//            auto data = mesh->mColors[0];
//            for (int j = 0; j < mesh->mNumVertices; j++) {
//                colors->push_back(vsg::dvec4(data[j].r, data[j].g, data[j].b, data[j].a));
//            }
//            geom->setColorArray(colors, vsg::Array::BIND_PER_VERTEX);
//        }
//        else {
//            auto colors = new vsg::Vec4Array();
//            colors->push_back(s_default_face_color);
//            geom->setColorArray(colors, vsg::Array::BIND_OVERALL);
//        }
//        if (mesh->HasTextureCoords(0)) {
//            // todo
//        }
//        if (false && mesh->HasNormals()) {
//            auto norms = new vsg::Vec3Array();
//            norms->reserve(mesh->mNumVertices);
//            for (int j = 0; j < mesh->mNumVertices; j++) {
//                norms->push_back(vsg::dvec3(mesh->mNormals[j].x, mesh->mNormals[j].y, mesh->mNormals[j].z));
//            }
//            geom->setNormalArray(norms, vsg::Array::BIND_PER_VERTEX);
//        }
//
//        if (mesh->HasFaces()) {
//            if (false && mesh->mNumFaces * 3 == mesh->mNumVertices) {
//                geom->addPrimitiveSet(new vsg::DrawArrays(GL_TRIANGLES, 0, mesh->mNumVertices));
//            }
//            else {
//                auto indices = new vsg::DrawElementsUInt(GL_TRIANGLES);
//                for (auto j = 0; j < mesh->mNumFaces; j++) {
//                    auto face = mesh->mFaces[j];
//                    if (face.mNumIndices == 3) {
//                        indices->push_back(face.mIndices[0]);
//                        indices->push_back(face.mIndices[1]);
//                        indices->push_back(face.mIndices[2]);
//                    }
//                }
//                geom->addPrimitiveSet(indices);
//            }
//        }
//        osgUtil::SmoothingVisitor smoother;
//        smoother.setCreaseAngle(vsg::PI * 0.1);
//        geom->accept(smoother);
//        geod->addDrawable(geom);
//    }
//    auto& m  = node->mTransformation;
//    auto  mt = new vsg::MatrixTransform();
//    mt->setName(node->mName.data);
//    mt->addChild(geod);
//    mt->setMatrix(
//        vsg::Matrix(m.a1, m.b1, m.c1, m.d1, m.a2, m.b2, m.c2, m.d2, m.a3, m.b3, m.c3, m.d3, m.a4, m.b4, m.c4, m.d4));
//    for (int i = 0; i < node->mNumChildren; i++) {
//        auto                  child_node  = node->mChildren[i];
//        vsg::MatrixTransform* child_model = nullptr;
//        aiProcessNode(&child_model, scene, child_node);
//        if (child_model) {
//            mt->addChild(child_model);
//        }
//    }
//    *model = mt;
//}
//} // namespace
//
//bool MeshLoader::isSupported(const std::string& file) {
//    namespace fs = std::filesystem;
//    fs::path path(file);
//    if (!path.has_extension()) return false;
//    auto                         file_ext = path.extension().string();
//    static std::set<std::string> exts     = { ".stl", ".obj", ".gltf", ".3mf", ".3ds", ".dxf",
//                                              ".ifc", ".ac",  ".ac3d", ".lxo", ".fbx", ".dae" };
//    return exts.contains(file_ext);
//}
//
//vsg::MatrixTransform* MeshLoader::loadFile(const std::string& file) {
//    vsg::MatrixTransform* root = nullptr;
//    ai::Importer          im;
//    auto scene = im.ReadFile(file, aiProcess_CalcTangentSpace | aiProcess_Triangulate | aiProcess_GenSmoothNormals);
//    if (scene) {
//        aiProcessNode(&root, scene, scene->mRootNode);
//        if (root) {
//            setPipelineMask(root, DEFERRED_SCENE_MASK);
//        }
//        return root;
//    }
//    return root;
//}
//} // namespace vkv