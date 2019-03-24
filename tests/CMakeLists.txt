# All tests for Icarus go here

add_executable(icarus_tests.run
  index.cpp
  testing.hpp
  testing.cpp
  core/resource-generator.hpp
  core/resource-generator.cpp
  core/craft-process.hpp
  core/craft-process.cpp
)

target_include_directories(icarus_tests.run PRIVATE ${../src})

target_link_libraries(icarus_tests.run 
  icarus_core
)
