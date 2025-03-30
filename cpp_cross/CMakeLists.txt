cmake_minimum_required(VERSION 3.31)

project(Demo VERSION 1.0)

add_executable(Demo src/main.cpp)

add_subdirectory(libs/DemoLib)
add_subdirectory(external/glfw)

target_include_directories(Demo PUBLIC libs/DemoLib external/glfw/include)
target_link_libraries(Demo PUBLIC DemoLib glfw)