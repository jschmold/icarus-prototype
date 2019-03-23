#include "resource-generator.hpp"

using namespace Icarus;

int ResourceGenerator::getRate() {
  return this->rate;
}

ResourceGenerator::ResourceGenerator(
  string  name,
  Entity* res,
  int     amt,
  int     max,
  int     rate
) : ResourcePool(amt, max) {
  this->name     = name;
  this->resource = res;
  this->rate     = rate;
}


void ResourceGenerator::onThink() {
  if (this->rate + this->amount == this->max) return;
  if (this->rate + this->amount <= 0) {
    this->amount = 0;
    return;
  }

  this->amount += this->rate;
}

