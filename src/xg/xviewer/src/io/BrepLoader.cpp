#include <xg/xviewer/io/BrepLoader.hpp>

#include <filesystem>

#include <osg/Geode>
#include <osg/Geometry>
#include <osg/LineWidth>
#include <osg/MatrixTransform>
#include <osg/PolygonMode>
#include <osg/PolygonOffset>
#include <osgUtil/SmoothingVisitor>

#include <BRepMesh_IncrementalMesh.hxx>
#include <BRep_Builder.hxx>
#include <BRep_Tool.hxx>
#include <GeomLib.hxx>
#include <IGESControl_Reader.hxx>
#include <Poly_Connect.hxx>
#include <STEPControl_Reader.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TopTools.hxx>
#include <TopTools_IndexedMapOfShape.hxx>
#include <TopoDS.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shape.hxx>

#include <xg/comm/Text.hpp>

namespace xg
{
namespace xviewer
{
namespace
{

bool isStpFile(const std::string& ext)
{ return ext == ".stp" || ext == ".step"; }

bool isIgesFile(const std::string& ext)
{ return ext == ".iges" || ext == ".igs"; }

enum FileType
{
    TYPE_UNKNOW,
    TYPE_STEP,
    TYPE_IGES
};

bool isSupportedType(const std::string& file, FileType& type)
{
    namespace fs    = std::filesystem;
    auto     u8file = xg::local8bitToUtf8(file);
    fs::path path(u8file);
    if (!path.has_extension())
        return false;

    auto file_ext = path.extension().string();
    std::transform(file_ext.begin(), file_ext.end(), file_ext.begin(), ::tolower);
    if (isStpFile(file_ext))
        type = TYPE_STEP;
    else if (isIgesFile(file_ext))
        type = TYPE_IGES;
    else
        type = TYPE_UNKNOW;

    return type != TYPE_UNKNOW;
}

void computeTriangulationNormals(const TopoDS_Face& theFace, const occ::handle<Poly_Triangulation>& aPolyTri, TColgp_Array1OfDir& theNormals)
{
    Standard_Integer numNodes = aPolyTri->NbNodes();

    if (aPolyTri->HasNormals()) {
        for (Standard_Integer aNodeIter = 1; aNodeIter <= numNodes; ++aNodeIter) { theNormals(aNodeIter) = aPolyTri->Normal(aNodeIter); }

        if (theFace.Orientation() == TopAbs_REVERSED) {
            for (Standard_Integer aNodeIter = 1; aNodeIter <= numNodes; ++aNodeIter) { theNormals.ChangeValue(aNodeIter).Reverse(); }
        }
    }
    else {
        // take in face the surface location
        Poly_Connect      thePolyConnect(aPolyTri);
        const TopoDS_Face aZeroFace    = TopoDS::Face(theFace.Located(TopLoc_Location()));
        Handle(Geom_Surface) aSurf     = BRep_Tool::Surface(aZeroFace);
        const Standard_Real aTol       = Precision::Confusion();
        Standard_Boolean    hasNodesUV = aPolyTri->HasUVNodes() && !aSurf.IsNull();
        Standard_Integer    aTri[3];

        for (Standard_Integer aNodeIter = 1; aNodeIter <= numNodes; ++aNodeIter) {
            // try to retrieve normal from real surface first, when UV coordinates are available
            if (!hasNodesUV || GeomLib::NormEstim(aSurf, aPolyTri->UVNode(aNodeIter), aTol, theNormals(aNodeIter)) > 1) {
                // compute flat normals
                gp_XYZ eqPlan(0.0, 0.0, 0.0);

                for (thePolyConnect.Initialize(aNodeIter); thePolyConnect.More(); thePolyConnect.Next()) {
                    aPolyTri->Triangle(thePolyConnect.Value()).Get(aTri[0], aTri[1], aTri[2]);
                    const gp_XYZ        v1(aPolyTri->Node(aTri[1]).Coord() - aPolyTri->Node(aTri[0]).Coord());
                    const gp_XYZ        v2(aPolyTri->Node(aTri[2]).Coord() - aPolyTri->Node(aTri[1]).Coord());
                    const gp_XYZ        vv   = v1 ^ v2;
                    const Standard_Real aMod = vv.Modulus();

                    if (aMod >= aTol) { eqPlan += vv / aMod; }
                }

                const Standard_Real aModMax = eqPlan.Modulus();
                theNormals(aNodeIter)       = (aModMax > aTol) ? gp_Dir(eqPlan) : gp::DZ();
            }
        }

        if (theFace.Orientation() == TopAbs_REVERSED) {
            for (Standard_Integer aNodeIter = 1; aNodeIter <= numNodes; ++aNodeIter) { theNormals.ChangeValue(aNodeIter).Reverse(); }
        }
    }
}

} // namespace

bool BrepLoader::isSupported(const std::string& file)
{
    FileType type;
    return isSupportedType(file, type);
}

osg::MatrixTransform* BrepLoader::loadFile(const std::string& file)
{
    FileType type;
    if (!isSupportedType(file, type))
        return nullptr;

    XSControl_Reader* reader = nullptr;
    if (type == TYPE_STEP)
        reader = new STEPControl_Reader();
    else if (type == TYPE_IGES)
        reader = new IGESControl_Reader();

    if (!reader)
        return nullptr;

    auto u8path = xg::local8bitToUtf8(file);
    auto status = reader->ReadFile(u8path.data());
    if (status != IFSelect_RetDone)
        return nullptr;

    reader->TransferRoots();
    TopoDS_Shape shape;
    if (reader->NbShapes() > 1) {
        BRep_Builder    builder;
        TopoDS_Compound compound;
        builder.MakeCompound(compound);
        for (int i = 1; i <= reader->NbShapes(); i++) { builder.Add(compound, reader->Shape(i)); }
        shape = compound;
    }
    else {
        shape = reader->OneShape();
    }

    delete reader;

    std::set<int>              all_edge_indices;
    TopTools_IndexedMapOfShape face_map;
    TopTools_IndexedMapOfShape edge_map;

    TopExp::MapShapes(shape, TopAbs_FACE, face_map);
    TopExp::MapShapes(shape, TopAbs_EDGE, edge_map);

    for (int i = 1; i <= edge_map.Extent(); i++) { all_edge_indices.insert(i); }

    auto face_geod   = new osg::Geode();
    auto edge_geod   = new osg::Geode();
    auto face_colors = new osg::Vec4Array();
    auto edge_colors = new osg::Vec4Array();
    face_colors->push_back(osg::Vec4(220.f / 255, 223.f / 255, 0.f / 255, 1.f));
    edge_colors->push_back(osg::Vec4(0.2f, 0.2f, 0.2f, 1.f));

    // see https://dev.opencascade.org/doc/occt-7.9.0/overview/html/occt_user_guides__mesh.html
    // see https://occt3d.com/dev/doc/overview/html/occt_user_guides__mesh.html
    IMeshTools_Parameters params;
    // Maximum angular deviation (in radians) between the generated mesh segment and the tangent direction of the original geometric curve at the segment
    // endpoints.
    /*
     * Angle (double, default = 0.5 radians ≈28.6°). Angular deflection for boundary edges. This controls how sharply a curved edge can be approximated. Smaller
     * Angle → more subdivided edges. In OCCT, this sets the maximum allowed angle between consecutive segments in the polyline approximation of each edge.
     * Roughly, if two segments meet at an angle larger than Angle, the edge is subdivided further. In practice, reducing Angle yields a finer mesh on curved
     * edges, while increasing it produces a coarser, more faceted approximation. For example, a common default is ~15°–30°. */
    params.Angle                    = 0.2;
    // Maximum linear deviation between the original geometric edge and the generated polygonal approximation.
    /*
     * Deflection (double, default = 0.001). Linear deflection for boundary edges. This is the maximum distance allowed between the true curve and its polygonal
     * approximation. A smaller Deflection forces more edge subdivisions (finer mesh), while a larger value allows coarser edges. The mesher attempts to keep
     * the distance from the original edge to the mesh edge below this value. Note: if Deflection is set smaller than the surface’s tolerance, the algorithm by
     * default will actually use the (larger) shape tolerance instead. To override this and force the given Deflection, enable ForceFaceDeflection (see
     * below).*/
    params.Deflection               = 1;
    // angle(N1, N2) <= Angle
    // angle(N2, N3) <= Angle
    /*
     * AngleInterior (double, default = –1.0, meaning “use default”). Angular deflection for face interior. This applies to the triangulation within a face (not
     * along its edges), particularly for NURBS/B-spline faces. It limits the angle between the normals of adjacent triangles inside the face. A smaller
     * AngleInterior will produce smoother curvature inside faces at the cost of more triangles. The default value of –1.0 tells the mesher to use a fallback
     * strategy (often it will use the same value as Angle or a project-specific default). Because interior angles often have less visual impact, this parameter
     * is sometimes left at default unless one needs extra accuracy on smooth surfaces.
     */
    params.AngleInterior            = 0.2;
    // Linear deflection defines the maximum allowed distance deviation between the original geometric surface and the generated triangulation.
    /*
     * DeflectionInterior (double, default = –1.0). Linear deflection for face interior. This controls the maximum distance of interior triangles from the true
     * surface. Like Deflection for edges, smaller values produce more triangles on the face interior. The default –1.0 again triggers an automatic choice
     * (often it uses the same value as Deflection). Use a positive value to enforce a stricter interior tolerance; otherwise interior triangles may be coarser.
     * The Wiki notes that DeflectionInterior “limits the distance between triangles and the face interior,” and it works together with AngleInterior to control
     * mesh density inside the face.
     */
    params.DeflectionInterior       = 1;
    /*
     * MinSize (double, default = –1.0). A lower bound on mesh element size (edge length) to prevent runaway refinement. This “handbrake” stops triangles from
     * becoming too small even if angle/deflection criteria demand further subdivision. By default (MinSize<0), OCCT computes a min size as a fraction of
     * Deflection: specifically, MinSize = RelMinSize() * Deflection, where RelMinSize() is a static function returning 0.1. (Thus default min edge length ≈
     * 0.1×Deflection.) You can override it by setting a positive MinSize: then no triangle edge will be smaller than that absolute value. This is useful to
     * avoid extremely dense meshes in pathological cases.
     */
    params.MinSize                  = 1e-4;
    /*
     * InParallel (bool, default = Standard_False). Enable multi-threaded meshing. If true, the mesher will try to distribute work over multiple CPU threads
     * (for example, processing multiple faces in parallel). This can greatly speed up meshing large compounds of shapes on multi-core machines. If false, all
     * meshing runs in a single thread. Use InParallel = true for faster performance when thread safety is desired (and thread resources are available).
     */
    params.InParallel               = true;
    /*
     * Relative (bool, default = Standard_False). Use relative deflection scaling. When false, the Deflection and DeflectionInterior are treated as absolute
     * distances. When true, the linear deflection for each edge is multiplied by that edge’s length, and for faces the deflection is taken as the maximum of
     * its edges’ deflections. In other words, defl_edge = Deflection * (edge length). This mode is akin to a level-of-detail (LOD) scaling: larger shapes get
     * proportionally larger mesh tolerances. The overview guide notes that using a relative deflection lets imported models of varying size be meshed without
     * manual parameter tuning. In summary, set Relative = true to have the mesh adapt to part dimensions; set false for an absolute metric tolerance.
     */
    params.Relative                 = true;
    /*
     * InternalVerticesMode (bool, default = Standard_True). Include or skip “interior” face vertices. When true, any vertices lying inside a face (e.g.
     * intersection points, or existing interior nodes) are retained in the triangulation, yielding a more faithful mesh. When false, the mesher will ignore
     * those interior vertices and produce a “clean” triangulation of each face, which can be faster but may lose detail. In effect, InternalVerticesMode = true
     * (the OCCT default) ensures that complex faces with internal seams or cracks preserve those vertices in the mesh, improving fidelity on curved faces.
     * Setting it to false can speed up meshing at the expense of missing subtle interior features. (One source puts it succinctly as “Add interior vertices for
     * better curved face fidelity (slower, set false for speed)”.)
     */
    params.InternalVerticesMode     = true;
    /*
     * ControlSurfaceDeflection (bool, default = Standard_True). Enables an extra pass to enforce deflection on triangles that deviate from the underlying
     * surface. After initial tessellation, the mesher can check all triangles against the actual surface and refine any that “bulge” beyond the specified
     * tolerances. If ControlSurfaceDeflection = true (the default), the algorithm does this extra refinement step to improve accuracy; if false, it skips that
     * check (speeding up meshing but risking coarser results). In other words, true means “post-refine any triangle exceeding the deflection,” whereas false
     * may leave some triangles slightly outside the ideal tolerance. Bitbybit’s OCCT docs describe this as “extra post-pass refining [of] triangles that bulge
     * beyond the deflection (slower, set false for speed)”.
     */
    params.ControlSurfaceDeflection = true;
    /*
     * ForceFaceDeflection (bool, default = Standard_False). If false (the default), OCCT will respect shape tolerances when deciding face deflections (meaning
     * it may effectively use the larger of DeflectionInterior and the face’s built-in tolerance). If true, the given DeflectionInterior is enforced even if it
     * is smaller than the tolerance. In other words, when enabled, force the user’s deflection regardless of any surface tolerance. This can yield denser
     * meshes than usual on very precise geometry. The brief doc says it “enables/disables usage of shape tolerances for computing face deflection”. Use
     * ForceFaceDeflection = true if you want the mesher to ignore built-in tolerances and apply your DeflectionInterior strictly; otherwise leave it false to
     * allow OCCT to use natural tolerances.
     */
    params.ForceFaceDeflection      = false;
    params.CleanModel               = true;
    /*
     * AllowQualityDecrease (bool, default = Standard_False). Controls whether the mesher is allowed to coarsen an existing mesh on the shape. By default
     * (false), if a shape already has triangulation, the mesher will only refine/improve the mesh (make it finer) to meet the new parameters, but will never
     * replace it with a worse (lower-quality) mesh. If you set AllowQualityDecrease = true, then the mesher can drop mesh quality compared to any pre-existing
     * mesh (for example, if you deliberately increase deflection for a quick pass). In effect, this flag forbids or permits “downgrading” a mesh. It is rarely
     * needed; the default policy is to preserve or improve existing triangulation. Use this only if you explicitly want the mesher to override a fine mesh with
     * a coarser one.
     */
    params.AllowQualityDecrease     = false;
    /*
     * AdjustMinSize (bool, default = Standard_False). When enabled, the algorithm will locally adjust the MinSize limit for each edge based on that edge’s
     * length. In other words, the minimum allowed triangle edge size is scaled per-edge rather than global. If false (default), the same MinSize applies
     * uniformly. Setting AdjustMinSize = true can help prevent over-refinement on very short edges: long edges may have a larger effective minimum than short
     * edges. This is an advanced option. It is documented as “local adjustment of min size depending on edge size.” The exact internal rule is: if
     * AdjustMinSize is on, the code reduces the “handbrake” MinSize for shorter edges so that small edges don’t force a uniformly small min-size everywhere. If
     * you encounter oddly coarse mesh on tiny features, disabling this may give more uniform behavior.
     */
    params.AdjustMinSize            = true;

    BRepMesh_IncrementalMesh im(shape, params);
    im.Perform();

    for (int i = 1; i <= face_map.Extent(); i++) {
        auto&           face = TopoDS::Face(face_map(i));
        TopLoc_Location loc;

        // 返回局部坐标下的三角网格，通过输出参数 loc 单独给出位置变换。
        // OpenCASCADE 文档明确规定网格节点坐标不含 location。
        auto& mesh = BRep_Tool::Triangulation(face, loc);
        if (mesh.IsNull())
            continue;

        auto vertices = new osg::Vec3Array();
        auto norms    = new osg::Vec3Array();
        auto indices  = new osg::DrawElementsUInt(GL_TRIANGLES);
        vertices->reserve(mesh->NbNodes());
        norms->reserve(mesh->NbNodes());
        indices->reserve(mesh->NbTriangles() * 3);
        for (auto i = 1; i <= mesh->NbNodes(); i++) {
            auto pnt = mesh->Node(i);
            pnt.Transform(loc.Transformation());
            vertices->push_back(osg::Vec3(pnt.X(), pnt.Y(), pnt.Z()));
        }
        for (auto i = 1; i <= mesh->NbTriangles(); i++) {
            Standard_Integer v1, v2, v3;
            const auto&      tri = mesh->Triangle(i);
            tri.Get(v1, v2, v3);
            if (face.Orientation() == TopAbs_REVERSED)
                std::swap(v1, v2);
            indices->push_back(v1 - 1);
            indices->push_back(v2 - 1);
            indices->push_back(v3 - 1);
        }
        TColgp_Array1OfDir occ_norms(1, mesh->NbNodes());
        computeTriangulationNormals(face, mesh, occ_norms);
        for (auto& n : occ_norms) {
            n.Transform(loc.Transformation());
            norms->push_back(osg::Vec3(n.X(), n.Y(), n.Z()));
        }

        auto face_geom = new osg::Geometry();
        face_geom->setColorArray(face_colors, osg::Array::BIND_OVERALL);
        face_geom->setVertexArray(vertices);
        face_geom->setNormalArray(norms, osg::Array::BIND_PER_VERTEX);
        face_geom->addPrimitiveSet(indices);
        face_geom->setUseDisplayList(false);
        face_geom->setUseVertexBufferObjects(true);
        // face_geom->setUseVertexArrayObject(true);
        //  osgUtil::SmoothingVisitor().smooth(*face_geom);
        face_geod->addDrawable(face_geom);

        TopExp_Explorer exp(face, TopAbs_EDGE);
        for (; exp.More(); exp.Next()) {
            auto& edge       = TopoDS::Edge(exp.Current());
            auto  edge_index = edge_map.FindIndex(edge);
            if (all_edge_indices.find(edge_index) == all_edge_indices.end())
                continue;
            all_edge_indices.erase(edge_index);
            auto& polygon = BRep_Tool::PolygonOnTriangulation(edge, mesh, loc);
            if (polygon.IsNull())
                continue;
            auto& nodes     = polygon->Nodes();
            auto  edge_geom = new osg::Geometry();

#if true
            vertices = new osg::Vec3Array();
            for (int i = nodes.Lower(); i <= nodes.Upper(); i++) {
                auto pnt = mesh->Node(nodes(i));
                pnt.Transform(loc.Transformation());
                vertices->push_back(osg::Vec3(pnt.X(), pnt.Y(), pnt.Z()));
            }
            edge_geom->addPrimitiveSet(new osg::DrawArrays(GL_LINE_STRIP, 0, vertices->size()));
#else
            indices = new osg::DrawElementsUInt(GL_LINE_STRIP);
            for (auto i : nodes) { indices->push_back(i); }
            edge_geom->addPrimitiveSet(indices);
#endif

            edge_geom->setVertexArray(vertices);
            edge_geom->setColorArray(edge_colors, osg::Array::BIND_OVERALL);
            edge_geom->setUseDisplayList(false);
            edge_geom->setUseVertexBufferObjects(true);
            // edge_geom->setUseVertexArrayObject(true);
            edge_geod->addDrawable(edge_geom);
        }
    }

    edge_geod->getOrCreateStateSet()->setAttributeAndModes(new osg::LineWidth(1.0f), 1);
    edge_geod->getOrCreateStateSet()->setMode(GL_LIGHTING, 0);
    face_geod->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonOffset(2.f, 2.f), 1);
    // face_geod->getOrCreateStateSet()->setAttributeAndModes(new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK,
    // osg::PolygonMode::LINE));

    auto root = new osg::MatrixTransform();
    root->addChild(face_geod);
    root->addChild(edge_geod);

    return root;
}

} // namespace xviewer
} // namespace xg
