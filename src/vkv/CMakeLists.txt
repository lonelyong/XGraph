set(TARGET_NAME vkv)

find_package(vsg CONFIG REQUIRED)
find_package(opencascade CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(PCL CONFIG REQUIRED)

file(GLOB SRC_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

file(GLOB SRC_FIELS_IO io/*.cpp)
file(GLOB HEADER_FIELS_IO io/*.h)

file(GLOB SRC_FIELS_MODELING modeling/*.cpp)
file(GLOB HEADER_FIELS_MODELING modeling/*.h)

file(GLOB SRC_FIELS_APP app/*.cpp)
file(GLOB HEADER_FIELS_APP app/*.h)

set(RES_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res/)
set(RES_OUTPUT_DIR ${XG_RESOURCE_OUTPUT_DIR}/${TARGET_NAME}/)
set(RES_SHADER_OUTPUT_DIR ${RES_OUTPUT_DIR}shaders/)
set(RES_IMAGE_OUTPUT_DIR ${RES_OUTPUT_DIR}images/)
file(GLOB RES_SHADER_FILES ${RES_SRC_DIR}shaders/*.*)
file(GLOB RES_IMAGE_FILES ${RES_SRC_DIR}images/*.*)

add_executable(
    ${TARGET_NAME}
    ${SRC_FILES} 
    ${HEADER_FILES} 
    ${SRC_FIELS_IO} 
    ${HEADER_FIELS_IO} 
    ${SRC_FIELS_MODELING} 
    ${HEADER_FIELS_MODELING}
    ${SRC_FIELS_APP}
    ${HEADER_FIELS_APP}
    
    ${BACKWARD_SRC_FILES}
)

target_sources(${TARGET_NAME} PRIVATE ${RES_SHADER_FILES} ${RES_IMAGE_FILES})

source_group(io FILES ${HEADER_FIELS_IO} ${SRC_FIELS_IO})
source_group(modeling FILES ${HEADER_FIELS_MODELING} ${SRC_FIELS_MODELING})
source_group(app FILES ${SRC_FIELS_APP} ${HEADER_FIELS_APP})
source_group(res/images FILES ${RES_IMAGE_FILES})
source_group(res/shaders FILES ${RES_SHADER_FILES})
source_group(third/backward FILES ${BACKWARD_SRC_FILES})


target_include_directories(${TARGET_NAME}
    PRIVATE 
        ${BACKWARD_INCLUDE_DIR}
)

target_link_libraries(${TARGET_NAME} 
    PRIVATE 
        xgcomm 
        glfw 
        vsg::vsg
        assimp::assimp 
        TKernel TKXSBase TKMesh TKBRep TKDESTEP TKDEIGES TKMath TKGeomBase TKGeomAlgo TKG3d
        ${PCL_LIBRARIES}  
)

target_compile_definitions(${TARGET_NAME}
    PRIVATE 
        XG_MODULE_NAME="${TARGET_NAME}" 
        XG_RESOURCE_DIR="${XG_RESOURCE_ROOT}${TARGET_NAME}"
        VKVENDERER_LIB
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