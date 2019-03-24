#pragma once

#include <string>
#include <utility>
#include "entity.hpp"
#include <chrono>

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
namespace Icarus {
  using Ingredient = pair<int, Entity*>;
  using Recipe     = Ingredient*;

  class CraftProcess {
    private:

      /** When the crafting process is to be ended */
      system_clock::time_point* end = nullptr;

      /** How long in ms does this last */
      int duration;

      /** how much of the resource are we making */
      int quantity;

      /** What is being created */
      Entity* resource;

    public:

      /** Check whether or not the time is past the expected end */
      bool isFinished();

      /** start the crafting processs */
      void execute();

      Ingredient claim();

      CraftProcess(int duration, int quantity, Entity* entity);
      ~CraftProcess();

  };
}
