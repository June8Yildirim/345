// from: Savitch. Absolute C++
#pragma once

#include "Employee.h"

class HourlyEmployee : public Employee{
public:
  HourlyEmployee();
  HourlyEmployee(string name, string ssn, double wageRate, double hours);
	
  HourlyEmployee(const HourlyEmployee& h);
  HourlyEmployee& operator =(const HourlyEmployee& h);

private:
  double _wageRate;
  double _hours;
};
