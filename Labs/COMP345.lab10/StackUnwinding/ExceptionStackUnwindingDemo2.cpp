#include <string>
#include <iostream>
using namespace std;

class MyException{};

class Dummy {
  public:
	Dummy(string s) : dummyName(s) { 
		cout << "Created Dummy: " << dummyName << endl; 
	}
	Dummy(const Dummy& other) : dummyName(other.dummyName){ 
		cout << "Copy created Dummy: " << dummyName << endl; 
	}
	~Dummy(){ 
		cout << "Destroyed Dummy: " << dummyName << endl; 
	}
	string dummyName;
};

void fC(Dummy d){
	cout << "Entering Function fC" << endl;
	d.dummyName = "dummy_fC";
	throw MyException();
	cout << "Exiting Function fC" << endl;
}

void fB(Dummy& d){
	cout << "Entering Function fB" << endl;
	d.dummyName = "dummy_fB";
	fC(d);
	cout << "Exiting Function fB" << endl;
}

void fA(Dummy& d){
	cout << "Entering Function fA" << endl;
	Dummy stackDummy("Dummy on Stack");
	Dummy* heapDummy = new Dummy("Dummy on Heap"); //Not exception safe!!!
	d.dummyName = "dummy_fA";
	fB(d);
	delete heapDummy; 
	cout << "Exiting Function fA" << endl;
}


int main()
{
	cout << "Entering main" << endl;
	try{
		Dummy d("dummy_main");
		fA(d);
	}
	catch (MyException& e){
		cout << "Caught an exception of type: " << typeid(e).name() << endl;
	}
	cout << "Exiting main." << endl;
	char c; cin >> c;
}