#include <string>
#include "transform.hpp"

using std::string;
/**
 * The base class of all bays that exist inside the station
 */
namespace Icarus {
  class Bay {
    Transform transform;
  };
}
