#include "commandline.hpp"
#include <ncurses.h>
#include "window-utilities.hpp"

using namespace Icarus::Visuals;

CommandLine::CommandLine(int x, int y, int width, int height) {
  this->host = newwin(height, width, y, x);
  wtimeout(this->host, 0);

  this->listeners = new list<CommandListener>;

  this->command = readString(this->host);
}

CommandLine::~CommandLine() {
  delwin(this->host);
  delete this->listeners;
}

void CommandLine::onThink() {
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
