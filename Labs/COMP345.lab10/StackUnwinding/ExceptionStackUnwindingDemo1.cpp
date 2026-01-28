#include <iostream>
using namespace std;

char classToThrow;

class D {
public:
	D(){
		cout << "Constructor D()" << endl;
		if (classToThrow == 'D') 
			throw classToThrow;
	}
	~D(){ cout << "Destructor ~D()" << endl; }
	void* operator new(size_t size) {
		void* storage = malloc(size);
		cout << "D::new\n";
		return storage;
	}
	void operator delete(void* p) {
		cout << "D::delete\n";
		free(p);
	}
}; 

class C {
public:
	C(){ 
		cout << "Constructor C()" << endl;
		if (classToThrow == 'C') 
			throw classToThrow;
	}
	~C(){ cout << "Destructor ~C()" << endl; }
	void* operator new(size_t size) {
		void* storage = malloc(size);
		cout << "C::new\n";
		return storage;
	}
	void operator delete(void* p) {
		cout << "C::delete\n";
		free(p);
	}
};

class B {
public:
	B(){ 
		cout << "Constructor B()" << endl;  
		if (classToThrow == 'B') 
			throw classToThrow;
	}
	~B(){ cout << "Destructor ~B()" << endl; }
	void* operator new(size_t size) {
		void* storage = malloc(size);
		cout << "B::new\n";
		return storage;
	}
	void operator delete(void* p) {
		cout << "B::delete\n";
		free(p);
	}
};

class A : public B {
public:
	C mC1;
	D mD2;
	A() {
		cout << "Constructor A()" << endl; 
		if (classToThrow == 'A') 
			throw classToThrow;
	}
	~A(){ cout << "Destructor ~A()" << endl; }
	void* operator new(size_t size) {
		void* storage = malloc(size);
		cout << "A::new\n";
		return storage;
	}
	void operator delete(void* p) {
		cout << "A::delete\n";
		free(p);
	}
};

int main(){
	while (true){
		cout << "Enter the class name to throw an exception (A,B,C,D or X for none): ";
		cin >> classToThrow;
		D* a1 = new D();
		try{
			B* b1 = new B();
			A* a2 = new A();
			A va = A();
			delete b1;
			delete a2;
		}
		catch (char c){
			cout << "catching " << c << endl;
		}
	}
	system("PAUSE");
	return EXIT_SUCCESS;
}