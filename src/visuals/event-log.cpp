#include <iostream>
#include <curses.h>
#include <string>
#include <list>
#include <ctime>
#include <chrono>
#include "event-log.hpp"

using std::string;
using std::strftime;
using std::chrono::system_clock;
using std::localtime;
using std::logic_error;

using namespace Icarus::Visuals;

EventLog::EventLog(int x, int y, int width, int height) {
  this->maxLogSize = height - 2;
  this->host = newwin(height, width, y, x);
  this->events = new list<string>;
}

EventLog::~EventLog() {
  delwin(this->host);
}

void EventLog::onThink() {
  wclear(this->host);
  string log = "Events: \n";
  for (auto iter = this->events->begin(); iter != this->events->end(); ++iter) {
    log += *iter + '\n';
  }
  wprintw(this->host, log.c_str());
  wrefresh(this->host);
}

void EventLog::write(string event) {
  time_t clock = system_clock::to_time_t(system_clock::now());
  tm* now = localtime(&clock);
  char* time = new char[6];

  size_t copied = strftime(time, 6, "%H:%M", now);
  if (copied == 0) throw logic_error("Was unable to provide a format");

  this->events->push_front(string(time) + " - " + event);

  delete[] time;
}

void EventLog::clear() {
  delete this->events;
  this->events = new list<string>;
}
