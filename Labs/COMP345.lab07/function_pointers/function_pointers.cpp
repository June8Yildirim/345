#include <iostream>
using namespace std;

// These are free functions that all have the same signature. 
// We will below create a function pointer that point to 
// one of these functions depending on what arithmetic operations
// we want to use. 
float Plus(float a, float b)     {return a + b;}
float Minus(float a, float b)    {return a - b;}
float Multiply(float a, float b) {return a * b;}
float Divide(float a, float b)   {return a / b;}

// This function explicitly refers to the different functions
// to trigger a different arithmetic operation. 
// If we want to add other operators, we need to change this function. 
float Switch(float a, float b, char opCode) {
  float result; // execute operation 
  switch (opCode) {
  case '+': result = Plus(a, b); break;
  case '-': result = Minus(a, b); break;
  case '*': result = Multiply(a, b); break;
  case '/': result = Divide(a, b); break;
  }
  return result;
}

// This function receives a function pointer and calls the pointed 
// function to trigger an arithmetic operation. 
// If we want to add other operators, this code does not need to be changed. 
float Switch_With_Function_Pointer(float a, float b,
				   float(*ptFunc)(float, float)) {
  // call using function pointer 
  float result = ptFunc(a, b); 
  return result;
}  

int main(){
  //function pointer declaration
  float(*op)(float, float);
  //assign the address of a particular function to the pointer
  op = &Plus;
  cout << "Switch: 1+2=";
  cout << Switch(1, 2, '+') << endl;
  cout << "Switch_With_Function_Pointer: 1+2=";
  cout << Switch_With_Function_Pointer(1, 2, op) << endl;
  int i; cin >> i;
}


