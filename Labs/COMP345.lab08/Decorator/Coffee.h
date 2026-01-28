#pragma once
#include<string>

using namespace std;

/**
* The abstract Coffee class defines the functionality of any Coffee
* implemented by subclasses of Coffee
*/
class Coffee {
public:
  virtual double getCost() = 0;
  virtual string getIngredients() = 0;
};

