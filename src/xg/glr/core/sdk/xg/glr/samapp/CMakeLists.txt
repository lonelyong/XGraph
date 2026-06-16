set(XG_GLRSAMAPP_TARGET_NAME glr-samapp)

# find_package(sdl2 CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets)

qt_standard_project_setup()

set(RES_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res/)
set(RES_OUTPUT_DIR ${XG_RES_OUTPUT_DIR_BUILD}/${XG_GLRSAMAPP_TARGET_NAME}/)
set(RES_SHADER_OUTPUT_DIR ${RES_OUTPUT_DIR}shaders/)
set(RES_IMAGE_OUTPUT_DIR ${RES_OUTPUT_DIR}images/)

file(GLOB SRC_FILES *.cpp)
file(GLOB HEADER_FILES *.h)

file(GLOB SRC_FIELS_APP app/*.cpp)
file(GLOB HEADER_FIELS_APP app/*.h)

file(GLOB RES_SHADER_FILES ${RES_SRC_DIR}shaders/*.*)
file(GLOB RES_IMAGE_FILES ${RES_SRC_DIR}images/*.*)

add_executable(
    ${XG_GLRSAMAPP_TARGET_NAME} 
    ${SRC_FILES} 
    ${HEADER_FILES}
    ${GLAD_SRC_FILES}
    ${SRC_FIELS_APP}
    ${HEADER_FIELS_APP}
)

target_sources(${XG_GLRSAMAPP_TARGET_NAME} PRIVATE ${RES_SHADER_FILES} ${RES_IMAGE_FILES})

source_group(app FILES ${HEADER_FIELS_APP} ${SRC_FIELS_APP})
source_group(res/images FILES ${RES_IMAGE_FILES})
source_group(res/shaders FILES ${RES_SHADER_FILES})
source_group(third/glad FILES ${GLAD_SRC_FILES})

target_include_directories(${XG_GLRSAMAPP_TARGET_NAME}
    PRIVATE
        ${GLAD_INCLUDE_DIR}
        ${STB_INCLUDE_DIR}
)

target_link_libraries(${XG_GLRSAMAPP_TARGET_NAME}
    PRIVATE
        glr
        xgcomm 
        glfw
        SDL3::SDL3
        Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets
)

target_compile_definitions(${XG_GLRSAMAPP_TARGET_NAME} 
    PRIVATE 
        XG_MODULE_NAME="${XG_GLRSAMAPP_TARGET_NAME}"
        XG_RESOURCE_DIR="${XG_RES_ROOT}${XG_GLRSAMAPP_TARGET_NAME}"
)
set_target_properties(${XG_GLRSAMAPP_TARGET_NAME} PROPERTIES FOLDER src/glr)

add_custom_command(TARGET ${XG_GLRSAMAPP_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_SHADER_OUTPUT_DIR})
add_custom_command(TARGET ${XG_GLRSAMAPP_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_IMAGE_OUTPUT_DIR})
if(RES_SHADER_FILES)
    add_custom_command(TARGET ${XG_GLRSAMAPP_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_SHADER_FILES} ${RES_SHADER_OUTPUT_DIR})
endif()
if(RES_IMAGE_FILES)
    add_custom_command(TARGET ${XG_GLRSAMAPP_TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_IMAGE_FILES} ${RES_IMAGE_OUTPUT_DIR})
endif()

# get_target_property(WINDEPLOYQT_EXE Qt6::windeployqt IMPORTED_LOCATION)
# message(--------windeployqt=${WINDEPLOYQT_EXE})
# message(--------VCINSTALLDIR=${VCINSTALLDIR})
# if(WIN32)
#     add_custom_command (
#         TARGET ${XG_GLRSAMAPP_TARGET_NAME}
#         POST_BUILD
#         COMMAND ${WINDEPLOYQT_EXE} --verbose 0 $<TARGET_FILE:AnyRenderer>
#         COMMENT "--------Run:windeployqt")
# endif()