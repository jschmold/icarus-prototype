#pragma once

#include <string>
#include "pool.hpp"


using std::string;

namespace Icarus {
  /**
   * An instance that represents a single kind of global Entity.
   *
   * For example, sheet metal would be an instance sitting in memory
   * that you get a reference to, and a variable indicating the quantity
   * is stored wherever to tell you how much "Entity"
   *
   * An "entity" is simply something that exists in the world, including 
   * forces that are usable
   */
  class Entity {
  public:
    /* Assign a Entity ID by going Entity_GROUP | 0x0001 */
    static const int ITEM_GROUP      = 0x00010000;
    static const int KNOWLEDGE_GROUP = 0x00100000;
    static const int LABOUR_GROUP    = 0x01000000;
    static const int POWER_GROUP     = 0x10000000;

    static bool isItem(Entity res);
    static bool isKnowledge(Entity res);
    static bool isLabour(Entity res);
    static bool isPower(Entity res);

    // ------------------------------------------------------
  
    int    identifier;
    string name;

    /** name, id, and enum type. Does not need to be fully qualified */
    Entity(string name, int id, int type);

    /** Name and fully qualified id */
    Entity(string name, int id);
  };

  using EntityPool = Pool<Entity*>;
}
