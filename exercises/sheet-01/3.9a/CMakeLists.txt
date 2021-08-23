cmake_minimum_required(VERSION 3.0.0)
project(exercise-3.9a VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(exercise main.cpp)
# target_link_libraries(exercise limwa)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
