#pragma once

namespace Icarus::Core {
  /**
   * Describes one entry in a recipe
   */
  template <typename T>
  class Ingredient {
  protected:
    /** How much is needed? */
    int required;

    /** How much of the needed T is committed? */
    int committed;

    /** A reference to what the ingredient is */
    T resource;

  public:
    /** Is this ingredient satisfied with the needed == committed */
    bool isSatisfied ();

    /** How much is needed until this ingredient is satisfied */
    int needed();

    /** Commit a certain amount to this ingredient */
    void commit (int amt);
    
    /** Remove a certain amount from this ingredient */
    void remove (int amt);
  };
}
