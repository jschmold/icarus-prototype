#include "testing.hpp"
#include <string>
#include <iostream>

using namespace std;


void IcarusTesting::test(string test, action fn) {
  cout << "  " << test << ": ";
  try {
    fn();
  } catch (std::logic_error e) {
    cout << "Failed." << endl;
    cout << "    Logical error: " << endl << e.std::exception::what() << endl;
  }

  cout << "Passed" << endl;
}

