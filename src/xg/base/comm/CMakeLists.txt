set(TARGET_NAME comm)

file(GLOB_RECURSE SDK_FILES sdk/*.hpp)
file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_library(${TARGET_NAME} STATIC ${SDK_FILES} ${SRC_FILES})
add_library(${XG_SHARED_LIBRARY_PREFIX}::${TARGET_NAME} ALIAS ${TARGET_NAME})

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER src)
target_include_directories(${TARGET_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/sdk>
        $<INSTALL_INTERFACE:include>
)

# target_sources(${TARGET_NAME} FILE_SET SDK_FILES BASE_DIRS ${CMAKE_CURRENT_LIST_DIR})

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SDK_FILES})
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SRC_FILES})

install(
    TARGETS ${TARGET_NAME}
    EXPORT ${CMAKE_PROJECT_NAME}Targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR} # for executables(including .dll on Windows)
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} # for shared libraries(.so for Linux)
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}) # for static libraries(.a .lib)(including dll import library)

install(DIRECTORY sdk/ DESTINATION ${CMAKE_INSTALL_PREFIX}/include/)