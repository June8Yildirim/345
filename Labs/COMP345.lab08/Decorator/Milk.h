#pragma once

#include "CoffeeDecorator.h"

/** Decorator that mixes Milk with coffee.
*  It is a subclass of CoffeeDecorator, and thus a subclass of Coffee.
*/
class Milk : public CoffeeDecorator {
public:
  /**
   * When creating a decorated Coffee, pass a Coffee to be decorated
   * as a parameter. Note that this can be an already-decorated Coffee.
   */
  Milk(Coffee *decoratedCoffee) : CoffeeDecorator(decoratedCoffee) {}
  /**
   * Overriding methods defined in the abstract superclass.
   * Enables to provide different behavior for decorated Coffee methods
   */
  double getCost() {
    return CoffeeDecorator::getCost() + 0.5;
  }
  string getIngredients() {
    return CoffeeDecorator::getIngredients() + ", Milk";
  }
  /**
   * May also add additional members for decorated-specific data
   * or behavior
   */
};

