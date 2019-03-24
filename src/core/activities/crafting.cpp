#include <iostream>
#include <chrono>
#include "crafting.hpp"
#include "../entities/entity.hpp"


using namespace Icarus::Activities;
using namespace std::chrono;
using std::runtime_error;

Crafting::Crafting(
  int     duration,
  int     quantity,
  Entity* resource
) : TimedActivity(duration) {
  this->quantity   = quantity;
  this->resource   = resource;
}

Ingredient Crafting::claim() {
  if (this->isFinished() == false) 
    throw runtime_error("Process is not finished yet");
  return Ingredient(this->quantity, this->resource);
}

