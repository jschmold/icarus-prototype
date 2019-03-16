#include <curses.h>
#include <string>
#include "thinkable.hpp"

using std::string;

/**
 * Event log: The stream of events above the command area to the
 * right to let the player know that there are things actually
 * going on
 *
 * Looks like "02:10 - the string"
 */
namespace Icarus {
  class EventLog : IThinkable {
    /** A fixed-size based on window dimensions */
    string* events;
    
    WINDOW* host;

    EventLog();
    ~EventLog();

    /** This happens on every loop */
    void onThink();

    /** Write an event to the feed */
    void write(string text);

    /** This clears the events completely */
    void clear();
  };
}
