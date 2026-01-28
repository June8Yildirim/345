// from: Savitch. Absolute C++

#include<iostream>
#include "HourlyEmployee.h"
using namespace std;

HourlyEmployee::HourlyEmployee() : Employee(), _wageRate(0), _hours(0){
}

HourlyEmployee::HourlyEmployee(string name, string ssn, double wageRate, double hours) : Employee(name, ssn), _wageRate(wageRate), _hours(hours){
}

HourlyEmployee::HourlyEmployee(const HourlyEmployee& h) : Employee(h){
  cout << "Inside copy constructor of HourlyEmployee" << endl;
  _wageRate = h._wageRate;
  _hours = h._hours;
}

HourlyEmployee& HourlyEmployee::operator=(const HourlyEmployee& h){
  cout << "Inside operator = of HourlyEmployee" << endl;
  Employee::operator= (h);
  _wageRate = h._wageRate;
  _hours = h._hours;
  return *this;
}
