#pragma once
#include "Strategy.h"
/**
* Class configured with a ConcreteStrategy object and maintains
* a reference to a Strategy object. Depending on which strategy is
* plugged in, it will execute a different operation.
*/
class Calculator {
private:
  Strategy *strategy;
public:
  Calculator() {};
  /**
   * Plugs in a specific strategy to be used
   */
  Calculator(Strategy *initStrategy) {
    this->strategy = initStrategy;
  }
  void setStrategy(Strategy *newStrategy) {
    this->strategy = newStrategy;
  }
  /**
   * Method that executes a different strategy depending on what strategy was
   * plugged in upon instantiation.
   */
  int executeStrategy(int a, int b) {
    return this->strategy->execute(a, b);
  }
};

