
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${LIBRARY_OUTPUT_PATH})


add_subdirectory(xgcomm)
add_subdirectory(glr)
add_subdirectory(glr-app)
add_subdirectory(glv)
add_subdirectory(vkr)
add_subdirectory(vkv)
add_subdirectory(plugins)