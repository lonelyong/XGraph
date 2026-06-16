set(TARGET_NAME glr-app)

# find_package(sdl2 CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)
find_package(Qt6 CONFIG REQUIRED COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets)

qt_standard_project_setup()

set(RES_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/res/)
set(RES_OUTPUT_DIR ${XG_RES_OUTPUT_DIR_BUILD}/${TARGET_NAME}/)
set(RES_SHADER_OUTPUT_DIR ${RES_OUTPUT_DIR}shaders/)
set(RES_IMAGE_OUTPUT_DIR ${RES_OUTPUT_DIR}images/)

file(GLOB_RECURSE SRC_FILES *.c *.cc *.cpp *.cxx)
file(GLOB_RECURSE HEADER_FILES *.h *.hh *.hpp *.hxx)

file(GLOB_RECURSE RES_SHADER_FILES ${RES_SRC_DIR}shaders/*.*)
file(GLOB_RECURSE RES_IMAGE_FILES ${RES_SRC_DIR}images/*.*)

add_executable(
    ${TARGET_NAME}
    # source and header files
    ${HEADER_FILES} ${SRC_FILES}
    # resources
    ${RES_SHADER_FILES} ${RES_IMAGE_FILES}
    # third party
    ${GLAD_HEADER_AND_SRC_FILES}
    ${STB_HEADER_AND_SRC_FILES}
)

source_group(
    TREE ${CMAKE_CURRENT_LIST_DIR}
    PREFIX include
    FILES ${HEADER_FILES}
)
source_group(
    TREE ${CMAKE_CURRENT_LIST_DIR}
    PREFIX src
    FILES
    ${SRC_FILES}
)

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${RES_IMAGE_FILES} ${RES_SHADER_FILES})
source_group(TREE ${CMAKE_SOURCE_DIR} FILES ${GLAD_HEADER_AND_SRC_FILES} ${STB_HEADER_AND_SRC_FILES})

target_include_directories(${TARGET_NAME}
    PRIVATE
    ${GLAD_INCLUDE_DIR}
    ${STB_INCLUDE_DIR}
)

target_link_libraries(${TARGET_NAME}
    PRIVATE
    xg::glr-core
    xg::comm
    glfw
    SDL3::SDL3
    Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets
)

if(WIN32)
    target_link_libraries(${TARGET_NAME} PRIVATE opengl32)
endif()

target_compile_definitions(${TARGET_NAME}
    PRIVATE
    XG_MODULE_NAME="${TARGET_NAME}"
    XG_RESOURCE_DIR="${XG_RES_ROOT}${TARGET_NAME}"
)

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER src)

if(RES_SHADER_FILES)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_SHADER_OUTPUT_DIR})
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_SHADER_FILES} ${RES_SHADER_OUTPUT_DIR})
endif()
if(RES_IMAGE_FILES)
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory ${RES_IMAGE_OUTPUT_DIR})
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${RES_IMAGE_FILES} ${RES_IMAGE_OUTPUT_DIR})
endif()

install(
    TARGETS ${TARGET_NAME}
    EXPORT ${CMAKE_PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # for executables(including .dll on Windows)
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # for shared libraries(.so for Linux)
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}) # for static libraries(.a .lib)(including dll import library)

if(RES_SHADER_FILES OR RES_IMAGE_FILES)
    install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/res/ DESTINATION ${CMAKE_INSTALL_PREFIX}/${XG_RES_ROOT}${TARGET_NAME}/)
endif()


# get_target_property(WINDEPLOYQT_EXE Qt6::windeployqt IMPORTED_LOCATION)
# message(--------windeployqt=${WINDEPLOYQT_EXE})
# message(--------VCINSTALLDIR=${VCINSTALLDIR})
# if(WIN32)
#     add_custom_command (
#         TARGET ${TARGET_NAME}
#         POST_BUILD
#         COMMAND ${WINDEPLOYQT_EXE} --verbose 0 $<TARGET_FILE:AnyRenderer>
#         COMMENT "--------Run:windeployqt")
# endif()