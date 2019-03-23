#pragma once

#include <string>
#include "transform.hpp"
#include "crafting.hpp"

using std::string;
/**
 * The base class of all bays that exist inside the station
 */
namespace Icarus {
  class Structure {
    /** Where is this located?  */
    Transform transform;

    /** What does it take to build this? */
    Recipe bayRecipe;
  };
}
