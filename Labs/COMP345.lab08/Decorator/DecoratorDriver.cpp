#include<iostream>
#include "SimpleCoffee.h"
#include "CoffeeDecorator.h"
#include "Sprinkles.h"
#include "Expresso.h"
#include "Milk.h"
#include "Whip.h"

using namespace std;

int main() {
  Coffee *c = new SimpleCoffee();
  cout << "Cost: " << c->getCost() << " Ingredients : " << c->getIngredients() << endl;

  c = new Milk(c);
  cout << "Cost: " << c->getCost() << " Ingredients : " << c->getIngredients() << endl;

  c = new Sprinkles(c);
  cout << "Cost: " << c->getCost() << " Ingredients : " << c->getIngredients() << endl;

  c = new Whip(c);
  cout << "Cost: " << c->getCost() << " Ingredients : " << c->getIngredients() << endl;

  // Note that you can also stack more than one decorator of the same type
  c = new Sprinkles(c);
  cout << "Cost: " << c->getCost() << " Ingredients : " << c->getIngredients() << endl;
  
  c = new Espresso();
  cout << "Cost: " << c->getCost() << " Ingredients : " << c->getIngredients() << endl;

  c = new Milk(c);
  cout << "Cost: " << c->getCost() << " Ingredients : " << c->getIngredients() << endl;

  int x; cin >> x;
  return 0;
}
