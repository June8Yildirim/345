#pragma once

#include "CoffeeDecorator.h"
class Whip : public CoffeeDecorator {
public:
  Whip(Coffee *decoratedCoffee) : CoffeeDecorator(decoratedCoffee) {}
  double getCost() {
    return CoffeeDecorator::getCost() + 0.2;
  }
  string getIngredients() {
    return CoffeeDecorator::getIngredients() + ", Whip";
  }
};


