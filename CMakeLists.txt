cmake_minimum_required(VERSION 3.0.0)

set(GLFL_Proj GLFW)
set(Proj_name Proba)

project(${Proj_name} LANGUAGES CXX)

add_executable(main src/main.cpp src/F.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(External/Glfw)
target_link_libraries(main glfw)

add_subdirectory(External/glad)
target_link_libraries(main glad1)

add_subdirectory(External/my)
target_link_libraries(main F)