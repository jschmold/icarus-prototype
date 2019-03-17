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

CommandLine::CommandLine(int x, int y, int width, int height) {
  noecho();
  nocbreak();
  raw();

  this->host        = newwin(height, width, y, x);
  this->listeners   = new list<CommandListener>;
  this->input       = "";
  this->history     = new list<string>;
  this->historySize = 20;
  this->lines       = height;
  this->columns     = width;

  nodelay(this->host, true);

  mvwaddstr(this->host, 0, 0, " $> ");
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
  mvwaddstr(this->host, 0, 0, (" $> " + this->input).c_str());

  int character = wgetch(this->host);
  if (character == ERR) return;

  // BACKSPACE
  if (character == 127) {
    auto len = this->input.length() - 1;
    this->input = this->input.substr(0, len);
    return;
  }

  if (character == '\n') {
    this->execute();
  } else {
    this->input.push_back((char)character);
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
