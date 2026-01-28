#pragma once
#include "Pizza.h"

// Abstract class providing the structure for all 
// concrete pizza builders
class PizzaBuilder{
public:
  //get the built Pizza from the Builder
  Pizza* getPizza() { return m_pizza; }
  //build a generic empty Pizza
  void createNewPizzaProduct() { m_pizza = new Pizza; }
  //create each part of the Product according to subtypes
  virtual void buildDough() = 0;
  virtual void buildSauce() = 0;
  virtual void buildTopping() = 0;
protected:
  //Product built by Pizza Builder
  Pizza* m_pizza;
};

