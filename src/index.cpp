#include <iostream>
#include <sstream>
#include <ncurses.h>
#include <chrono>
#include <time.h>

#include "visuals/commandline.hpp"
#include "visuals/event-log.hpp"

using Icarus::Visuals::CommandLine;
using Icarus::Visuals::EventLog;

using namespace std;

#define FRAME_LENGTH 41666666.666

bool run = true;
EventLog* logger;

void shouldExit(string command) {
  if (command == "close" || command == "exit") run = false;
}

void eventLogMessage(string command) {
  if (command == "help") logger->write("Help requested");
  
  if (command == "construct") logger->write("Build something");
}

int main(int argc, char* argv[]) {
  initscr();
  int width, height;
  getmaxyx(stdscr, height, width);

  curs_set(0);

  CommandLine* cmd = new CommandLine(0, height - 2, width * 0.75, 2);
  EventLog* log = new EventLog(width * 0.75, 0, width * 0.2, height);
  logger = log;

  cmd->addCommandListener(shouldExit);
  cmd->addCommandListener(eventLogMessage);

  while(run) {
    auto now = chrono::high_resolution_clock::now();

    cmd->onThink();
    log->onThink();

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = (end - now);
    struct timespec waitTime;
    waitTime.tv_nsec = FRAME_LENGTH - duration.count();
    waitTime.tv_sec  = 0;
    nanosleep(&waitTime, NULL);
  }

  delete cmd;

  echo();
  endwin();

  return 0;
}
