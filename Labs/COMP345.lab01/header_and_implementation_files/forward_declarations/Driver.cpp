#include "A.h"    // main declares an object of type A: needs the whole class declaration: include the header file that contains it
#include "B.h"    // main declares an object of type B: needs the whole class declaration: include the header file that contains it
//#include "C.h"  // use a #include if this file refers to C as a type for a variable declaration, 
				  // or refers to some of the members of the class(es) declared in C.h
class C;          // use a forward declaration if this file refers to class C only as a pointer or a reference, 
                  // or if it would refer to class C as a parameter or return type in a function header. 

int main(){
	A a; 
	B *b; 
	C* c1;              // main declares a pointer to a C. It does not need the entire class: provide only a forward reference
	//C* c2 = new C(); // however, if we use any member of C - here its constructor - we need to include the whole class decaration
}