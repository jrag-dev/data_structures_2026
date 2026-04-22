cmake_minimum_required(VERSION 3.10)

project(DrawingFiguresWithRaylib)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(/usr/local/include)

link_directories(/usr/local/lib)

add_executable(draw_app draw.cc circle.cc rectangle.cc)

target_link_libraries(draw_app raylib GL m pthread dl rt X11)