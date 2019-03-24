#include "citizen.hpp"

using namespace Icarus::Entities;

Citizen::Citizen(
  Entity*   energyType,
  int       energyAmount,
  int       energyMax
) : EntityPool(energyAmount, energyMax, energyType) {

}

int Citizen::drawEnergy(int amt) {
  return this->energy->draw(amt);
}

int Citizen::addEnergy(int amt) {
  return this->energy->add(amt);
}
