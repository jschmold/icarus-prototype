cmake_minimum_required(VERSION 3.0.0)

project (ICARUS_PROTOTYPE)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

find_package(Curses REQUIRED curses)

add_subdirectory(src/core)
add_subdirectory(src/visuals)

add_subdirectory(tests)

add_executable(icarus.run src/index.cpp)

target_link_libraries(icarus.run
  curses
  pthread
  icarus_core
  icarus_visuals
)

