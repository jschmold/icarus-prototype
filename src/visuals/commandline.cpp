#include "commandline.hpp"
#include <ncurses.h>
#include "window-utilities.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>

#define REGULAR_PAIR 1
#define CURSOR_PAIR 2

#define CURSOR COLOR_PAIR(CURSOR_PAIR)
#define REGULAR COLOR_PAIR(REGULAR_PAIR)

using std::istringstream;
using std::stringstream;
using std::endl;
using std::getline;
using std::ofstream;

using namespace Icarus::Visuals;

ofstream logs;

CommandLine::CommandLine(int x, int y, int width, int height) {
  start_color();
  init_pair(1, COLOR_GREEN, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_GREEN);

  this->host        = newwin(height, width, y, x);
  this->listeners   = new list<CommandListener>;
  this->input       = "";
  this->history     = new list<string>;
  this->historySize = 20;
  this->lines       = height;
  this->columns     = width;
  this->cursor      = 0;
  nodelay(this->host, true);
  keypad(this->host, true);
  raw();
  noecho();

  logs.open("logs.txt");
}

CommandLine::~CommandLine() {
  delwin(this->host);
  delete this->listeners;
}

/**
 * This is a separate thread that runs reading user input, 
 * firing all listeners when a command is executed
 */
void CommandLine::execute() {
  for(auto iter = this->listeners->begin(); iter != this->listeners->end(); ++iter) {
    (*iter)(this->input); // call the function
  }

  if (this->history->size() == this->historySize) {
    this->history->pop_back();
  }
  this->history->push_front(this->input);

  this->input = "";
}

void CommandLine::onThink() {
  wclear(this->host);
  wattron(this->host, REGULAR);
  wprintw(this->host, (" $> " + this->input).c_str());
  wattroff(this->host, REGULAR);
  this->drawCursor();

  int character = wgetch(this->host);
  if (character == ERR) return;

  switch(character) {
    case KEY_BACKSPACE:
      this->keyBackspace();    
      return;
    case KEY_LEFT:
      this->keyLeft();
      return;
    case KEY_RIGHT:
      this->keyRight();
      return;
    case '\n':
      this->keyEnter();
      return;
    case KEY_DC:
      this->keyDelete();
      return;
    default:
      this->regularInput(character);
      return;
  }

  wrefresh(this->host);
}

void CommandLine::addCommandListener(CommandListener listener) {
  this->listeners->push_front(listener);
}

void CommandLine::removeCommandListener(CommandListener listener) {
  this->listeners->remove_if([listener](auto val) {
    return val == listener;
  });
}

void CommandLine::keyEnter() {
  this->execute();
  this->cursor = 0;
}

void CommandLine::keyBackspace() {
  if (this->cursor == 0) return;

  if (this->cursor == 1) {
    this->input = this->input.substr(1);
    this->cursor--;
    return;
  }

  if (this->cursor == this->input.length()) {
    auto len = this->input.length() - 1;
    this->input = this->input.substr(0, len);
    this->cursor--;
    return;
  }

  string a = this->input.substr(0, this->cursor - 1);
  string b = this->input.substr(this->cursor);
  this->input = a + b;

  this->cursor--;
}

void CommandLine::keyDelete() {
  if (this->cursor == this->input.length()) {
    return;
  }

  if (this->cursor == 0) {
    this->input = this->input.substr(1);
    return;
  }

  string a = this->input.substr(0, this->cursor);
  string b = this->input.substr(this->cursor + 1);
  this->input = a + b;
}

void CommandLine::keyLeft() {
  if (this->cursor == 0) return;
  this->cursor--;
}

void CommandLine::keyRight() {
  if (this->cursor == this->input.length()) {
    return;
  }

  if (this->cursor > this->input.length()) {
    this->cursor = this->input.length();
    return;
  }

  this->cursor++;
}

void CommandLine::regularInput(int character) {
  if (this->cursor == this->input.length())  {
    this->input.push_back((char)character);
    this->cursor++;
    return;
  }

  if (this->cursor == this->input.length()) {
    this->input = (char)character + this->input;
    this->cursor++;
    return;
  }

  string a = this->input.substr(0, this->cursor);
  string b = this->input.substr(this->cursor);
  this->input = a + (char)character + b;
  this->cursor++;
}


void CommandLine::drawCursor() {
  char ch = this->input[this->cursor];
  if (!ch) ch = ' ';
  logs << (char)ch << endl;
  wattron(this->host, CURSOR);
  mvwaddch(this->host, 0, this->cursor + 4, ch);
  wattroff(this->host, CURSOR);
}
