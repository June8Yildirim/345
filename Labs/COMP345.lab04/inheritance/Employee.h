// from: Savitch. Absolute C++
#pragma once

#include<string>
using namespace std;

class Employee{
public:
  Employee();
  Employee(string name, string ssn);
  
  Employee(const Employee& e);
  Employee& operator =(const Employee& e);
  
  friend std::ostream& operator <<(std::ostream& stream, const Employee& e);
  
  void printCheck() const;

private:
  string _name;
  string _ssn;
  double _netPay;
};
