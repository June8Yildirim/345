#include<iostream>
#include "Calculator.h"
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
using namespace std;

int main() {
  Calculator calculator(new Add());
  int resultA = calculator.executeStrategy(3, 4);
  calculator.setStrategy(new Subtract());
  int resultB = calculator.executeStrategy(3, 4);
  calculator.setStrategy(new Multiply());
  int resultC = calculator.executeStrategy(3, 4);

  cout << "Result of addition strategy: " << resultA << endl;
  cout << "Result of subtraction strategy: " << resultB << endl;
  cout << "Result of multiplication strategy: " << resultC << endl;

  return 0;
}
