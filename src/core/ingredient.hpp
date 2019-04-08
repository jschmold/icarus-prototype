#pragma once

namespace Icarus::Core {
  /**
   * Describes one entry in a recipe
   */
  template <typename T>
  class Ingredient {
  protected:
    /** How much is needed? */
    int needed;
    /** How much of the needed T is committed? */
    int committed;

  public:
    /** Is this ingredient satisfied with the needed == committed */
    bool isSatisfied();

  };
}
