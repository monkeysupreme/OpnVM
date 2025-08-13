#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Opn::OpnVM" for configuration "Release"
set_property(TARGET Opn::OpnVM APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Opn::OpnVM PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/OpnVM.lib"
  )

list(APPEND _cmake_import_check_targets Opn::OpnVM )
list(APPEND _cmake_import_check_files_for_Opn::OpnVM "${_IMPORT_PREFIX}/lib/OpnVM.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
