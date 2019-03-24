#pragma once

#include <string>
#include "../entity.hpp"
#include <chrono>
#include "activity.hpp"

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

  using Ingredient = pair<int, Entity*>;
  using Recipe     = Ingredient*;

  class Crafting
  : public Activity {
    private:
      /** how much of the resource are we making */
      int quantity;

      /** What is being created */
      Entity* resource;
    public:
      Crafting(int duration, int quantity, Entity* entity);
      ~Crafting();

      Ingredient claim();
  };
}
