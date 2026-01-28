#include<iostream>
#include "A.h"
#include "B.h"

using namespace std;

int A::Func2(B& b)
{
	cout << "Here we cannot access B's private member " << endl;
	return 0;
}

void A::show(A& a, B& b)
{
	cout << "Inside A::show() accessing B's private member " << b._b << endl;
}
