#include <iostream>
using namespace std;

class Base {
public:
  virtual void function1();
  virtual void function2();
  virtual void function3() = 0;
  void function4();
};

class Derived1 : public Base {
public:
  void function1();
  virtual void function5();
  void function6();
};

class Derived2 : public Base {
public:
  void function2();
  void function3();
  void function4();
  virtual void function5();
};

class Derived3 : public Derived1 {
public:
  void function3();
};

void Base::function1(){
  cout << "Base::function1()" << endl;
}

void Base::function2(){
  cout << "Base::function2()" << endl;
}

void Base::function4(){
  cout << "Base::function4()" << endl;
}

void Derived1::function1(){
  cout << "Derived1::function1()" << endl;
}

void Derived1::function5(){
  cout << "Derived1::function5()" << endl;
}

void Derived1::function6(){
  cout << "Derived1::function6()" << endl;
}

void Derived2::function2(){
  cout << "Derived2::function2()" << endl;
}

void Derived2::function3(){
  cout << "Derived2::function3()" << endl;
}

void Derived2::function4(){
  cout << "Derived2::function4()" << endl;
}

void Derived2::function5(){
  cout << "Derived2::function5()" << endl;
}

void Derived3::function3(){
  cout << "Derived3::function3()" << endl;
}

int main(){
  Base *baseArray[] = { new Derived2, new Derived3 };
  
  cout << "baseArray[0]->function1(): " << endl;
  baseArray[0]->function1();
  cout << "baseArray[0]->function2(): " << endl;
  baseArray[0]->function2();
  cout << "baseArray[0]->function3(): " << endl;
  baseArray[0]->function3();
  cout << "baseArray[0]->function4(): " << endl;
  baseArray[0]->function4();
  //baseArray[0]->function5(); //no function5 in Base
  cout << "dynamic_cast<Derived2*>(baseArray[0])->function5(): " << endl;
  dynamic_cast<Derived2*>(baseArray[0])->function5();
  
  cout << "baseArray[1]->function1(): " << endl;
  baseArray[1]->function1();
  cout << "baseArray[1]->function2(): " << endl;
  baseArray[1]->function2();
  cout << "baseArray[1]->function3(): " << endl;
  baseArray[1]->function3();
  cout << "baseArray[1]->function4(): " << endl;
  baseArray[1]->function4();
  //baseArray[1]->function5();
  cout << "dynamic_cast<Derived3*>(baseArray[1])->function5(): " << endl;
  dynamic_cast<Derived3*>(baseArray[1])->function5();
  //baseArray[1]->function6();
  cout << "dynamic_cast<Derived3*>(baseArray[1])->function6(): " << endl;
  dynamic_cast<Derived3*>(baseArray[1])->function6();
  int i; cin >> i;
}
