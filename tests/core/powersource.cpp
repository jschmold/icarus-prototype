#include "../../src/core/powersource.hpp"
#include "powersource.hpp"
#include <iostream>
#include "../testing.hpp"

using std::exception;
using namespace std;
using Icarus::PowerSource;
using IcarusTesting::test;

namespace PowerSourceTests {
  void sourceDecaysAccurately() {
    auto source = new PowerSource(
      "Nuclear Reactor",
      0x0001,
      500,
      1000,
      100 
    );

    source->onThink();

    auto remaining = source->getAmount();

    if (remaining != 600) {
      throw std::logic_error("Expected amount to be 600");
    }
  }


  void run() {
    cout << "Power Source Tests" << endl;
    test("Accurately Decays", sourceDecaysAccurately);
  }
}
