#include <curses.h>

/**
 * The top-line that indicates resources, power, population
 */
namespace Icarus {
  class StatusBar {
    /** The total population of the station */
    int population;

    /** the amount of available power */
    int power;

    /** The amount of available scrap */
    int scrap;

    /** The window hosting the contents of the status bar */
    WINDOW* host;

    StatusBar();
    ~StatusBar();

    void onThink();
  };
}
