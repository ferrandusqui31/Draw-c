cmake_minimum_required(VERSION 3.10)
project(Draw)

set(CMAKE_CXX_STANDARD 14)

add_executable(Draw
src/main.cpp
src/Draw.cpp
src/Color.cpp
src/HelpWindow.cpp)

target_link_libraries(Draw sfml-system sfml-graphics sfml-window sfml-audio sfml-network)