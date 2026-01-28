#include <iostream>
using namespace std; 

class C {
public: 
	C() {cout << "C::C();" << endl;};
	C(int) { cout << "C::C(int);" << endl; };
	C(C&) { cout << "C::C(C);" << endl; }
};

void pass_by_value(C val_c) {
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	cout << "= pass_by_value " << endl;
	cout << "= address where val_c is stored: " << &val_c << endl << endl;
	cout << "= = = = = = = = = = = = = = = = =" << endl;

}
void pass_by_reference(C& ref_c) {
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	cout << "= pass_by_reference " << endl;
	cout << "= address of object that ref_c refers to: " << &ref_c << endl << endl;
	cout << "= = = = = = = = = = = = = = = = =" << endl;
}
void pass_by_pointer(C* ptr_c) {
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	cout << "= pass_by_pointer " << endl;
	cout << "= address of object pointed to by ptr_c: " << ptr_c << endl << endl;
	cout << "= = = = = = = = = = = = = = = = =" << endl;
}
C pass_and_return_by_value(C val_c) {
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	cout << "address where val_c is stored: " << &val_c << endl << endl;
	// returning by value returns a copy of the local object (copied using the copy constructor). 
	return val_c; 
}
C* pass_and_return_by_pointer(C* ptr_c) {
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	cout << "address of object pointed to by ptr_c: " << ptr_c << endl << endl;
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	// Here we return a pointer to the object. 
	// 
	// Returning a pointer the original object is not really useful (though it avoids making a copy of the object)  
	// Really useful if we want to receive an object, do some processing using  it, 
	// and return a new object created locally that resides on the heap, 
	// or sometimes receive a null pointer and return a pointer to newly created object.
	// 
	// if (ptr_c) {
    //   process and change the passed object
	// } else {
	//   do some processing and create a new pointer to a C
	// } 
	return ptr_c; 
}
C& pass_and_return_by_reference(C& ref_c) {
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	cout << "= address of object that ref_c refers to: " << &ref_c << endl << endl;
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	// here we return the original reference
	// 
	// Use this if you want the calling function to use the function call as a value part of an expression.   
	// The most famous example of pass-and-return-by reference is the implementation 
	// of stream extraction/insertion operators (<</>>). 
	// 
	// Limitation: as a reference cannot be made to point to a new object or to be null, 
	// passing/returning by pointer is often the appropriate solution. 
	return ref_c;
}
int main() {
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	C c;
	cout << "= = = = = = = = = = = = = = = = =" << endl;
	cout << "address where c is stored : " << &c << endl << endl;
	cout << "passing by value" << endl;
	pass_by_value(c);
	cout << "passing by reference" << endl;
	pass_by_reference(c);
	cout << "passing by pointer" << endl;
	pass_by_pointer(&c);

	cout << "passing/returning by value" << endl;
	c = pass_and_return_by_value(c);
	cout << "passing/returning by reference" << endl;
	c = pass_and_return_by_reference(c);
	cout << "passing/returning by pointer" << endl;
	c = *pass_and_return_by_pointer(&c);

	return 0;
}

