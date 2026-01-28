#include<iostream>

using namespace std;

class Foo{
public:
  Foo(){
    cout << "Foo's constructor" << endl;
  }

  ~Foo() {
    cout << "Foo's destructor" << endl;
  }
};

int main(){
  if (1){
    Foo* fooPtr = new Foo();
    //Memory leaks here, destructor not invoked
  }
  if (1){
    Foo fooVar;
    // No memory leak as variable goes out of scope
    // and destructor will be invoked.
  }
  if (1){
    Foo* fooPtr = new Foo();
    delete fooPtr;
    // delete operator will invoke the destructor. Hence no memory leak
  }
}
