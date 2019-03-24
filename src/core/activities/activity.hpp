#pragma once

namespace Icarus::Activities {
  class Activity {
  public:
      /** Check whether or not the time is past the expected end */
      virtual bool isFinished() = 0;

      /** get the percent completion */
      virtual double getProgress() = 0;

      /** start the crafting processs */
      virtual void execute() = 0;
  };
}
