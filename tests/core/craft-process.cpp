#include "../../src/core/crafting.hpp"
#include "../../src/core/entity.hpp"
#include "craft-process.hpp"
#include "../testing.hpp"
#include <chrono>
#include <iostream>
#include <sstream>

using namespace CraftProcessTests;
using namespace Icarus;
using IcarusTesting::test;
using namespace std;
using namespace std::chrono;

void waitsLongEnough() {
  auto oxygen = new Entity("Oxygen", 0x0001, Entity::ITEM_GROUP);
   
  auto process = new CraftProcess(300, 2, oxygen);
  auto now = system_clock::now();
  auto timeout = now + milliseconds(320);
  process->execute();

  while(system_clock::now() < timeout) { }

  if (process->isFinished() == false)
    throw new std::logic_error("Expected to be finished");

  delete oxygen;
  delete process;
}

void claimCorrect() {
  auto oxygen = new Entity("Oxygen", 0x0001, Entity::ITEM_GROUP);
   
  auto process = new CraftProcess(300, 30, oxygen);
  auto now = system_clock::now();
  auto timeout = now + milliseconds(320);
  process->execute();

  while(system_clock::now() < timeout) { }

  auto claimed = process->claim();
  if (claimed.first != 30) {
    stringstream str;
    str << "Expected 30 oxygen, actually " << claimed.first;
    throw logic_error(str.str());
  }

  delete oxygen;
  delete process;
}

void CraftProcessTests::run() {
  cout << "Crafting Process Tests" << endl;
  test("Takes long enough", waitsLongEnough);
  test("Claims correct amount", claimCorrect);
}
