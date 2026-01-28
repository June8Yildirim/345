#include <iostream>
using namespace std; 

class A {
public: 
	void f() { cout << "A::f()" << endl; }
};

class B : public A {
public:
	void f() { cout << "B::f()" << endl; }
};

class C : public B {
public:
	virtual void f() { cout << "C::f()" << endl; }
};

class D : public C {
public:
	void f() { cout << "D::f()" << endl; }
};

class E : public D {
public:
	void f() { cout << "E::f()" << endl; }
};

int main() {
	cout << "A *a[5] = { new A(), new B(), new C(), new D(), new E() };" << endl; 
	A *a[5] = { new A(), new B(), new C(), new D(), new E() };
	for (int i = 0; i <= 4; i++) {
		cout << "a[" << i << "]->f() : ";  a[i]->f();
	}
	cout << "B* b[4] = { new B(), new C(), new D(), new E() };" << endl; 
	B* b[4] = { new B(), new C(), new D(), new E() };
	for (int i = 0; i <= 3; i++) {
		cout << "b[" << i << "]->f() : ";  b[i]->f();
	}
	cout << "C* c[3] = { new C(), new D(), new E() };" << endl;
	C* c[3] = { new C(), new D(), new E() };
	for (int i = 0; i <= 2; i++) {
		cout << "c[" << i << "]->f() : ";  c[i]->f();
	}
	cout << "D* d[2] = { new D(), new E() };" << endl;
	D* d[2] = { new D(), new E() };
	for (int i = 0; i <= 1; i++) {
		cout << "d[" << i << "]->f() : ";  d[i]->f();
	}
	cout << "E* e[1] = { new E() };" << endl;
	E* e[1] = { new E() };
	for (int i = 0; i <= 0; i++) {
		cout << "e[" << i << "]->f() : ";  e[i]->f();
	}
}