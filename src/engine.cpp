#include <chrono>
#include <curses.h>

#include "engine.hpp"
#include "./visuals/commandline.hpp"
#include "./visuals/event-log.hpp"

using namespace Icarus;
using namespace std::chrono;

Engine::Engine(int framerate) {
  this->refreshRate = Icarus::FullFrameSecond / framerate;

  // height and width refer implicity to "this"
  getmaxyx(stdscr, height, width);
  this->cmd = new CommandLine(0, height - 2, width * 0.8, 2);
  this->logSystem = new EventLog(width * 0.8, 0, width * 0.2, height);
}

Engine::~Engine() {
  delete this->logSystem;
  delete this->cmd;
}

void Engine::run() {
  if (exit) return;
  this->detectResize();
  auto now = high_resolution_clock::now();

  this->cmd->onThink();
  this->logSystem->onThink();


  auto commands = this->cmd->commands;

  if (commands->size() > 0) {
    for(auto iter = commands->rbegin(); iter != commands->rend(); ++iter) {
      this->execute(*iter);
    }

    this->cmd->resetCommands();
  }

  auto end = high_resolution_clock::now();
  duration<double> duration = (end - now);
  struct timespec waitTime;
  waitTime.tv_nsec = this->refreshRate - duration.count();
  waitTime.tv_sec  = 0;
  nanosleep(&waitTime, NULL);

  this->run();
}

void Engine::execute(string message) {
  if (message == "help") {
    this->logSystem->write("Help requested");
  }
  if (message == "construct") {
    this->logSystem->write("Construction requested");
  }

  if (message == "quit" || message == "exit") {
    this->exit = true;
  }
}

void Engine::detectResize() {
  int nh, nw;
  getmaxyx(stdscr, nh, nw);
  if (nh != this->height || nw != this->width) {
    this->width = nw;
    this->height = nh;
    this->sizeChildren();
  }
}

void Engine::sizeChildren() {
  this->cmd->resize(0, height - 2, width * 0.8, 2);
  this->logSystem->resize(width * 0.8, 0, width * 0.2, height);
}
