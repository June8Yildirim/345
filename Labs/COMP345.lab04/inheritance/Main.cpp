// from: Savitch. Absolute C++
#include<iostream>
#include "Employee.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
using namespace std;

int main(){
  Employee e1("A", "111-111-111");
  SalariedEmployee se1("B", "222-222-222", 100.00);
  HourlyEmployee he1("C", "333-333-333", 10, 10);

  cout << e1;

  cout << "Copying Employee e1 to e2" << endl;
  Employee e2 = e1;

  cout << "Copying SalariedEmployee se1 to se2" << endl;
  SalariedEmployee se2 = se2;

  cout << "Copying HourlyEmployee he1 to he2" << endl;
  HourlyEmployee he2 = he1;	
}
