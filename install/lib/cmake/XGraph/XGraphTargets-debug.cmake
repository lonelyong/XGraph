#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "xg::comm" for configuration "Debug"
set_property(TARGET xg::comm APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(xg::comm PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/comm.lib"
  )

list(APPEND _cmake_import_check_targets xg::comm )
list(APPEND _cmake_import_check_files_for_xg::comm "${_IMPORT_PREFIX}/lib/comm.lib" )

# Import target "xg::glr-core" for configuration "Debug"
set_property(TARGET xg::glr-core APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(xg::glr-core PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/glr-core.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "glfw;assimp::assimp;pcl_common;pcl_kdtree;pcl_octree;pcl_search;pcl_sample_consensus;pcl_filters;pcl_io_ply;pcl_io;pcl_features;pcl_ml;pcl_segmentation;pcl_surface;pcl_registration;pcl_keypoints;pcl_tracking;pcl_recognition;pcl_stereo;pcl_outofcore;Boost::iostreams;Boost::filesystem;Boost::serialization;flann::flann_cpp"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/glr-core.dll"
  )

list(APPEND _cmake_import_check_targets xg::glr-core )
list(APPEND _cmake_import_check_files_for_xg::glr-core "${_IMPORT_PREFIX}/lib/glr-core.lib" "${_IMPORT_PREFIX}/bin/glr-core.dll" )

# Import target "xg::glr-app" for configuration "Debug"
set_property(TARGET xg::glr-app APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(xg::glr-app PROPERTIES
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/glr-app.exe"
  )

list(APPEND _cmake_import_check_targets xg::glr-app )
list(APPEND _cmake_import_check_files_for_xg::glr-app "${_IMPORT_PREFIX}/bin/glr-app.exe" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
