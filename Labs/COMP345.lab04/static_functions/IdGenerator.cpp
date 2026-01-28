#include<iostream>
using namespace std;

class IDGenerator{
private:
  static int s_nextId ;
public:
  static int getNextId(){
    return s_nextId++;
  }
};

// static members initialized in the global scope
int IDGenerator::s_nextId = 1;

int main(){
  for (int i = 0; i < 5; i++)
    cout << "The next ID is " << IDGenerator::getNextId() << endl;
  
  return 0;
}
