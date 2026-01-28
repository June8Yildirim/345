// from: http://www.cplusplus.com/doc/oldtutorial/namespaces/
#include <iostream>
using namespace std;

namespace first{
	int x = 5;
	int y = 10;
}

namespace second{
	double x = 3.1416;
	double y = 2.7183;
}

int main() {
	// any unqualified names will be looked up in namespace first if not declared in the scope.   
	using namespace first;
	// x is defined in the currect scope
	int x = 0;
    // x is the one declared in the current scope. 
	cout << x << endl;
	// y is not defined in the current scope, and is found in namespace first. 
	cout << y << endl;
	cout << second::x << endl;
	cout << second::y << endl;
	return 0;
}
