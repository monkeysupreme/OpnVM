#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Opn::OpnVM" for configuration "RelWithDebInfo"
set_property(TARGET Opn::OpnVM APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(Opn::OpnVM PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/OpnVM.lib"
  )

list(APPEND _cmake_import_check_targets Opn::OpnVM )
list(APPEND _cmake_import_check_files_for_Opn::OpnVM "${_IMPORT_PREFIX}/lib/OpnVM.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
