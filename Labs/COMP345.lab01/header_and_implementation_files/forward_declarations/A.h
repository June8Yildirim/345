#pragma once
 // #include "b.h" // using a #include in both header files would result in a recursive include, which would fail due to the #pragma once guard

class B; // class A declares a pointer to an A, no need for the whole class: use a forward declaration

class A { B* b; };