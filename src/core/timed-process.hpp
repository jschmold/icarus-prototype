#pragma once

#include <chrono>

using namespace std::chrono;

namespace Icarus {
  class TimedProcess {
  protected:

      /** When the crafting process is to be ended */
      system_clock::time_point* end = nullptr;

      /** How long in ms does this last */
      int duration;

  public:
      
      /** Check whether or not the time is past the expected end */
      bool isFinished();

      /** start the crafting processs */
      void execute();

      TimedProcess(int duration);
      ~TimedProcess();

  };
}
