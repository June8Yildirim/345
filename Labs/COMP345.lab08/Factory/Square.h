#include<iostream>
#include "Shape.h"
using namespace std;

class Square : public Shape {
public:
  void draw() { cout << "I am square" << endl; }
};
