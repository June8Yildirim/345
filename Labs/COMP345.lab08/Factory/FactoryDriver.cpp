#include "Circle.h"
#include "Shape.h"
#include "Square.h"
#include "ShapeFactory.h"

int main(){
  // Give me a circle
  Shape* shape1 = ShapeFactory::Create("circle");

  // Give me a square
  Shape* shape2 = ShapeFactory::Create("square");

  shape1->draw(); // will call appropriate draw()
  shape2->draw(); // as it is defined as virtual

  delete shape1;
  delete shape2;
}
