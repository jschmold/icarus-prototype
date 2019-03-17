#pragma once

#include <string>
#include <utility>
#include "entity.hpp"

using std::string;
using std::pair;


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
  using Ingredient = pair<int, Entity>;
  using Recipe     = Ingredient*;
}
