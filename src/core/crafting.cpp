#include "crafting.hpp"

using namespace Icarus;

Resource::Resource(int id, string name) {
  this->identifier = id;
  this->name = name;
}

bool Resource::isResource(Resource res) {
  return (res.identifier & RESOURCE_GROUP) == RESOURCE_GROUP;
}

bool Resource::isKnowledge(Resource res) {
  return (res.identifier & KNOWLEDGE_GROUP) == KNOWLEDGE_GROUP;
}

bool Resource::isLabour(Resource res) {
  return (res.identifier & LABOUR_GROUP) == LABOUR_GROUP;
}

bool Resource::isPower(Resource res) {
  return (res.identifier & POWER_GROUP) == POWER_GROUP;
}
