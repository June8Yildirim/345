#pragma once
 #include "a.h" // using a #include in both header files would result in a recursive include, which would fail due to the #pragma once guard

// class A; // class A declares a pointer to an A, no need for the whole class: use a forward declaration

//class B { A* a; };

class B : A { A a; };