# lib/CMakeLists.txt
add_library(OpnVM
    src/OpnVM.cpp
    src/Controls.cpp
    src/Machine.cpp
)
# Include dir for this target (works for both build and install)
target_include_directories(OpnVM PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
# Require a C++ standard
target_compile_features(OpnVM PUBLIC cxx_std_17)
# Versioning (optional but recommended)
set_target_properties(OpnVM PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)
# Create a namespaced alias so consumers can use mylib::mylib
add_library(OpnVM::OpnVM ALIAS OpnVM)

include(GNUInstallDirs)
install(TARGETS OpnVM
    EXPORT OpnVM_targets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT OpnVM_targets
    FILE OpnVM_targets.cmake
    NAMESPACE Opn::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/OpnVM
)
