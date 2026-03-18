set(XG_THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third/)
set(XG_THIRD_PARTY_LIBS
    glad
    glm
    stb
)
foreach(lib_name ${XG_THIRD_PARTY_LIBS})
    list(APPEND CMAKE_PREFIX_PATH "${XG_THIRD_PARTY_DIR}${lib_name}")
endforeach()

set(STB_DIR "${XG_THIRD_PARTY_DIR}stb")
set(STB_INCLUDE_DIR "${STB_DIR}/include")
set(GLAD_DIR "${XG_THIRD_PARTY_DIR}glad")
set(GLAD_INCLUDE_DIR "${GLAD_DIR}/include")
set(BACKWARD_DIR "${XG_THIRD_PARTY_DIR}backward")
set(BACKWARD_INCLUDE_DIR "${BACKWARD_DIR}")

find_package(glm REQUIRED)
find_package(glfw3 REQUIRED)

set(GLAD_HEADER_FILES ${GLAD_INCLUDE_DIR}/glad/glad.h)
set(GLAD_SRC_FILES ${GLAD_DIR}/src/glad.c)

if(WIN32)
    list(APPEND GLAD_HEADER_FILES ${GLAD_INCLUDE_DIR}/glad/wgl.h)
    list(APPEND GLAD_SRC_FILES ${GLAD_DIR}/src/glad_wgl.c)
endif()

file(GLOB GLAD_HEADER_FILES ${GLAD_DIR}/*.h)
file(GLOB_RECURSE GLAD_HEADER_AND_SRC_FILES ${GLAD_DIR}/*.*)
file(GLOB BACKWARD_SRC_FILES ${BACKWARD_INCLUDE_DIR}/*.hpp ${BACKWARD_INCLUDE_DIR}/*.cpp)

# add_definitions(-DSTB_IMAGE_IMPLEMENTATION)