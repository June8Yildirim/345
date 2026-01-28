//! @file 
//! @brief Implementation file for DerivedCircleFromAbstractGeometricObject.h
//!

#include "DerivedCircleFromAbstractGeometricObject.h"
#include <iostream>
using namespace std;

//! Signify to MFC serialization that objects of this class are serializable
//! Parameter 1 : Name of the class
//! Parameter 2 : Name of the first non-abstract class up on the inheritance chain
//! Parameter 3 : Class schema version name. Must use same positive integer value across classes.
IMPLEMENT_SERIAL(Circle, CObject, 1)

//! Construct a default circle object with a radius of 1
//! @param
//! @return new Circle object
//!
Circle::Circle()
{
  radius = 1;
}

//! Construct a circle object with specified radius
//! @param radius : radius of the circle
//! @return new Circle object
//!
Circle::Circle(double radius)
{
  setRadius(radius);
}

//! Construct a circle object with specified radius, color, filled
//! @param radius : radius of the circle
//! @param color : color of the circle
//! @param filled : whether the circle is filled or not
//! @return new Circle object
//!
Circle::Circle(double radius, const string& color, bool filled) : GeometricObject(color, filled)
{
  setRadius(radius);
  setColor(color);
  setFilled(filled);
}

//! Accessor for radius
//! @param 
//! @return value of radius
//!
double Circle::getRadius() const
{
  return radius;
}

//! Mutator for radius
//! @param radius : new value for radius
//! @return void
//!
void Circle::setRadius(double radius)
{
  this->radius = (radius >= 0) ? radius : 0;
}

//! Return the area of the circle
//! @param 
//! @return area of the circle
//!
double Circle::getArea() const
{
  return radius * radius * 3.14159;
}

//! Return the perimeter of the circle
//! @param 
//! @return permeter of the circle
//!
double Circle::getPerimeter() const
{
  return 2 * radius * 3.14159;
}

//! Return the diameter of the circle
//! @param 
//! @return diameter of the circle
//!
double Circle::getDiameter() const
{
  return 2 * radius;
}

//! Serialize a Circle to/from a MFC CArchive
//! @param ar : CArchive object to serialize to/from
//! @ return none
//!
void Circle::Serialize(CArchive& ar)
{
	// Always call base class Serialize().
	GeometricObject::Serialize(ar);

	// Serialize dynamic members and other raw data 
	if (ar.IsStoring())
	{
		ar << radius;
	}
	else
	{
		ar >> radius; 
	}
}

//! free operator << to output a Circle object to an output stream
//! @param out: output stream to output to
//! @param circle: circle object to output
//! @return a reference to the stream, to enable a chain of such operations
//!
ostream& operator<<(ostream& out, const Circle& circle)
{
	out << "Circle Object: \nradius: " << circle.getRadius() << endl;;
	return out;
}