#pragma once

#include <curses.h>
#include <string>
#include <list>
#include "../thinkable.hpp"

using std::string;
using std::list;

/**
 * Event log: The stream of events above the command area to the
 * right to let the player know that there are things actually
 * going on
 *
 * Looks like "02:10 - the string"
 */
namespace Icarus::Visuals {
  class EventLog : IThinkable {
  private:
    /** A fixed-size based on window dimensions */
    list<string>*   events;
    int             maxLogSize;
    WINDOW*         host;

  public:
    EventLog(int x, int y, int width, int height);
    ~EventLog();

    /** This happens on every loop */
    void onThink();

    /** Write an event to the feed */
    void write(string text);

    /** This clears the events completely */
    void clear();
    void resize(int x, int y, int width, int height);
  };
}
