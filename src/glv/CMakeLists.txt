SET(CURRENT_TARGET_NAME glv)

find_package(OpenSceneGraph REQUIRED COMPONENTS osgDB osgText osgGA osgUtil osgViewer)
find_package(opencascade REQUIRED)
find_package(assimp REQUIRED)
find_package(PCL CONFIG REQUIRED)
find_package(VTK REQUIRED)
# find_package(osgVerse REQUIRED)

file(GLOB SRC_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

file(GLOB SRC_FIELS_IO io/*.cpp)
file(GLOB HEADER_FIELS_IO io/*.h)

file(GLOB SRC_FIELS_MODELING modeling/*.cpp)
file(GLOB HEADER_FIELS_MODELING modeling/*.h)

file(GLOB SRC_FIELS_APP app/*.cpp)
file(GLOB HEADER_FIELS_APP app/*.h)

set(RES_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res/)
set(RES_OUTPUT_DIR ${CONFIG_XG_RES_OUTPUT_DIR}/${CURRENT_TARGET_NAME}/)
set(RES_SHADER_OUTPUT_DIR ${RES_OUTPUT_DIR}shaders/)
set(RES_IMAGE_OUTPUT_DIR ${RES_OUTPUT_DIR}images/)
file(GLOB RES_SHADER_FILES ${RES_SRC_DIR}shaders/*.*)
file(GLOB RES_IMAGE_FILES ${RES_SRC_DIR}images/*.*)

add_executable(
    ${CURRENT_TARGET_NAME}
    ${SRC_FILES} 
    ${HEADER_FILES} 
    ${SRC_FIELS_IO} 
    ${HEADER_FIELS_IO} 
    ${SRC_FIELS_MODELING} 
    ${HEADER_FIELS_MODELING}
    ${SRC_FIELS_APP}
    ${HEADER_FIELS_APP}
    
    ${GLAD_SRC_FILES}
    ${BACKWARD_SRC_FILES}
)

target_sources(${CURRENT_TARGET_NAME} PRIVATE ${RES_SHADER_FILES} ${RES_IMAGE_FILES})

source_group(io FILES ${HEADER_FIELS_IO} ${SRC_FIELS_IO})
source_group(modeling FILES ${HEADER_FIELS_MODELING} ${SRC_FIELS_MODELING})
source_group(app FILES ${SRC_FIELS_APP} ${HEADER_FIELS_APP})
source_group(res/images FILES ${RES_IMAGE_FILES})
source_group(res/shaders FILES ${RES_SHADER_FILES})
source_group(third/glad FILES ${GLAD_SRC_FILES})
source_group(third/backward FILES ${BACKWARD_SRC_FILES})


target_include_directories(${CURRENT_TARGET_NAME}
    PRIVATE 
        ${BACKWARD_INCLUDE_DIR}
        ${GLAD_INCLUDE_DIR}
)

target_link_libraries(${CURRENT_TARGET_NAME} 
    PRIVATE 
        xgcomm
        assimp::assimp
        TKernel TKXSBase TKMesh TKBRep TKDESTEP TKDEIGES TKMath TKGeomBase TKGeomAlgo TKG3d
        VTK::CommonCore VTK::IOPLY VTK::FiltersCore VTK::IOGeometry

        ${OPENSCENEGRAPH_LIBRARIES} 
        #${osgVerse_LIBRARIES} 
        ${PCL_LIBRARIES}
        
        opengl32.lib
)

target_include_directories(${CURRENT_TARGET_NAME} 
    PRIVATE 
        #$<BUILD_INTERFACE:${osgVerse_INCLUDE_DIRS}>
        $<BUILD_INTERFACE:${OPENSCENEGRAPH_INCLUDE_DIRS}>
)

# target_link_directories(${CURRENT_TARGET_NAME} 
#     PRIVATE
#         $<BUILD_INTERFACE:${osgVerse_LIB_DIRS}>
# )

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

target_compile_definitions(${CURRENT_TARGET_NAME}
    PRIVATE 
        CURRENT_MODULE_NAME="${CURRENT_TARGET_NAME}" 
        CURRENT_RES_DIR="${XG_RES_ROOT}${CURRENT_TARGET_NAME}"
        GLV_LIB
)

add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_SHADER_OUTPUT_DIR})
add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_IMAGE_OUTPUT_DIR})
if(RES_SHADER_FILES)
    add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_SHADER_FILES} ${RES_SHADER_OUTPUT_DIR})
endif()
if(RES_IMAGE_FILES)
    add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_IMAGE_FILES} ${RES_IMAGE_OUTPUT_DIR})
endif()