//! @file 
//! @brief Header file for AbstractGeometricObject.cpp
//!

#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
using namespace std;

// An abstract class for geometric objects that needs to be dervied with a concrete class 
//
class GeometricObject {
protected:
	GeometricObject();
	GeometricObject(const string& color, bool filled);

public:
	string getColor() const;
	void setColor(const string& color);
	bool isFilled() const;
	void setFilled(bool filled);
	string toString() const;
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;

private:
	string color;
	bool filled;
};

#endif
