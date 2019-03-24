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
) {
  this->quantity   = quantity;
  this->resource   = resource;
  this->duration   = duration;
}

bool CraftProcess::isFinished() {
  return this->end != nullptr
    && system_clock::now() > *this->end;
}

CraftProcess::~CraftProcess() {
  if (this->end != nullptr) delete this->end;
}

void CraftProcess::execute() {
  this->end  = new time_point<system_clock>(
    system_clock::now() + std::chrono::milliseconds((int)this->duration)
  );
}

Ingredient CraftProcess::claim() {
  if (this->isFinished() == false) 
    throw runtime_error("Process is not finished yet");
  return Ingredient(this->quantity, this->resource);
}

