#include "commandline.hpp"
#include <ncurses.h>
#include "window-utilities.hpp"
#include <string>
#include <sstream>
#include <fstream>
#include <time.h>

using std::istringstream;
using std::stringstream;
using std::endl;
using std::getline;
using std::ofstream;

using namespace Icarus::Visuals;

ofstream logs;

CommandLine::CommandLine(int x, int y, int width, int height) {
  this->host        = newwin(height, width, y, x);
  this->listeners   = new list<CommandListener>;
  this->input       = "";
  this->history     = new list<string>;
  this->historySize = 20;
  this->lines       = height;
  this->columns     = width;
  this->cursor      = 0;

  nodelay(this->host, true);
  raw();
  keypad(this->host, true);
  noecho();


  mvwaddstr(this->host, 0, 0, " $> ");

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

  wclear(this->host);
  mvwaddstr(this->host, 0, 0, " $> ");
}

void CommandLine::onThink() {
  wrefresh(this->host);
  wclear(this->host);
  wprintw(this->host, (" $> " + this->input).c_str());
  wmove(this->host, 0, this->cursor + 4);

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
  if (this->cursor > 0) {
    auto len = this->input.length() - 1;
    this->input = this->input.substr(0, len);
    this->cursor--;
    return;
  }
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

