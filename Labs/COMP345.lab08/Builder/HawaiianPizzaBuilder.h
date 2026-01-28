#pragma once
#include "PizzaBuilder.h"

class HawaiianPizzaBuilder : public PizzaBuilder{ //Concrete Builder 1
public:
  virtual void buildDough(){                      //Build different parts of the pizza 
    m_pizza->setDough("cross");
  }                                               //The construction process could be
  virtual void buildSauce(){                      //more complex in a real-life example
    m_pizza->setSauce("mild");
  }                                               //The construction of the pizza part 
  virtual void buildTopping(){                    //depends on the type of pizza. 
    m_pizza->setTopping("ham+pineapple");
  }
};

