SET(CURRENT_TARGET_NAME glr-core)

find_package(PCL CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(Vine REQUIRED)

set(RES_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res/)
set(RES_OUTPUT_DIR ${CONFIG_XG_RES_OUTPUT_DIR}/${CURRENT_TARGET_NAME}/)
set(RES_SHADER_OUTPUT_DIR ${RES_OUTPUT_DIR}shaders/)
set(RES_IMAGE_OUTPUT_DIR ${RES_OUTPUT_DIR}images/)

file(GLOB SRC_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

file(GLOB SRC_FIELS_IGL igl/*.cpp)
file(GLOB HEADER_FIELS_IGL igl/*.h)

file(GLOB SRC_FIELS_ENGINE engine/*.cpp engine/*.tmpl)
file(GLOB HEADER_FIELS_ENGINE engine/*.h)

file(GLOB SRC_FIELS_IO io/*.cpp)
file(GLOB HEADER_FIELS_IO io/*.h)

file(GLOB SRC_FIELS_SCENE scene/*.cpp)
file(GLOB HEADER_FIELS_SCENE scene/*.h)

file(GLOB SRC_FIELS_UTILS utils/*.cpp)
file(GLOB HEADER_FIELS_UTILS utils/*.h)

file(GLOB SRC_FIELS_APP app/*.cpp)
file(GLOB HEADER_FIELS_APP app/*.h)

file(GLOB RES_SHADER_FILES ${RES_SRC_DIR}shaders/*.*)
file(GLOB RES_IMAGE_FILES ${RES_SRC_DIR}images/*.*)

add_library(
    ${CURRENT_TARGET_NAME}
    SHARED
    ${SRC_FILES} 
    ${HEADER_FILES}
    ${GLAD_HEADER_AND_SRC_FILES}
    ${SRC_FIELS_ENGINE}
    ${HEADER_FIELS_ENGINE}
    ${SRC_FIELS_IO}
    ${HEADER_FIELS_IO}
    ${SRC_FIELS_SCENE}
    ${HEADER_FIELS_SCENE}
    ${SRC_FIELS_UTILS}
    ${HEADER_FIELS_UTILS}
    ${SRC_FIELS_APP}
    ${HEADER_FIELS_APP}
    ${SRC_FIELS_IGL}
    ${HEADER_FIELS_IGL}
)

target_sources(${CURRENT_TARGET_NAME} PRIVATE ${RES_SHADER_FILES} ${RES_IMAGE_FILES})

source_group(igl FILES ${HEADER_FIELS_IGL} ${SRC_FIELS_IGL})
source_group(engine FILES ${HEADER_FIELS_ENGINE} ${SRC_FIELS_ENGINE})
source_group(io FILES ${HEADER_FIELS_IO} ${SRC_FIELS_IO})
source_group(scene FILES ${HEADER_FIELS_SCENE} ${SRC_FIELS_SCENE})
source_group(utils FILES ${HEADER_FIELS_UTILS} ${SRC_FIELS_UTILS})
source_group(app FILES ${HEADER_FIELS_APP} ${SRC_FIELS_APP})
source_group(res/images FILES ${RES_IMAGE_FILES})
source_group(res/shaders FILES ${RES_SHADER_FILES})
source_group(third/glad FILES ${GLAD_HEADER_AND_SRC_FILES})

target_include_directories(${CURRENT_TARGET_NAME}
    PRIVATE
        ${GLAD_INCLUDE_DIR}
        ${STB_INCLUDE_DIR}
)

target_link_libraries(${CURRENT_TARGET_NAME}
    PUBLIC
        glm::glm
        vi::Core vi::Ge
    PRIVATE
        xgcomm 
        glfw
        assimp::assimp
        ${PCL_LIBRARIES}
        opengl32.lib
)

target_compile_definitions(${CURRENT_TARGET_NAME} 
    PRIVATE 
        CURRENT_MODULE_NAME="${CURRENT_TARGET_NAME}" 
        CURRENT_RES_DIR="${XG_RES_ROOT}${CURRENT_TARGET_NAME}"
        GLR_LIB
)

set_target_properties(${CURRENT_TARGET_NAME} PROPERTIES FOLDER src)

add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_SHADER_OUTPUT_DIR})
add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_IMAGE_OUTPUT_DIR})
if(RES_SHADER_FILES)
    add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_SHADER_FILES} ${RES_SHADER_OUTPUT_DIR})
endif()
if(RES_IMAGE_FILES)
    add_custom_command(TARGET ${CURRENT_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_IMAGE_FILES} ${RES_IMAGE_OUTPUT_DIR})
endif()

# get_target_property(WINDEPLOYQT_EXE Qt6::windeployqt IMPORTED_LOCATION)
# message(--------windeployqt=${WINDEPLOYQT_EXE})
# message(--------VCINSTALLDIR=${VCINSTALLDIR})
# if(WIN32)
#     add_custom_command (
#         TARGET ${CURRENT_TARGET_NAME}
#         POST_BUILD
#         COMMAND ${WINDEPLOYQT_EXE} --verbose 0 $<TARGET_FILE:AnyRenderer>
#         COMMENT "--------Run:windeployqt")
# endif()