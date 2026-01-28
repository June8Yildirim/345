#include <string>
#include <list>
#include <iostream>
using namespace std; 

class Person {
public:
    string name;
    string address;
};

class Instructor : virtual public Person {
public: 
    list<string> courseLoad;
    int EmployeeID;
};
class Student : virtual public Person {
public:
    list<string> registeredCourses;
    int studentID;
};
class TeachingAssistant : public Student, public Instructor {};

int main() {
    TeachingAssistant ta; 
    // here there is only one Person part, it is not ambiguous
    ta.name = "Mr. Nice Guy";
    // we may still refer to it via the two branches in the inheritance graph
    cout << ta.Student::name << endl;
    cout << ta.Instructor::name << endl;
    cout << ta.name << endl;
}