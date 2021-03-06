cmake_minimum_required(VERSION 3.0.0)

project (ICARUS_PROTOTYPE
  VERSION 0.0.1
  LANGUAGES CXX
)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS ON)

add_subdirectory(src/core)
add_subdirectory(src/structures)
add_subdirectory(src/visuals)
add_subdirectory(tests)

add_executable(icarus.run
  src/index.cpp
  src/engine.hpp
  src/engine.cpp
  src/thinkable.hpp
  src/tickable.hpp
)

target_link_libraries(icarus.run
  ncurses
  pthread
  icarus_core
  icarus_activities
  icarus_visuals
)

