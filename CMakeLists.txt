cmake_minimum_required(VERSION 3.20)

project(mini_query_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compile our storage implementation into a library.
add_library(storage
    src/storage.cpp
)

# Allow files to include "storage.hpp".
target_include_directories(storage PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Build our main executable.
add_executable(mini_query_engine
    src/main.cpp
)

# Link the storage library into the executable.
target_link_libraries(mini_query_engine PRIVATE storage)

enable_testing()

add_executable(storage_tests
    tests/storage_test.cpp
)

target_link_libraries(storage_tests PRIVATE storage)

add_test(NAME StorageTests COMMAND storage_tests)
