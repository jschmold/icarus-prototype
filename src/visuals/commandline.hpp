#pragma once

#include <curses.h>
#include "../thinkable.hpp"
#include <string>
#include <list>
#include <queue>
#include <sstream>

using std::string;
using std::list;
using std::queue;
using std::stringstream;

/**
 * Purpose: This is the command area where a player will enter
 * the commands to operate the station.
 */
namespace Icarus::Visuals {
  class CommandLine : public IThinkable {
  public:
    typedef void (*CommandListener)(string);

    static const int CURSOR_BEGINNING = -1;
    static const int CURSOR_END       = -2;

  private:
    string                 input;
    queue<string>          commands;
    list<CommandListener>* listeners;
    WINDOW*                host;
    int                    lines;
    int                    columns;
    int                    cursor;

    /**
     * ran when an enter character has been detected
     */
    void execute();

  public:
    list<string>*          history;
    int                    historySize;

    CommandLine(int x, int y, int width, int height);
    ~CommandLine();

    void onThink();
    void addCommandListener(CommandListener listener);
    void removeCommandListener(CommandListener listener);

    void keyEnter();
    void keyBackspace();
    void keyDelete();
    void keyLeft();
    void keyRight();
    void regularInput(int character);
  };
}
