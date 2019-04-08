#pragma once

#include <string>
#include "../entities/entity.hpp"
#include <chrono>
#include "timed-activity.hpp"

using namespace Icarus::Entities;
using std::string;
using std::pair;
using std::chrono::system_clock;


/**
 * Identifiers
 *
 * Hex Groupings
 *
 * Resource  0001 XXXX
 * Knowledge 0010 XXXX
 * Labour    0100 FFFF
 * Power     1000 FFFF
 */
namespace Icarus::Activities {

  class Crafting
  : public TimedActivity {
    private:
      /** how much of the resource are we making */
      int quantity;

      /** What is being created */
      Entity* resource;
    public:

      Crafting(int duration, int quantity, Entity* entity);

      Ingredient claim();
  };
}
