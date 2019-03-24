#include "activity.hpp"
#include "../pool.hpp"
#include "../entities/entity.hpp"
#include "./crafting.hpp"

using namespace Icarus::Entities;

namespace Icarus::Activities {
  class ConstructionActivity
  : public Activity {

  protected:
    /** What does it take to make this? */
    Recipe* recipe;

    /** Where do the materials come from? */
    Pool<Entity*> materials;

    /** Who is working on this? */
    Pool<Entity*> workers;

  public:
    bool isFinished();

    /** get the percent completion */
    double getProgress();

    /** start the crafting processs */
    void execute();

    /** executed every second */
    void tick();
  };
}
