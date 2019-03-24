#include "../entity.hpp"
#include "crafting.hpp"
#include <iostream>

#include <chrono>

using namespace Icarus::Activities;
using namespace std::chrono;
using std::runtime_error;

Crafting::Crafting(
  int     duration,
  int     quantity,
  Entity* resource
) : Activity(duration) {
  this->quantity   = quantity;
  this->resource   = resource;
}


Crafting::~Crafting() { }

Ingredient Crafting::claim() {
  if (this->isFinished() == false) 
    throw runtime_error("Process is not finished yet");
  return Ingredient(this->quantity, this->resource);
}

