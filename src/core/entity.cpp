#include "entity.hpp"

using namespace Icarus;

Entity::Entity(string name, int id) {
  this->identifier = id;
  this->name = name;
}

Entity::Entity(string name, int id, int type) {
  this->identifier = id | type;
  this->name = name;
}

bool Entity::isItem(Entity res) {
  return (res.identifier & ITEM_GROUP) == ITEM_GROUP;
}

bool Entity::isKnowledge(Entity res) {
  return (res.identifier & KNOWLEDGE_GROUP) == KNOWLEDGE_GROUP;
}

bool Entity::isLabour(Entity res) {
  return (res.identifier & LABOUR_GROUP) == LABOUR_GROUP;
}

bool Entity::isPower(Entity res) {
  return (res.identifier & POWER_GROUP) == POWER_GROUP;
}
