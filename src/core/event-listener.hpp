#include <string>

using std::string;

namespace Icarus {
  class EventListener {
    void onEvent(string evt, string* args);
  };
}
