#include "thinkable.hpp"


/**
 * Purpose: This is the command area where a player will enter
 * the commands to operate the station.
 */
namespace Icarus {
  class CommandLine : IThinkable {
    
    
    
    /**
     * ran when an enter character has been detected
     */
    void execute();

    /**
     * Processes user input on every frame, running execute if the user presses enter
     */
    void onThink();
  };
}
