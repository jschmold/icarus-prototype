#include "entity.hpp"
#include "crafting.hpp"
#include <iostream>

#include <chrono>

using namespace Icarus;
using namespace std::chrono;
using std::runtime_error;

CraftProcess::CraftProcess(
  int     duration,
  int     quantity,
  Entity* resource
) : TimedProcess(duration) {
  this->quantity   = quantity;
  this->resource   = resource;
}


CraftProcess::~CraftProcess() { }

Ingredient CraftProcess::claim() {
  if (this->isFinished() == false) 
    throw runtime_error("Process is not finished yet");
  return Ingredient(this->quantity, this->resource);
}

