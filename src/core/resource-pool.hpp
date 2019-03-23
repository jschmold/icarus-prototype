#pragma once
#include "entity.hpp"

namespace Icarus {
  class ResourcePool {
  protected:
    /** How much is currently available */
    int amount;
  
    /** the maximum amount this can store */
    int max;

  public:
    int getAmount();
    int getMax();

    ResourcePool(int amt, int max);

    /**
     * Draw up to a certain amount of Resource from this. 
     * The amount returned is the actual quantity of units
     * that were consumed from this
     *
     * Example:
     *   max: 1000
     *   amt: 220
     *
     *   draw: 500
     *   return: 220
     *   leftover: 0
     *
     * @param int
     */
    int draw(int amt);
  };
}
