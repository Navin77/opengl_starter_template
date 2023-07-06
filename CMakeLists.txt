cmake_minimum_required(VERSION 3.26)
project(BITe)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/external/rajProg")
link_directories("${PROJECT_SOURCE_DIR}/external/rajProg")
add_subdirectory(src)

