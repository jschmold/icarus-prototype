#include "structure.hpp"
#include <string> 

using namespace Icarus;
using std::string;

/// Section: Structure Definition

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

/// End Section: Structure Definition

// Section: Structure

Structure::Structure(string name, Transform location, double integrity) {
  this->transform = location;
  this->name      = name;
  this->integrity = Integrity(integrity, integrity);
}

