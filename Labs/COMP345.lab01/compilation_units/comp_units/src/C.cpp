#include "C.h"
#include <iostream>

void cff(){
  std::cout << "Executing cff()" << std::endl;
}

void C::cmf(int cmfp){
  std::cout << "Executing C::cmf(" << cmfp << ")" << std::endl;
}

C::C(int newcmv){
  cmv = newcmv;
  std::cout << "Executing C::C(" << newcmv << ")" << std::endl;
}


