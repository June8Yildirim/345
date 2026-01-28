#include <iostream>
using namespace std;
// The following free functions are all compiled into a function f(int [][15][20]). 
// Even though they are declared with a different signature, their array parameter 
// is decayed into a pointer in exactly the same manner, leading them to have the same function 
// signature. 
namespace ns1 {
	void f(int b[][15][20]) {
		cout << "void f(int b[][15][20])" << sizeof(b) << endl;

	}
}

namespace ns2 {
	void f(int b[100][15][20]) {
		cout << "void f(int b[10][15][20])" << sizeof(b) << endl;

	}
}

namespace ns3 {
	void f(int b[10][15][20]) {
		cout << "void f(int b[10][15][20])" << sizeof(b) << endl;
	}
}

// The above function's array parameter all decay into the following's : 
namespace ns4 {
	void f(int(*b)[15][20]) {
		cout << "void f(int(*b)[15][20])" << sizeof(b) << endl;
	}
}

// The following function's array parameter does not decay into a pointer, 
// as it uses the noptr-declarator that prevents the array declaration to 
// decay into a pointer. 
namespace ns5 {
	void f(int(&b)[10][15][20]) {
		cout << "void f(int(&b)[10][15][20])" << sizeof(b) << endl;
	}
}

int main() {
	int a1[10][15][20];
	int b1[20][15][20];
	// all the above-defined functions have valid array parameter declarations
	// to receive any array [][15][20]
	ns1::f(a1);
	ns2::f(a1);
	ns3::f(a1);
	ns4::f(a1);
	ns1::f(b1);
	ns2::f(b1);
	ns3::f(b1);
	ns4::f(b1);
	ns5::f(a1); 

	// one-dimensional 
	int a[2] = {1,2};                            // array of 2 int
	int (*p1) = a;                               // a is explicitly decayed to a pointer p1 to the first element of a
	cout << "*(p1 + 1): " << *(p1 + 1) << endl;  // value of second element of array pointed to by p1 (2) 
	cout << "*(a + 1): " << *(a + 1) << endl;    // Here, a is implicitly decayed into a pointer. Value of second element of array pointed to by a (2).  
	                                             
	// two-dimensional
	int b[2][3] = {1,2,3,4,5,6};                           // array of 2 arrays of 3 int
	cout << "*(*(b+0)+0): " << *(*(b + 0) + 0) << endl;    // Here, b is implicitly decayed to a pointer. Increase decayed b by 0 rows, then 0 element (1). 
	// int** p2 = b;                                       // error: b does not decay to int**
	int(*p2)[3] = b;                                       // b is explicitly decayed to a pointer to the first 3-element row of b
	cout << "*(*(p2+0)+0): " << *(*(p2 + 0) + 0) << endl;  // increase p2 by 0 rows, then 0 element (1)
	cout << "*(*(p2+1)+2): " << *(*(p2 + 1) + 2) << endl;  // increase p2 by 1 row, then 2 elements (6)
	cout << "*(p2[0]): " << *(p2[0]) << endl;              // value of first element of first row of array pointed to by p2 (1)
	cout << "p2: " << p2 << endl;                          // address pointed to by p2
	cout << "a: " << p2 << endl;                           // address pointed to by a when decayed to a pointer
	cout << "p2[0]: " << p2[0] << endl;                    // address of first row of array pointed to by p2
	cout << "p2[1]: " << p2[0] << endl;                    // address of second row of array pointed to by p2

	// three-dimensional
	int c[2][3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 };      // array of 2 arrays of 3 arrays of 4 int
	for (int i = 0; i < 24; i++){
		cout << *(*(*(c + 0) + 0) + i) << ' ';             // here, c is implicitly decayed into a pointer, then is used to access the individual elements sequentially
	}
	cout << endl;

	for (int x = 0; x < 2; x++) {
		for (int y = 0; y < 3; y++) {
			for (int z = 0; z < 4; z++) {
				cout << *(*(*(c + x) + y) + z) << ' ';    // here, c is implicitly decayed into a pointer, then is incremented by x planes, y rows and z elements
			}
		}
	}
	cout << endl;

	int(*p3)[3][4] = c;                                   // c is explicitly decayed to a pointer to the first 3×4-element plane of c
	for (int i = 0; i < 12; i++)
		cout << *(*(*(p3 + 0) + 0) + i) << ' '; 
	cout << endl;

	int(*p4)[4] = *p3;                                    // p3 is implicitly decayed to a pointer to the first 4-element array of p3
	for (int i = 0; i < 4; i++)
		cout << *(*(p4+0) + i) << ' ';
	cout << endl; 

	
	int arr[2][3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24 }; // array of 2 int[3][4]

	cout << "arr: "                << arr                << endl; // array of 2 int[3][4]. When printed, prints address of 1st int[3][4]. 
	cout << "arr+1: "              << arr+1              << endl; // decay+add: address of 2nd int[3][4] array.
	cout << "*(arr+1): "           << *(arr+1)           << endl; // dereference: 2nd 2-dim array. When printed, prints its address .
	cout << "*(arr+1)+2: "         << *(arr+1)+2         << endl; // decay+add: address of 3rd int[4] array in 2nd int[3][4] array.
	cout << "*(*(arr+1)+2): "      << *(*(arr+1)+2)      << endl; // dereference: 3rd 1-dim array in 2nd 2-dim array. When printer, prints its address.
	cout << "*(*(arr+1)+2)+3: "    << *(*(arr+1)+2)+3    << endl; // decay+add: address of 4th element in 3rd int[4] array in 2nd int[3][4] array.
	cout << "*(*(*(arr+1)+2)+3): " << *(*(*(arr+1)+2)+3) << endl; // dereference: 4th element in 3rd int[4] array in 2nd int[3][4] array. Prints value (24).

}