//! @file 
//! @brief Main driver file for the console application.
//!

#include "AbstractGeometricObject.h"
#include "DerivedCircleFromAbstractGeometricObject.h"
#include "DerivedRectangleFromAbstractGeometricObject.h"
#include <iostream>
using namespace std;

//! A free function for comparing the areas of two geometric objects
//!
bool equalArea(const GeometricObject& g1, const GeometricObject& g2) {
	return g1.getArea() == g2.getArea();
}

//! A free function for displaying a geometric object
//!
void displayGeometricObject(const GeometricObject& g) {
	cout << "The area is " << g.getArea() << endl;
	cout << "The perimeter is " << g.getPerimeter() << endl;
}

//! A free function for displaying a geometric object that demonstrates 
//! the use of dynamic_cast to cast the GenericObject in both a Circle 
//! and a Rectangle. Whichever is successful will be the one displayed. 
//!
void displayGeometricObjectDynamicCastDemo(GeometricObject& g) {
	cout << "The area is " << g.getArea() << endl;
	cout << "The perimeter is " << g.getPerimeter() << endl;

	GeometricObject* p = &g;
	Circle* p1 = dynamic_cast<Circle*>(p);
	Rectangle* p2 = dynamic_cast<Rectangle*>(p);

	if (p1 != NULL) {
		cout << "The radius is " << p1->getRadius() << endl;
		cout << "The diameter is " << p1->getDiameter() << endl;
	}

	if (p2 != NULL) {
		cout << "The width is " << p2->getWidth() << endl;
		cout << "The height is " << p2->getHeight() << endl;
	}
}

//! main() function. Entry point of the program
//!
int main() {
	Circle circle(5);
	Rectangle rectangle(5, 3);

	cout << "Circle info: " << endl;
	displayGeometricObject(circle);

	cout << "\nRectangle info: " << endl;
	displayGeometricObject(rectangle);

	cout << "\nThe two objects have the same area? " <<
		(equalArea(circle, rectangle) ? "Yes" : "No") << endl;

	cout << "\nCircle info: " << endl;
	displayGeometricObjectDynamicCastDemo(circle);

	cout << "\nRectangle info: " << endl;
	displayGeometricObjectDynamicCastDemo(rectangle);

	cout << "\nPress any key to stop..." << endl;  char c; cin.get(c);

	return 0;
}
