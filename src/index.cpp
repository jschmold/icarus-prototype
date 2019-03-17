#include <iostream>
#include <sstream>
#include <ncurses.h>
#include <chrono>
#include <time.h>
#include "visuals/commandline.hpp"

using Icarus::Visuals::CommandLine;

using namespace std;

#define FRAME_LENGTH 1666666.7

bool run = true;
WINDOW* logWindow;
list<string>* history;

void shouldExit(string command) {
  if (command == "close" || command == "exit") run = false;
}


void showHistory(string command) {
  if (command != "history") return; 

  wclear(logWindow);
  mvwaddstr(logWindow, 0, 0, "");
  for (auto iter = history->rbegin(); iter != history->rend(); ++iter) {
    waddstr(logWindow, ((*iter) + '\n').c_str());
  }
}

int main(int argc, char* argv[]) {
  initscr();
  int width, height;
  getmaxyx(stdscr, height, width);

  CommandLine* cmd = new CommandLine(0, height - 2, width * 0.8, 2);
  history = cmd->history;
  cmd->addCommandListener(shouldExit);
  cmd->addCommandListener(showHistory);

  logWindow = newwin(height / 2, width * 0.2, 0, width * 0.8);

  while(run) {
    auto now = chrono::high_resolution_clock::now();

    wrefresh(logWindow);
    cmd->onThink();

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
