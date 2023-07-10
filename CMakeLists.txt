cmake_minimum_required(VERSION 3.20)
project(test)

set(CXX_STANDARD_REQUIRED 17)
# set(CMAKE_EXPORT_COMPILE_COMMANDS True)

add_executable(test main.cc)
add_library(a lib/a/a.c)

target_link_libraries(test a)

target_include_directories(a PUBLIC lib/a)
target_include_directories(test PRIVATE lib/b)
target_include_directories(test PRIVATE lib/a)
