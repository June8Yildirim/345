#include "A.h"
#include <iostream>
using namespace std; 

int main (){
	// This compilation unit needs to use the x and y global variables declared in A.cpp. 
	// In order not to have undeclared symbols (semantic error) for x and y, it needs to 
	// include an "extern" declaration for these to variables, which is provided by 
	// A.h (#included above). 
	cout << "x : " << x << endl;
	cout << "y : " << y << endl;  // y undeclared in this scope
}
