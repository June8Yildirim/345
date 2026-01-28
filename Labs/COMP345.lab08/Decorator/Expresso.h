#pragma once
#include "Coffee.h"

/**
* Kind of Coffee
*/
class Espresso : public Coffee {
public:
  double getCost() {
    return 1.25;
  }
  
  string getIngredients() {
    return "Strong Coffee";
  }
};

