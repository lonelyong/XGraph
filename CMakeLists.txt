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

set(XG_SHARED_LIBRARY_PREFIX xg)
set(XG_RES_ROOT res/)
set(XG_RES_OUTPUT_DIR_BUILD ${CMAKE_BINARY_DIR}/${XG_RES_ROOT})

add_definitions(-DXG_RES_ROOT="${XG_RES_ROOT}")

if(WIN32)
    add_definitions(-DUNICODE -D_UNICODE)
endif()

# add_compile_options("/EHa")

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(XGraphThirdParty)

add_subdirectory(src)

# tests
if(XG_BUILD_TEST)
    enable_testing()
    add_subdirectory(tests)
endif()

include(CMakePackageConfigHelpers)

# configure VineConfig.cmake
configure_package_config_file(${CMAKE_SOURCE_DIR}/cmake/XGraphConfig.cmake.in
    "${CMAKE_BINARY_DIR}/XGraphConfig.cmake" # The output file
    INSTALL_DESTINATION lib/cmake/vine # The install location for the generated config file, relative to CMAKE_INSTALL_PREFIX
)
install(
    FILES
    "${CMAKE_BINARY_DIR}/XGraphConfig.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/XGraph
)
install(EXPORT XGraphTargets
    NAMESPACE ${XG_SHARED_LIBRARY_PREFIX}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/XGraph
)
