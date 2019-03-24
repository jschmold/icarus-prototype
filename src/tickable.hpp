#pragma once

#include <chrono>

using std::chrono::system_clock;

namespace Icarus {
  class Tickable {
    virtual void onTick(system_clock lastTick) = 0;
  };
}
