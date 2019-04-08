#pragma once

#include <string>
#include <list>
#include "transform.hpp"
#include "./activities.hpp"


using std::string;
using std::list;

using Icarus::Activities::Ingredient;
using Icarus::Activities::Recipe;

/**
 * The base class of all bays that exist inside the station
 */
namespace Icarus {

  /**
   * This is a live instance of an actual structure
   */
  class Structure {
  public:
    class Definition;

    /** First: current, Second: max */
    using Integrity = pair<double, double>;

    /**
     * Just does the building. It is not the responsibility of this function
     * to consume any materials.
     */
    static Activities::ConstructionActivity Construct(Structure::Definition def, Transform location);

  protected:
    /** Where is this located?  */
    Transform transform;
    list<Activities::Activity>* Activities;

    string name;
    Integrity integrity;

    Structure(string name,
              Transform location,
              double integrity);

  public:
    void repair(double amt);
    void damage(double amt);

    /** Less than 15% integrity */
    bool isCritical();
  };

  /**
   * The game's package data for kinds will load into
   * this data type for structures, and initialize
   * into Structure types based on a save-game
   */
  class Structure::Definition {
  public:
    /** What does it take to make this structure? */
    Recipe recipe;

    /** What is the name of this structure? */
    string name;

    /** How long does it take to build */
    double duration;

    /** The id of the structure's type */
    int identifier;

    Definition(string name,
               double duration,
               int identifier,
               Recipe recipe);
  };
}
