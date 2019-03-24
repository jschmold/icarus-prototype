#pragma once
#include "entity.hpp"
#include <list>

using std::list;

namespace Icarus::Entities {
  class Citizen : public EntityPool {
    /** labour pool */
    EntityPool* energy;

    list<Entity*> knowledge;

  public:
    Citizen(
      Entity* energyType,
      int     energyAmount,
      int     energyMax
    );

    /** energy controls */
    int addEnergy(int amt);
    int drawEnergy(int amt);

    /** skills */
    void learnSkill(Entity* entity);
    void forgetSkill(Entity* entity);
    bool hasSkill(Entity* entity);
  };
}
