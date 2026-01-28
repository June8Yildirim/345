#pragma once

#include<iostream>
#include "Strategy.h"
using namespace std;
/**
* A concrete Strategy that implements a subtraction operation
*/
class Subtract : public Strategy {
public:
  int execute(int a, int b) {
    cout << "Called Subtract's execute()" << endl;
    return a - b;
  }
};

