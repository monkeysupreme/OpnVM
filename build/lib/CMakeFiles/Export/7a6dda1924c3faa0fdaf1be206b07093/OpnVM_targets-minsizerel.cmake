#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Opn::OpnVM" for configuration "MinSizeRel"
set_property(TARGET Opn::OpnVM APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(Opn::OpnVM PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/OpnVM.lib"
  )

list(APPEND _cmake_import_check_targets Opn::OpnVM )
list(APPEND _cmake_import_check_files_for_Opn::OpnVM "${_IMPORT_PREFIX}/lib/OpnVM.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
