add_executable(example
    src/main.cpp
)
# Link against the library using the namespaced alias
target_link_libraries(example PRIVATE OpnVM::OpnVM)