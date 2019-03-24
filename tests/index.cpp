#include <cstdio>
#include "./core/generator.hpp"
#include "./core/crafting.hpp"

int main(int argc, char* argv[]) {
  GeneratorTests::run();
  CraftingTests::run();

  return 0;
}

