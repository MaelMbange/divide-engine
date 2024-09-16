cmake_minimum_required(VERSION 3.29)
project(divide-engine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(GLFW_PATH ${CMAKE_SOURCE_DIR}/lib/glfw)

find_package(OpenGL REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp" "${CMAKE_SOURCE_DIR}/src/*.c")

add_executable(divide-engine ${SOURCES})

target_include_directories(divide-engine PRIVATE ${GLFW_PATH}/include)
target_link_directories(divide-engine PRIVATE ${GLFW_PATH}/lib)
target_link_libraries(divide-engine glfw3)

if (WIN32)
    target_link_libraries(divide-engine opengl32)
endif()

# Pour les systèmes Linux, lier avec X11, OpenGL, etc.
if (UNIX)
    target_link_libraries(divide-engine X11 pthread Xrandr Xi dl GL)
    find_library(X11 pthread Xrandr Xi dl GL REQUIRED)
endif()
