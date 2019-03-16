#include <curses.h>

/**
 * This is the window that appears above the command window.
 * It updates with information that is relevant to what 
 * exactly the user is doing at any given time
 */
namespace Icarus {
  class ContextWindow {

    WINDOW* host; 

    ContextWindow();
    ~ContextWindow();

    void onThink();

  };
}
