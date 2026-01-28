// from: Savitch. Absolute C++
#pragma once

#include "Employee.h"

class SalariedEmployee : public Employee{
public:
  SalariedEmployee();
  SalariedEmployee(string name, string ssn, double weeklyPay);

  SalariedEmployee(const SalariedEmployee& s);
  SalariedEmployee& operator =(const SalariedEmployee& s);

  double getSalary();

private:
  double _weeklyPay;
};
