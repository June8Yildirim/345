#include <iostream>
using namespace std;

class Base {
public:
	/* virtual */ ~Base() {
		cout << "Base::~Base()" << endl;
	}
};

class Derived : public Base {
public:
	~Derived() {
		cout << "Derived::~Derived()" << endl;
		// Do some important cleanup
	}
};

int main() {
	// The object created is of type Derived, so it has a Base part and a Derived part. 
	// If the destructor of type Base is called to destroy it, then the destructor of 
	// the class Derived is never called to destroy the Derived part. 
	// This is why if a class contains at least one virtual member function and is also 
	// a base class, then its destructor must be declared as virtual. 
	Base* b = new Derived();
	// use b
	delete b; // Here's the problem!
	int i; cin >> i;
}
