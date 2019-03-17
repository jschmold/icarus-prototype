#include <string>
#include "entity.hpp"
#include "powersource.hpp"

using Icarus::PowerSource;
using std::string;

PowerSource::PowerSource(string name,
                         int id, 
                         int amt,
                         int max,
                         int rate,
                         double efficiency)
              : Entity(name, id, Entity::POWER_GROUP)
{
  this->amount = amt;
  this->max    = max;
  this->rate   = rate;
  this->efficiency = efficiency;
}

int PowerSource::drawPower(int amt) {
  int actualDraw = amt;
  if (amt > this->amount) actualDraw = this->amount;

  this->amount -= actualDraw;

  return (int)(actualDraw * this->efficiency);
}

void PowerSource::onThink() {
  this->amount += this->rate;
}

int PowerSource::getAmount() {
  return this->amount;
}

int PowerSource::getMax() {
  return this->max;
}

int PowerSource::getRate() {
  return this->rate;
}

double PowerSource::getEfficiency() {
  return this->efficiency;
}


