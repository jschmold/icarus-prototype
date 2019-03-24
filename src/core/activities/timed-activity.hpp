#pragma once

#include <chrono>
#include "activity.hpp"

using namespace std::chrono;

namespace Icarus::Activities {
  class TimedActivity : public Activity {
  private:
    system_clock::time_point* start = nullptr;

    /** When the crafting process is to be ended */
    system_clock::time_point* end = nullptr;

    /** How long in ms does this last */
    int duration;

  public:
    TimedActivity(int duration);
    ~TimedActivity();

    bool isFinished();
    double getProgress();
    void execute();
  };


}
