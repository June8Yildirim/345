// from: https://en.cppreference.com/w/cpp/language/default_constructor
#include <iostream>
using namespace std; 

struct A{
  int x;
  A(int x = 1) : x(x) {} // User-defined default constructor. 
                         // If no parameter value is provided, the default value x=1 is used,
                         // making this a disguised default constructor.                        
};

struct B : A{
  // B::B() is implicitly-defined, calls A::A()
};

struct C{
  A a;
  // C::C() is implicitly-defined, calls A::A()
};

struct D : A{
  D(int y) : A(y) {}
  // D::D() is not declared because another constructor exists
};

struct E : A{
  E(int y) : A(y) {}
  E() = default; // explicitly defaulted, calls A::A()
};

struct F {
  int& ref; // reference member
  const int c; // const member
  // F::F() is implicitly defined as deleted because:
  // c and ref cannot be assigned a value using the automatically generated
  // default constructor. 
  
  // if we explicitly declare a default constructor that does nothing,  
  // the compiler complains that ref and c are not initialized. 
  // F() {};
  
  // The only way to properly create an object of that kind is to have a constructor such as: 
  // F(int newref, int newc) : ref(newref), c(newc) {
  // }
};


int main(){
    A a;
    B b;
    C c;
    //  D d; // compilation error: default constructor does not exist
    E e;
    // F f; // compilation error: default constructor has been deleted 
    
    int x = 1;  
    int y = 2;
    cout << x << y << endl; 
    int& ref = x;
    ref = y; // This does not make ref refer to y. It changes the value of ref (i.e. x) to the value of y (i.e. 2).   
    cout << x << y << endl; 
    
    // if we uncomment the constructor above, it has two effects: 
    // 1. The default constructor is not not defined (as opposed to defined but deleted. 
    // 2. we can now properly create an object of type F.  
    // F f = F(x, y);
}
