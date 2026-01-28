#include <string>
#include <list>
#include <iostream>
using namespace std; 

class Person {
public:
    string name;
    string address;
};

class Instructor : public Person {
public: 
    list<string> courseLoad;
    int EmployeeID;
};
class Student : public Person {
public:
    list<string> registeredCourses;
    int studentID;
};
class TeachingAssistant : public Student, public Instructor {};



int main() {
    TeachingAssistant ta; 
    ta.Instructor::name = "Mr. Nice Guy";
    cout << ta.Instructor::name << endl;
    // There are two separate name & address fields!
    // We shall see how to deal with that later
    cout << ta.Student::name << endl;
}