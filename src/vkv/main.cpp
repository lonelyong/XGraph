#include <cstring>
#include <filesystem>
#include <iostream>

#include <xgcomm/Environment.h>
#include <xgcomm/Text.h>

#include <vkv/io/BrepLoader.h>
#include <vkv/io/MeshLoader.h>
#include <vkv/io/PointCloudLoader.h>
#include <vkv/modeling/CurveGenerator.h>
#include <vkv/modeling/DottedCurve.h>

#include <vkv/app/Application.h>
#include <vkv/app/Viewer.h>

int main(int argc, char** argv) {

    using namespace vkv;

    AppInitializationParameters params;
    Application                 initializer(params);

    vsg::Group* model = nullptr;
    if (argc == 1) {
    }
    else {
    }

    namespace fs = std::filesystem;
    fs::current_path(xg::getApplicationDir());

    Viewer v;

    v.fitToScreen();
    v.run();

    return 0;
}