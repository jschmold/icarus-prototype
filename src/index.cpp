#include <iostream>
#include <ncurses.h>

using namespace std;

string readString(WINDOW*);

int main(int argc, char* argv[]) {
  initscr();
  noecho();

  WINDOW* topWindow;
  WINDOW* bottomWindow;

  int width, height;
  getmaxyx(stdscr, height, width);

  height = height / 2;

  topWindow = newwin(height, width, 0, 0);
  bottomWindow = newwin(height, width, (int)height, 0);


  mvwaddstr(topWindow, 1, 0, "This is the top Window");
  mvwaddstr(bottomWindow, 0, 0, "This is the bottom Window");

  bool exit = false;
  while(!exit) {
    wrefresh(topWindow);
    wrefresh(bottomWindow);
    string command = readString(bottomWindow);
  }

  echo();
  endwin();
  return 0;
}

string readString(WINDOW* win) {
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
