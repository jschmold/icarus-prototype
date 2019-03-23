#include "resource-pool.hpp"

using namespace Icarus;

ResourcePool::ResourcePool(int amt, int max) {
  this->amount = amt;
  this->max    = max;
}

int ResourcePool::draw(int amt) {
  int ceiling = this->amount;
  if (amt > ceiling) {
    this->amount = 0;
    return ceiling;
  }

  this->amount -= amt;
  return amt;
}

int ResourcePool::getAmount() {
  return this->amount;
}

int ResourcePool::getMax() {
  return this->max;
}

