#pragma once

#include<iostream>
#include "Strategy.h"
using namespace std;

/**
* A concrete Strategy that implements a addition operation
*/
class Add : public Strategy {
public:
  int execute(int a, int b) {
    cout << "Called Add's execute()" << endl;
    return a + b;
  }
};

