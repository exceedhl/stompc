cmake_minimum_required (VERSION 2.6)
project (stompc)
message(STATUS "Binary dir is ${PROJECT_BINARY_DIR}")
message(STATUS "Source dir is ${PROJECT_SOURCE_DIR}")

add_subdirectory(src)
add_subdirectory(ut EXCLUDE_FROM_ALL)

add_test(ut unittest)
enable_testing()