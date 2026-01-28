// topics: references, reference parameters, operator precedence. 

#include <iostream>
using namespace std; 

int f1(int f1p) {
	// Here, a copy of the passed value is made upon call. 
	// The value manipulated is a local value. 
	// Changing the local value does not affect the passed value. 
	f1p = f1p+1; 
	// A copy of the returned value is made upon return. 
	return f1p; 
}
int& f2(int& f2p) {
	// Here, the parameter is a reference to the passed value. 
	// The value manipulated is the same as the value that was passed. 
	f2p = f2p+2;
	// The reference is returned, so that it can be used as a value in an expression. 
	return f2p; 
}

int main() {
	int referredto = 0;
	// after this, x is an alias to referredto. 
	// If we change the value of x, we change the value of referredto, and inversely. 
	int& x = referredto; ;
	//
	int y = 1;
	cout << "x, referredto, y : " << x << referredto << y << endl; 
	// Here, it may see that we are now making x referring to y instead of referredto. 
	// No. We are assigning the value of y to x, which is still an alias to referredto.
	// x is now equal to 1, so is referred to. 
	x = y; 
	cout << "x, referredto, y : " << x << referredto << y << endl;
	// If we change the value of x, we dont change the value of y;  
	x = 0; 
	cout << "x, referredto, y : " << x << referredto << y << endl;
	cout << "f1(x)      : " << x << f1(x)     << x << endl;
	x = 0; 
	cout << "f1(x+1)    : " << x << f1(x + 1) << x << endl; 
	x = 0; 
	// Here, it seems x was changed prior to the call to f2. 
	// What really happens is that when the whole expression evaluates, 
	// the function call to f2 has the highest priority, so it is called 
	// before any of the << operators. Thus, the value of x is changed 
	// by f2 (as it is passed by reference) before the initial value of x
	// is printed. 
	cout << "f2(x)      : " << x << f2(x)     << x << endl; 
	x = 0;
	// one way to print what we wanted, we need to separate the statement. 
	cout << "f2(x)      : " << x;
	cout << f2(x);
	cout << x << endl;
	x = 0;
	// Here we show that the consecutive stream insertion operators
	// are evaluated from right to left if they involve expressions that
	// have operations with the same precedence. 
	cout << "f2(x)      : " << f2(x) << f2(x) << f2(x) << endl;
	x = 0;
	// ++x has higher precedence than <<, so it takes effect before them. 
	// incrementing x before returning the incremented x, then all the <<s 
	// take effect, outputting the incremented value, printing 111. 
	cout << "++x        : " << x << ++x << x << endl;
	x = 0;
	// x++ has higher precedence than <<, so it takes effect before them, 
	// it returns the current value of x (0), then increments x (now 1), 
	// then all the <<s take effect, printing 101.  
	cout << "x++        : " << x << x++ << x << endl;
	x = 0; 
	// Here, x is passed as a reference to f2, then a reference to x returned
	// by f2, thus making f2(x) a reference to x, which is assigned the value 3. 
	f2(x) = 3; 
	cout << "f2(x) = 3; : " <<  x << endl;
	return 0; 
}