// inspired from: https://en.cppreference.com/w/cpp/language/explicit

#include <iostream>
using namespace std;

struct A {
    int a; 
    A(int newA) {                              // converting constructor: converts from int to A
        a = newA; 
        cout << "A::A(int) ";
    }
    A(int new1, int new2) {                    // converting constructor (C++11)
        a = new1 + new2;
        cout << "A::A(int,int) ";
    }
    A(const A &toCopy) {                        // copy constructor 
        a = toCopy.a;                           // used to create a new object from an existing object of the same type
        cout << "A::A(A) "; 
    }
    A operator+ (A toAdd) {                     // operators often create new objects
        cout << "A::operator+ ";
        return A(a + toAdd.a);                  // upon return, uses direct initialization using A::A(int)  
    }
    A operator= (A toAssign) {                  // upon call, uses A::A(A), as A is passed by value
//  A operator= (A& toAssign) {                  // if A is passed as reference, reference initialization is used
                                                //   which does not trigger the copy constructor
        a = toAssign.a;                 
        cout << "A::operator=(A) ";
        return *this;                           // upon return, uses copy constructor A::A(A) for copy initialization of the returned value
    }
};

struct B {
    explicit B(int) {                     // cannot be used in conversion sequence
        cout << "B::B(int) ";
    }
    explicit B(int, int) {                // cannot be used in conversion sequence
        cout << "B::B(int,int) "; 
    }
    explicit operator bool() const {      // cannot be used in conversion sequence
        cout << "B::operator bool() ";
            return true; 
    }
};

int main() {
    cout << "A a1 = 1; uses : ";
    A a1 = 1;                               // OK: copy-initialization selects A::A(int)
    cout << endl;
    cout << "A a2(2); uses : "; 
    A a2(2);                                // OK: direct-initialization selects A::A(int)
    cout << endl;
    cout << "A a3{ 4, 5 }; uses : ";
    A a3{ 4, 5 };                           // OK: direct-list-initialization selects A::A(int, int)    
    cout << endl;
    cout << "A a5(6, 7); uses : ";
    A a5(6, 7);                             // OK: direct-list-initialization selects A::A(int, int)
    cout << endl;
    cout << "A a4 = { 4, 5 }; uses : ";
    A a4 = { 4, 5 };                        // OK: copy-list-initialization selects A::A(int, int)
    cout << endl;
    cout << "A a6 = A(6) + A(7); uses : ";
    A a6 = A(6) + A(7);                     // OK: direct initialization selects A::A(int) A::A(int) A::operator+ A::A(int)
    cout << "a6 = " << a6.a << endl;
    cout << "A a7 = a6; uses : ";
    A a7 = a6;                              // OK: copy initialization A::A(A)
    cout << endl;
    cout << "a1 = a7; uses : ";
    a1 = a7;                                // OK: a1 was already previously created, so no initialization, operator= is used 
    cout << endl;
//  B b1 = 1;                               // error: copy-initialization does not consider B::B(int)
    cout << "B b2(2); uses : ";
    B b2(2);                                // OK: direct-initialization selects B::B(int)
    cout << endl;
    cout << "B b3{ 4, 5 }; uses : ";
    B b3{ 4, 5 };                           // OK: direct-list-initialization selects B::B(int, int)
    cout << endl;
//  B b4 = {4, 5};                          // error: copy-list-initialization does not consider B::B(int,int)
    cout << "B b5 = (B)1; uses : ";
    B b5 = (B)1;                            // OK: explicit cast performs static_cast
    cout << endl;
    cout << "if (b2); uses : ";
    if (b2);                                // OK: B::operator bool()
    cout << endl;
//  bool nb1 = b2;                          // error: copy-initialization does not consider B::operator bool()
}