#include <string>
#include <iostream>
using namespace std;

class Pet {
public:
	string name;
	Pet() {}
	Pet(const Pet& aPet) : name(aPet.name) {
		cout << "In Pet's copy constructor" << endl;
	}
	Pet(string newName) : name(newName) {}
	virtual ~Pet() {}
	virtual void print() const {
		cout << "In Pet::print()" << endl;
		cout << "name: " << name << endl << endl;
	}
	Pet& operator= (const Pet& otherPet) {
		cout << "In Pet's assignment operator" << endl;
		name = otherPet.name;
		return *this;
	}
};

class Dog : public Pet {
public:
	string breed;
	Dog() : Pet() {}
	Dog(const Dog& aDog) : Pet(aDog), breed(aDog.breed) {
		cout << "In Dog's copy constructor" << endl;
	}
	Dog(string newName, string newBreed) : Pet(newName), breed(newBreed) {}
	virtual void print() const {
		cout << "In Dog::print(): " << endl;
		cout << "name: " << name << endl;
		cout << "breed: " << breed << endl << endl;
	}
	Dog& operator= (const Dog& otherDog) {
		cout << "In Dog's assignment operator" << endl;
		Pet::operator=(otherDog);
		breed = otherDog.breed;
		return *this;
	}
};

void referenceSemantics(const Pet& aPet) {
	// As this function receives its parameter 
	// as a reference, its original type is kept 
	// in the value the reference parameter 
	// refers to and thus can polymorphically 
	// call print(). 
	aPet.print();
}

void valueSemantics(const Pet aPet) {
	// As this function receives its parameter as value, 
	// it is copied into a Pet value, and then always 
	// calls Pet::print().
	aPet.print();
}

int main() {
	cout << "\nUsing value semantics results in the slicing problem\n";
	cout << "and is not very interesting as it does not enable polymorphism.\n\n";
	Dog vdog1("Tiny", "GreatDane");
	Pet vpet1;
	cout << "Use of Pet's copy constructor:";
	Pet vpet2(vdog1);
	cout << "Use of Pet's assignment operator:";
	vpet1 = vdog1;
	cout << "The Dog has been sliced into a Pet\n";
	cout << "due to the value semantics used in\n";
	cout << "the assignment operation.\n";
	cout << "vdog1.print() uses Dog::print():\n";
	vdog1.print();
	cout << "vpet1.print() uses Pet::print():\n";
	vpet1.print();
	cout << "vpet2.print() uses Pet::print():\n";
	vpet2.print();
	cout << endl << "Passing a Dog received as a Pet using value semantics:" << endl;
	valueSemantics(vdog1);

	cout << "\nUsing reference semantics does not result in the slicing\n";
	cout << "problem and it allows to use polymorphism through late binding.\n\n";
	Dog* pdog1 = new Dog("Tiny", "GreatDane");
	Pet* ppet1 = new Pet;
	cout << "Use of Dog and Pet's copy constructors:\n";
	Pet* ppet2 = new Dog(*pdog1);
	cout << "Use of Pet's copy constructor:\n";
	Pet* ppet3 = new Pet(*pdog1);
	cout << "ppet1 = pdog1 does not use ";
	cout << "Pet`s assignment operator\n";
	ppet1 = pdog1;
	cout << "pdog1.print() uses Dog::print():\n";
	pdog1->print();
	cout << "ppet1.print() uses Dog::print():\n";
	ppet1->print();
	cout << "ppet2.print() uses Dog::print():\n";
	ppet2->print();
	cout << "ppet3.print() uses Pet::print():\n";
	ppet3->print();
	cout << "Passing a Dog received as a Pet using";
	cout << " reference semantics" << endl;
	referenceSemantics(vdog1);

	int i; cin >> i;
}
