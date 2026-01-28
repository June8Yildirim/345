#pragma once
#include "PizzaBuilder.h"

class SpicyPizzaBuilder : public PizzaBuilder{    //Concrete Builder 2
public:
  virtual void buildDough(){                      //The construction process may vary 
    m_pizza->setDough("pan baked");
  }                                               //across different Concrete Builders. 
  virtual void buildSauce(){
    m_pizza->setSauce("hot");
  }
  virtual void buildTopping(){
    m_pizza->setTopping("pepperoni+salami");
  }
};
