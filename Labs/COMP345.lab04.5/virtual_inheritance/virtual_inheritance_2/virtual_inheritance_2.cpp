#include <iostream>
using namespace std;

class V {
  int i;
public:
  V() { cout << "in V::V()\n"; };
  V(int i) : i(i){ cout << "in V::V(int)\n"; }
};
class A : virtual public V {
public:
  A() { cout << "in A::A()\n"; };
  A(int i) : V(i) { cout << "in A::A(int)\n"; }
};

class B : virtual public V {
public:
  B(){ cout << "in B::B()\n"; };
  B(int i) : V(i) { cout << "in B::B(int)\n"; }
};

class C : public A, B {
public:
  C(){ cout << "in C::C()\n"; };
  C(int i) : A(i), B(i) { cout << "in C::C(int)\n"; }
};

class D : virtual public V {
public:
  D() { cout << "in D::D()\n"; }
  D(int i) : V(i) { cout << "in D::D(int)\n"; }
};

class E : public C, D {
public:
  E() { cout << "in E::E()\n"; }
  E(int i) : V(i), C(i), D(i) { cout << "in E::E(int)\n"; }
};

int main(){
  E e1(2);
  E e2;
  int i; cin >> i;
  return 0;
}
