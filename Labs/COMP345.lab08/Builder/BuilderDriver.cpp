//Pizza Builder Client

#include "Cook.h"
#include "HawaiianPizzaBuilder.h"
#include "SpicyPizzaBuilder.h"

int main(){
  Cook cook;                                    //Create the Director 
  PizzaBuilder* hawaiianPizzaBuilder =          //Create the Concrete Builder
    new HawaiianPizzaBuilder;
  PizzaBuilder* spicyPizzaBuilder =
    new SpicyPizzaBuilder;
  
  cook.setPizzaBuilder(hawaiianPizzaBuilder);   //Tell the Director which Builder to use
  cook.constructPizza();                        //Tell the Director to construct the Product
  Pizza* hawaiian = cook.getPizza();            //Client gets the Product
  hawaiian->open();                             //Client uses the Product
  
  cook.setPizzaBuilder(spicyPizzaBuilder);      //same for another kind of product
  cook.constructPizza();
  
  Pizza* spicy = cook.getPizza();
  spicy->open();
  
  delete hawaiianPizzaBuilder;
  delete spicyPizzaBuilder;
  delete hawaiian;
  delete spicy;
  
  return 0;
}
