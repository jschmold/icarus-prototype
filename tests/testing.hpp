#include <string>

using std::string;

namespace IcarusTesting {
  typedef void (* action)();
  void test(string test, action fn);
}
