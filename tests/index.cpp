#include <cstdio>
#include "./core/resource-generator.hpp"
#include "./core/craft-process.hpp"

int main(int argc, char* argv[]) {
  ResourceGeneratorTests::run();
  CraftProcessTests::run();

  return 0;
}

