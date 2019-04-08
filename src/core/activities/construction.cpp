#include "construction.hpp"
#include "../entities/entity.hpp"

using namespace Icarus::Activities;
using namespace Icarus::Entities;

ConstructionActivity::ConstructionActivity()
: Activity() {
  this->materials = new Inventory;
}
