#pragma once
#include "entity.hpp"

namespace Icarus {
  template <typename T>
  class Pool {
  protected:
    /** How much is currently available */
    int amount;
  
    /** the maximum amount this can store */
    int max;

    T contentType;

  public:
    int getAmount() {
      return this->amount;
    }
    int getMax() {
      return this->max;
    }

    Pool(int amt, int max, T content) {
      this->amount = amt;
      this->max    = max;
      this->contentType = content;
    }

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
    int draw(int amt) {
      int ceiling = this->amount;
      if (amt > ceiling) {
        this->amount = 0;
        return ceiling;
      }

      this->amount -= amt;
      return amt;
    }
  };
}
