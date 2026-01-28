#include <string>
#include <iostream>
using namespace std;

class CShape {
protected:
	double area;
	string name;
public:
	CShape() : name("anonymous") {
	}
	CShape(string newName) : name(newName) {
	}
	string getName() {
		return name;
	}
	// This is a virtual method, which makes the objects of this class potentially 
	// subject to reference semantics and polymorphic member function calls. 
	virtual void print() {
		cout << "Shape:" << name << endl;
		cout << "Area: " << getArea() << endl;
	}
	// This is a pure virtual function, which makes this class an abstract class
	// and forces its subclasses to provide an implementation for it, or else
	// they would also be abstract classes. 
	virtual double getArea() = 0;
};

// This is an example of how a free function (in this case an operator) can make use 
// of polymorphic calls. 
bool operator < (CShape& s1, CShape& s2) {
	// The line below is an example of a polymorphic call. 
	// (1) The parameters to the operator are of type *reference* to CShape (i.e. the base class type). 
	// (2) As getArea() is declared as a virtual function in the base class.
	// This is triggering reference semantics on the operations done on the parameter objects. 
	// Thus, the calls to getArea() below are polymorphic calls. 
	//
	// If the parameters would be passed by value instead of by reference, then value semantics would be used, 
	// and the calls to getArea() would not be polymorphic. 
	return (s1.getArea() < s2.getArea());
}

class CTriangle : public CShape {
	double height;
	double base;
public:
	CTriangle() : CShape(), base(1), height(1) {
	}
	CTriangle(string n, double b, double h) : CShape(n), base(b), height(h) {
	}
	void setHeight(double h) {
		height = h;
	}
	void setBase(double b) {
		base = b;
	}
	double getHeight() const {
		return height;
	}
	double getBase() const {
		return base;
	}
	double getArea() {
		area = base / 2 * height;
		return area;
	}
	void print() {
		CShape::print();
		cout << "Triangle:" << endl;
		cout << "Height: " << height << " Base: " << base << endl;
	}
};

class CRectangle : public CShape {
	double length;
	double width;
public:
	CRectangle() : CShape(), length(1), width(1) {
	}
	CRectangle(string n, double l, double w) : CShape(n), length(l), width(w) {
	}
	void setLength(double l) {
		length = l;
	}
	void setWidth(double w) {
		width = w;
	}
	double getLength() const {
		return length;
	}
	double getWidth() const {
		return width;
	}
	double getArea() {
		area = length * width;
		return area;
	}
	void print() {
		CShape::print();
		cout << "Rectangle:" << endl;
		cout << "Height: " << length << " Width: " << width << endl;
	}
};

class CCircle : public CShape {
	double radius;
public:
	CCircle() : CShape(), radius(1) {
	};
	CCircle(string n, double r) : CShape(n), radius(r) {
	};
	void setRadius(double r) {
		radius = r;
	}
	double getRadius() const {
		return radius;
	}
	double getArea() {
		area = 3.14159265 * radius * radius;
		return area;
	}
	void print() {
		CShape::print();
		cout << "Circle:" << endl;
		cout << "Radius: " << radius << endl;
	}
};

// This shows that a free function can use reference semantics and dynamic_cast to 
// access the subtype-specific members of a subclass. This works, but is not as 
// elegant/flexible/maintainable compared to calls to polymorphic member functions.  
void displayCShapeDynamicCastDemo(CShape& shape) {
	// Here we use dynamic_cast to downcast the CShape object into its subclass type. 
	// Depending on what subtype the passed object is, the function will output the values of its data members. 
	CShape* p = &shape;
	CCircle* p1 = dynamic_cast<CCircle*>(p);
	CRectangle* p2 = dynamic_cast<CRectangle*>(p);
	CTriangle* p3 = dynamic_cast<CTriangle*>(p);

	if (p1 != NULL) {
		cout << "Circle's area is " << p1->getArea() << endl;
		cout << "Circle's radius is " << p1->getRadius() << endl;
	}
	if (p2 != NULL) {
		cout << "Rectangle's area is " << p2->getArea() << endl;
		cout << "Rectangle's width is " << p2->getWidth() << endl;
		cout << "Rectangle's height is " << p2->getLength() << endl;
	}
	if (p3 != NULL) {
		cout << "Triangle's area is " << p3->getArea() << endl;
		cout << "Triangle's width is " << p3->getHeight() << endl;
		cout << "Triangle's height is " << p3->getBase() << endl;
	}
	// Here, if new subclasses of CShape are added, we need to remember to add new code for each of them. 
	// Not very flexible code. 
}

// This free function makes full use of polymorphism by using references semantics and then 
// making a call to a polymorphic function to automatically trigger the subtype-specific behavior. 
void displayCShapePolymorphismDemo(CShape& shape) {
	shape.print();
}

void main() {
	CRectangle* shapeRect = new CRectangle("shapeRect", 16.8, 8.8);
	CCircle* shapeCircle = new CCircle("shapeCircle", 13.8);
	CTriangle* shapeTriangle = new CTriangle("shapeTriangle", 2.5, 3.8);
	CShape* shapes[] = { shapeRect, shapeCircle, shapeTriangle };
	for (int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i++) {
		// The following two calls are polymorphic calls
		shapes[i]->getArea();
		shapes[i]->print();
		if (i > 0)
			cout << "Shape[" << i << "] area (" << shapes[i]->getArea()
			<< ") less than Shape[" << i - 1 << "] area ("
			<< shapes[i - 1]->getArea() << ") : "
			<< (*shapes[i] < *shapes[i - 1]) << endl;
	}
	cout << "Use of dynamic_cast to access subtype-specific members: " << endl;
	for (int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i++) {
		displayCShapeDynamicCastDemo(*shapes[i]);
	}
	cout << "Polymorphic calls by a free function using reference semantics: " << endl;
	for (int i = 0; i < sizeof(shapes) / sizeof(shapes[0]); i++) {
		displayCShapePolymorphismDemo(*shapes[i]);
	}
	int i;  std::cin >> i;
	delete shapeRect;
	delete shapeCircle;
	delete shapeTriangle;
}

