#include <iostream>
using namespace std;

class A1 {
  int i;
public:
  A1() { cout << "in A1::A1()\n"; };
  A1(int k) : i(k){ cout << "in A1::A1(int)\n"; }
}; 

class A : virtual public A1 {
public:
  A() {cout<<"in A::A()\n";};
  A(int k) : A1(k){ cout << "in A::A(int)\n";}
};

class B : public A {
public:
  B(){cout<<"in B::B()\n";};
  B(int i) : A(i) { cout << "in B::B(int)\n"; }
};

class C : public A {
public:
  C(){ cout << "in C::C()\n"; };
  C(int i) : A(i) { cout << "in C::C(int)\n"; }
};

class D : public B, C{
public:
  D() { cout << "in D::D()\n"; }
  D(int i) : A1(i), B(i), C(i) { cout << "in D::D(int)\n"; }
};

int main(){
  D d1(2);
  D d2;
  int i; cin >> i;
  return 0;
}
