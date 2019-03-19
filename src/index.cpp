#include <iostream>
#include <sstream>
#include <ncurses.h>
#include <chrono>
#include <time.h>

#include "engine.hpp"

using Icarus::Engine;
using namespace std;



int main(int argc, char* argv[]) {
  initscr();
  int width, height;
  getmaxyx(stdscr, height, width);
  curs_set(0);

  Engine* engine = new Engine();

  engine->run();

  echo();
  endwin();

  return 0;
}
