
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
	//from now on, x refers to first::x
	using first::x;
	//from now on, y refers to second::y
	using second::y;
	cout << x << endl;
	cout << y << endl;
	cout << first::y << endl;
	cout << second::x << endl;
	return 0;
}
