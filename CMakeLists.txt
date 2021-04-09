cmake_minimum_required(VERSION 3.12.0)
project(mdcore_testbot VERSION 0.1.0)

include(CTest)
enable_testing()

set(JSON_BuildTests OFF CACHE INTERNAL "")

file(GLOB_RECURSE mdcore_SRC CONFIGURE_DEPENDS "mdcore/*.h" "mdcore/*.cpp")

add_executable(mdcore_testbot main.cpp testcases.cpp)
add_library(mdcore lib/json.hpp lib/catch.hpp ${mdcore_SRC})
add_subdirectory(lib/sleepy-discord)
target_link_libraries(mdcore sleepy-discord)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
