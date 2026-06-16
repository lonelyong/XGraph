set(TARGET_NAME xviewer)

option(XG_XVIEWER_BUILD_WITH_OSGVERSE "Build with osgVerse." OFF)

find_package(OpenSceneGraph CONFIG REQUIRED COMPONENTS osgDB osgText osgGA osgUtil osgViewer)
find_package(opencascade CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(PCL CONFIG REQUIRED)
find_package(VTK CONFIG REQUIRED)
find_package(octomap CONFIG REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets)

if(XG_XVIEWER_BUILD_WITH_OSGVERSE)
    find_package(osgVerse CONFIG REQUIRED)
endif()

qt_standard_project_setup()

file(GLOB SRC_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

file(GLOB SRC_FILES_IO io/*.cpp)
file(GLOB HEADER_FILES_IO io/*.h)

file(GLOB SRC_FILES_MODELING modeling/*.cpp)
file(GLOB HEADER_FILES_MODELING modeling/*.h)

file(GLOB SRC_FILES_APP app/*.cpp)
file(GLOB HEADER_FILES_APP app/*.h)

file(GLOB SRC_FILES_UTILS utils/*.cpp)
file(GLOB HEADER_FILES_UTILS utils/*.h)

set(RES_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res/)
set(RES_OUTPUT_DIR ${XG_RES_OUTPUT_DIR_BUILD}/${TARGET_NAME}/)
set(RES_SHADER_OUTPUT_DIR ${RES_OUTPUT_DIR}shaders/)
set(RES_IMAGE_OUTPUT_DIR ${RES_OUTPUT_DIR}images/)
file(GLOB RES_SHADER_FILES ${RES_SRC_DIR}shaders/*.*)
file(GLOB RES_IMAGE_FILES ${RES_SRC_DIR}images/*.*)

add_executable(
    ${TARGET_NAME}
    ${SRC_FILES} 
    ${HEADER_FILES} 
    ${SRC_FILES_IO} 
    ${HEADER_FILES_IO} 
    ${SRC_FILES_MODELING} 
    ${HEADER_FILES_MODELING}
    ${SRC_FILES_APP}
    ${HEADER_FILES_APP}
    ${SRC_FILES_UTILS}
    ${HEADER_FILES_UTILS}
    ${BACKWARD_SRC_FILES}
)

target_sources(${TARGET_NAME} PRIVATE ${RES_SHADER_FILES} ${RES_IMAGE_FILES})

source_group(io FILES ${HEADER_FILES_IO} ${SRC_FILES_IO})
source_group(modeling FILES ${HEADER_FILES_MODELING} ${SRC_FILES_MODELING})
source_group(app FILES ${SRC_FILES_APP} ${HEADER_FILES_APP})
source_group(utils FILES ${SRC_FILES_UTILS} ${HEADER_FILES_UTILS})
source_group(res/images FILES ${RES_IMAGE_FILES})
source_group(res/shaders FILES ${RES_SHADER_FILES})
source_group(third/backward FILES ${BACKWARD_SRC_FILES})


target_include_directories(${TARGET_NAME}
    PRIVATE 
        ${BACKWARD_INCLUDE_DIR}
        ${GLAD_INCLUDE_DIR}
        
)
target_link_libraries(${TARGET_NAME} 
    PRIVATE
        xg::glr-core
        xg::comm
        glfw
        assimp::assimp
        TKernel TKXSBase TKMesh TKBRep TKDESTEP TKDEIGES TKMath TKGeomBase TKGeomAlgo TKG3d
        VTK::CommonCore VTK::IOPLY VTK::FiltersCore VTK::IOGeometry
        opengl32.lib
        octomap octomath octomap-static octomath-static
        Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets
        ${OpenSceneGraph_TARGETS}
        ${osgVerse_LIBRARIES}
        ${PCL_LIBRARIES}
)

target_include_directories(${TARGET_NAME} 
    PRIVATE
        $<BUILD_INTERFACE:${OSG_INCLUDE_DIR}>
)

if(XG_XVIEWER_BUILD_WITH_OSGVERSE)
    target_include_directories(${TARGET_NAME} 
        PRIVATE 
            $<BUILD_INTERFACE:${osgVerse_INCLUDE_DIRS}>
    )

    target_compile_definitions(${TARGET_NAME}
        PRIVATE 
            XG_XVIEWER_BUILD_WITH_OSGVERSE
)
endif()

# if(NOT DEFINED osgVerse_LIBRARIES)
#     list(APPEND osgVerse_LIBRARIES osgVerseDependency$<$<CONFIG:Debug>:d>)
#     list(APPEND osgVerse_LIBRARIES osgVerseReaderWriter$<$<CONFIG:Debug>:d>)
#     list(APPEND osgVerse_LIBRARIES osgVerseScript$<$<CONFIG:Debug>:d>)
#     list(APPEND osgVerse_LIBRARIES osgVersePipeline$<$<CONFIG:Debug>:d>)
#     list(APPEND osgVerse_LIBRARIES osgVerseAnimation$<$<CONFIG:Debug>:d>)
#     list(APPEND osgVerse_LIBRARIES osgVerseModeling$<$<CONFIG:Debug>:d>)
#     list(APPEND osgVerse_LIBRARIES osgVerseUI$<$<CONFIG:Debug>:d>)
#     list(APPEND osgVerse_LIBRARIES osgVerseAI$<$<CONFIG:Debug>:d>)
# endif()

target_compile_definitions(${TARGET_NAME}
    PRIVATE 
        XG_MODULE_NAME="${TARGET_NAME}" 
        XG_RESOURCE_DIR="${XG_RES_ROOT}${TARGET_NAME}"
        XVIEWER_LIB
)

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER src)

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_SHADER_OUTPUT_DIR})
add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_IMAGE_OUTPUT_DIR})
if(RES_SHADER_FILES)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_SHADER_FILES} ${RES_SHADER_OUTPUT_DIR})
endif()
if(RES_IMAGE_FILES)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_IMAGE_FILES} ${RES_IMAGE_OUTPUT_DIR})
endif()