#pragma once
#include "PizzaBuilder.h"

class Cook {//Director
 public:
  void setPizzaBuilder(PizzaBuilder* pb){ //Use a concrete builder
                                          //for building a specific
    m_pizzaBuilder = pb;                  //kind of Pizza.
  }
  Pizza* getPizza(){                      //get the constructed Pizza
    return m_pizzaBuilder->getPizza();
  }
  void constructPizza(){                  //Creational process to create 
                                          //a pizza using the builder. 
    m_pizzaBuilder->createNewPizzaProduct();
    m_pizzaBuilder->buildDough();
    m_pizzaBuilder->buildSauce();
    m_pizzaBuilder->buildTopping();
  }
 private:
  PizzaBuilder* m_pizzaBuilder;
};

