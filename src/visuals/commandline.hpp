#pragma once

#include <curses.h>
#include "../thinkable.hpp"
#include <string>
#include <list>
#include <sstream>

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

    static const int CURSOR_BEGINNING = -1;
    static const int CURSOR_END       = -2;

  private:
    string                 input;
    WINDOW*                host;
    int                    lines;
    int                    columns;
    int                    cursor;

    /**
     * ran when an enter character has been detected
     */
    void execute();

  public:
    list<string>*          commands;
    list<string>*          history;
    int                    historySize;

    CommandLine(int x, int y, int width, int height);
    ~CommandLine();

    void onThink();
    void keyEnter();
    void keyBackspace();
    void keyDelete();
    void keyLeft();
    void keyRight();
    void regularInput(int character);
    void drawCursor();
    void resetCommands();

    void resize(int x, int y, int width, int height);
  };
}
