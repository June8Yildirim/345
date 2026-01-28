#pragma once

/**
* The classes that implement a concrete strategy should inherit this.
* The Calculator class uses this to use a concrete strategy.
*/
class Strategy {
public:
  /**
   * Method whose implementation varies depending on the strategy adopted.
   */
  virtual int execute(int a, int b) = 0;
};

