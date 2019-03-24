#pragma once

#include <string>
#include "pool.hpp"

using std::string;

namespace Icarus {

  /**
   * Anything that generates a resource of any kind
   */
  template <typename T>
  class Generator
  : public Pool<T> {
  private:

    /** The rate at which the resource is being generated */
    int rate;

    /** The resource being generated */
    T resource;

    /** The name of this resource generator */
    string name; 

  public:
    
    int getRate() {
      return this->rate;
    }

    Generator(
      string  name,
      T       res,
      int     amt,
      int     max,
      int     rate
    ) : Pool<T>(amt, max, res) {
      this->name     = name;
      this->resource = res;
      this->rate     = rate;
    }


    void onThink() {
      if (this->rate + this->amount == this->max) return;
      if (this->rate + this->amount <= 0) {
        this->amount = 0;
        return;
      }
      this->amount += this->rate;
    }
  };
}
