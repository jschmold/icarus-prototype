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

  class Structure {
  public:
    class Definition;

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
    double integrity;

    Structure(string name, Transform location);

  };

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
