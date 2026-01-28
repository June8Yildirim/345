// from: Savitch. Absolute C++
#include<iostream>
#include "SalariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee() : Employee(), _weeklyPay(0){
}

SalariedEmployee::SalariedEmployee(string name, string ssn, double weeklyPay) : Employee(name, ssn), _weeklyPay(weeklyPay){
}

SalariedEmployee::SalariedEmployee(const SalariedEmployee& s) : Employee(s){
  cout << "Inside copy constructor of SalariedEmployee" << endl;
  this->_weeklyPay = s._weeklyPay;
}

SalariedEmployee& SalariedEmployee::operator=(const SalariedEmployee& s){
  cout << "Inside operator = of SalariedEmployee" << endl;
  Employee::operator= (s);
  _weeklyPay = s._weeklyPay;
  return *this;
}

double SalariedEmployee::getSalary(){
  return 0;
}
