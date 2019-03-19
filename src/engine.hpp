#pragma once 

#include "visuals/commandline.hpp"
#include "visuals/event-log.hpp"

using namespace Icarus::Visuals;


/**
 * This manages the framerate, houses the UI, and handles command execution
 */
namespace Icarus {
  static const int FullFrameSecond = 1000000000;

  class Engine {
    EventLog* logSystem;
    CommandLine* cmd;
    double refreshRate;
    bool exit = false;

    int height;
    int width;

    void sizeChildren();

  public:
    Engine(int framerate = 24);
    ~Engine();

    void execute(string message);

    void run();
    void detectResize();

  };
}
