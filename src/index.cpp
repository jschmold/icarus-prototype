#include <iostream>
#include <ncurses.h>
#include "visuals/commandline.hpp"

using Icarus::Visuals::CommandLine;

using namespace std;

string commands = "";

void commandListener(string command) {
  commands = commands + '\n' + command;
}

int main(int argc, char* argv[]) {
  initscr();
  noecho();

  int width, height;
  getmaxyx(stdscr, height, width);

  CommandLine* cmd = new CommandLine(0, 0, width, height);
  cmd->addCommandListener(commandListener);
  
  bool run = true;
  while (run) {
    cmd->onThink();
  }

  delete cmd;

  echo();
  endwin();
  return 0;
}
