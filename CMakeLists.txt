cmake_minimum_required(VERSION 3.26)

project(XGraph
    VERSION 1.0.0
)

option(XG_BUILD_TEST "" OFF)

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")
# set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /DEBUG")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(XG_RESOURCE_OUTPUT_DIR ${CMAKE_BINARY_DIR}/res/)
set(XG_RESOURCE_ROOT res/)

add_definitions(-DXG_RESOURCE_ROOT="${XG_RESOURCE_ROOT}")

if(WIN32)
    add_definitions(-DUNICODE -D_UNICODE)
endif()

# add_compile_options("/EHa")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(XGraphThirdParty)

add_subdirectory(src)

if(XG_BUILD_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()

#configure_file(".clang-format" ${CMAKE_BINARY_DIR} COPYONLY)