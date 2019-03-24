# All tests for Icarus go here

add_executable(icarus_tests.run
  index.cpp
  testing.hpp
  testing.cpp
  core/generator.hpp
  core/generator.cpp
  core/crafting.hpp
  core/crafting.cpp
)

target_include_directories(icarus_tests.run PRIVATE ${../src})

target_link_libraries(icarus_tests.run 
  icarus_core
  icarus_entities
  icarus_activities
  icarus_visuals
)
