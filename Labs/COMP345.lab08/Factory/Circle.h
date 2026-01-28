#include<iostream>
#include "Shape.h"

using namespace std;

class Circle : public Shape {
public:
  void draw() { cout << "I am circle" << endl; }
};
