#include <string>
#include <list>
#include <iostream>
using namespace std; 

class Instructor {
public: 
    list<string> courseLoad;
    int EmployeeID;
    string name;
    string address;
};
class Student {
public:
    list<string> registeredCourses;
    int studentID;
    string name;
    string address;
};
class TeachingAssistant : public Student, public Instructor {};

int main() {
    TeachingAssistant ta; 
    ta.Instructor::name = "Joey";
    cout << ta.Instructor::name << endl;
}