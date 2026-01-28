#pragma once
#include "Coffee.h"

/**
 * Kind of Coffee
 */
class SimpleCoffee : public Coffee {
public:
  double getCost() {
    return 1;
  }
  
  string getIngredients() {
    return "Coffee";
  }
};

