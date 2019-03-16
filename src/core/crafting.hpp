#include <string>
#include <utility>


using std::string;
using std::pair;


/**
 * Identifiers
 *
 * Hex Groupings
 *
 * Resource  0001 XXXX
 * Knowledge 0010 XXXX
 * Labour    0100 FFFF
 * Power     1000 FFFF
 */
namespace Icarus {

  /**
   * An instance that represents a single kind of global resource.
   *
   * For example, sheet metal would be an instance sitting in memory
   * that you get a reference to, and a variable indicating the quantity
   * is stored wherever to tell you how much "resource"
   */
  class Resource {
  public:
    /* Assign a resource ID by going RESOURCE_GROUP | 0x0001 */
    static const int RESOURCE_GROUP = 0x00010000;
    static const int KNOWLEDGE_GROUP = 0x00100000;
    static const int LABOUR_GROUP = 0x01000000;
    static const int POWER_GROUP = 0x10000000;

    static bool isResource(Resource res);
    static bool isKnowledge(Resource res);
    static bool isLabour(Resource res);
    static bool isPower(Resource res);

    // ------------------------------------------------------
  
    int    identifier;
    string name;

    Resource(int id, string name);
  };

  using Recipe = pair<int, Resource>;
}
