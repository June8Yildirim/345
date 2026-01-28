#include<iostream>
#include "SingletonClass.h"

using namespace std;

void foo(void){
  SingletonClass::instance()->increment_value();
  cout << "foo:  global_ptr is " << SingletonClass::instance()->get_value() << '\n';
}

void bar(void){
  SingletonClass::instance()->increment_value();
  cout << "bar:  global_ptr is " << SingletonClass::instance()->get_value() << '\n';
}

int main(int argc, char *argv[]){
  cout << "main: global_ptr is " << SingletonClass::instance()->get_value() << '\n';
  foo();
  bar();
  return 0;
}
