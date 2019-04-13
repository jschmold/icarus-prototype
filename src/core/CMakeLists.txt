add_library(icarus_core STATIC
  event-listener.hpp
  activities.hpp
  pool.hpp
  generator.hpp
  transform.hpp
  ingredient.hpp
  ingredient.cpp
)


add_subdirectory(activities)
add_subdirectory(entities)
