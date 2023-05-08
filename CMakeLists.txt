cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

project(sandbox VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SRC src/**/*.cpp src/*.cpp src/*.c)

add_executable(sandbox ${SRC}) 

include_directories(include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(include/glfw)

add_subdirectory(include/glm)

target_link_libraries(sandbox glfw)
target_link_libraries(sandbox glm)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
