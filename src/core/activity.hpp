#pragma once

#include <chrono>

using namespace std::chrono;

namespace Icarus {


  class Activity {
  protected:

      system_clock::time_point* start = nullptr;

      /** When the crafting process is to be ended */
      system_clock::time_point* end = nullptr;

      /** How long in ms does this last */
      int duration;

  public:

      /** Check whether or not the time is past the expected end */
      bool isFinished();

      /** get the percent completion */
      double getProgress();

      /** start the crafting processs */
      void execute();

      Activity(int duration);
      ~Activity();
  };
}
