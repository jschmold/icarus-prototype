#include "../../src/core/resource-generator.hpp"
#include "resource-generator.hpp"
#include <iostream>
#include <sstream>
#include "../testing.hpp"

using namespace std;
using Icarus::Entity;
using Icarus::ResourceGenerator;
using IcarusTesting::test;

namespace ResourceGeneratorTests {
  void sourceGeneratesAccurately() {
    auto electricity = new Entity("Electricity", 0x0001, Entity::POWER_GROUP);
    auto source = new ResourceGenerator(
      "Power Generator",
      electricity,
      500,
      1000,
      100 
    );

    source->onThink();
    auto remaining = source->getAmount();

    if (remaining != 600) {
      stringstream str;
      str << "Expected amount to be 600, actually " << remaining;
      throw std::logic_error(str.str());
    }

    delete source;
    delete electricity;
  }

  void sourceDecaysAccurately() {
    auto oxygen = new Entity("Oxygen", 0x0001, Entity::POWER_GROUP);
    auto source = new ResourceGenerator(
      "Lungs",
      oxygen,
      1000,
      1000,
      -10
    );

    source->onThink();

    auto remaining = source->getAmount();

    if (remaining != 990) {
      stringstream str;
      str << "Expected amount to be 990, actually " << remaining;
      throw std::logic_error(str.str());
    }

    delete source;
    delete oxygen;
  }

  void canDepleteCompletely() {
    auto oxygen = new Entity("Oxygen", 0x0001, Entity::POWER_GROUP);
    auto source = new ResourceGenerator(
      "Lungs",
      oxygen,
      10,
      10,
      -20
    );

    source->onThink();

    auto remaining = source->getAmount();

    if (remaining != 0) {
      stringstream str;
      str << "Expected amount to be 0, actually " << remaining;
      throw std::logic_error(str.str());
    }

    delete source;
    delete oxygen;
  }


  void run() {
    cout << "Power Source Tests" << endl;
    test("Accurately Generates", sourceDecaysAccurately);
    test("Accurately Decays", sourceGeneratesAccurately);
    test("Step can decay to 0", sourceGeneratesAccurately);
  }
}
