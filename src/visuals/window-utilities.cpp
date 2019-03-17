#include "window-utilities.hpp"

using namespace Icarus;

string Visuals::readString(WINDOW* win) {
  nocbreak();
  echo();

  string input;
  int character = wgetch(win);
  while(character != '\n') {
    input.push_back(character);
    character = wgetch(win);
  }

  noecho();
  cbreak();
  return input;
}
