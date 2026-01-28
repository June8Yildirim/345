#pragma once

#include<iostream>
#include "Strategy.h"
using namespace std;
/**
* A concrete Strategy that implements a multiplication operation
*/
class Multiply : public Strategy {
public:
  int execute(int a, int b) {
    cout << "Called Multiply's execute()" << endl;
    return a * b;
  }
};

