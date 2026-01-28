#pragma once

class A; //Forward Declaration

class B {
private:
	int _b;

	// A::show is a friend function to class B
	// so A::show has access to all members of B
	friend void A::show(A&, B&);
public:
	B() { _b = 20; }
};
