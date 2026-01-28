#pragma once

#include "Coffee.h"

/**
* Abstract decorator class - note that it extends the Coffee abstract class
*/
class CoffeeDecorator : public Coffee {
protected:
  Coffee *decoratedCoffee;
public:
  /**
   * Wraps a Coffee object inside an object of one of
   * CoffeeDecorator's subclasses
   */
  CoffeeDecorator(Coffee *decoratedCoffee) {
    this->decoratedCoffee = decoratedCoffee;
  }
  /**
   * Provides the wrapper with the Coffee interface and delegates
   * its methods to the wrapped Coffee object.
   */
  double getCost() {
    return decoratedCoffee->getCost();
  }
  string getIngredients() {
    return decoratedCoffee->getIngredients();
  }
};

