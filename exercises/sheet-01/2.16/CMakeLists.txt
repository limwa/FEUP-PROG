cmake_minimum_required(VERSION 3.0.0)
project(exercise-2.16 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(exercise main.cpp ansi.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
