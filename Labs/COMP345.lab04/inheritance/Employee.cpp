// from: Savitch. Absolute C++

#include<iostream>
#include "Employee.h"

using namespace std;

Employee::Employee(){
}

Employee::Employee(string name, string ssn) : _name(name), _ssn(ssn){
}

Employee::Employee(const Employee& e){
  cout << "Inside copy constructor of Employee" << endl;
  _name = e._name;
  _ssn = e._ssn;
}

Employee& Employee::operator=(const Employee& e){
  cout << "Inside operator = of Employee" << endl;
  _name = e._name;
  _ssn = e._ssn;
  return *this;
}

std::ostream& operator<<(std::ostream& stream, const Employee& e){
  return stream << "Employee details, name " << e._name << ", ssn " << e._ssn << ", netPay" << e._netPay << endl;
}

void Employee::printCheck() const{

}
