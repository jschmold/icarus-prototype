add_library(icarus_core STATIC
  event-listener.hpp
  pool.hpp
  structure.hpp
  structure.cpp
  entity.hpp
  entity.cpp
  resource-generator.hpp
  resource-generator.cpp
  transform.hpp
)

add_subdirectory(activities)
