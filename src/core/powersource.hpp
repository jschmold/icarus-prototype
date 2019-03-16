#include "../thinkable.hpp"

/**
 * Any source of power that can regenerate or decay over time.
 * This means this could be a battery, a reactor, or something
 * that supplies power, and may change its current amount over
 * time
 */
namespace Icarus {
  class PowerSource : IThinkable {
  private:
    /** The current amount of power */
    int amount;

    /** The capacity of the power source */
    int max;

    /** this is the regen/decay rate to apply on each "second" */
    int rate;

    /** A multiplier to apply to the transfer of power */
    double efficiency;

  public:
    PowerSource(int amt, int max = 100, int rate = 0, double efficiency = 0.95);

    /**
     * Draw up to a certain amount of power from this Source. 
     * The amount returned is the actual quantity of power units
     * that were consumed from this Source, when the efficiency
     * is applied.
     *
     * Example:
     *   max: 1000
     *   amt: 500
     *   eff: 0.5
     *
     *   draw: 500
     *   return: 250
     *   leftover: 0
     *
     * @param int
     */
    int drawPower(int amt);

    void onThink();
  };

}
