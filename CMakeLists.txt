cmake_minimum_required(VERSION 3.0.0)

project (ICARUS_PROTOTYPE)

find_package(Curses REQUIRED curses)

add_subdirectory(src/core)

add_executable(icarus.run
  src/index.cpp
)

target_link_libraries(icarus.run
  curses
  icarus_core
)

