#include "structure.hpp"
#include <string> 

using namespace Icarus;
using std::string;

Structure::Definition::Definition(
  string    name,
  double    duration,
  int       identifier,
  Recipe    recipe
) {
  this->identifier = identifier;
  this->name       = name;
  this->duration   = duration;
  this->recipe     = recipe;
}

