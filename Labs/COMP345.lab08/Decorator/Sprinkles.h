#pragma once

#include "CoffeeDecorator.h"

class Sprinkles : public CoffeeDecorator {
public:
  Sprinkles(Coffee *decoratedCoffee) : CoffeeDecorator(decoratedCoffee) {}
  double getCost() {
    return CoffeeDecorator::getCost() + 0.2;
  }
  string getIngredients() {
    return CoffeeDecorator::getIngredients() + ", Sprinkles";
  }
};
