#include <cstdio>
#include "./core/resource-generator.hpp"
#include "./core/crafting.hpp"

int main(int argc, char* argv[]) {
  ResourceGeneratorTests::run();
  CraftingTests::run();

  return 0;
}

