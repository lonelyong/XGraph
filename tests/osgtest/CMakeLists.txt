set(TARGET_NAME osgtest)
find_package(OpenSceneGraph CONFIG COMPONENTS osgDB REQUIRED)
XG_ADD_TEST(${TARGET_NAME})

target_include_directories(${TARGET_NAME} 
    PRIVATE
        $<BUILD_INTERFACE:${OPENSCENEGRAPH_INCLUDE_DIRS}>)
        
target_link_libraries(${TARGET_NAME} PRIVATE ${OPENSCENEGRAPH_LIBRARIES})