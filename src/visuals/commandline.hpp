#pragma once

#include <curses.h>
#include "../thinkable.hpp"
#include <string>
#include <list>

using std::string;
using std::list;

/**
 * Purpose: This is the command area where a player will enter
 * the commands to operate the station.
 */
namespace Icarus::Visuals {
  class CommandLine : public IThinkable {
  public:
    typedef void (*CommandListener)(string);

  private:
    string command;
    WINDOW* host;
    list<CommandListener>* listeners;

    /**
     * ran when an enter character has been detected
     */
    void execute();

  public:
    CommandLine(int x, int y, int width, int height);
    ~CommandLine();

    /**
     * Processes user input on every frame, running execute if the user presses enter
     */
    void onThink();
    void addCommandListener(CommandListener listener);
    void removeCommandListener(CommandListener listener);
  };
}
