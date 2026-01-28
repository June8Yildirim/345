//! @file 
//! @brief Implementation file for DerivedJRectangleFromAbstractGeometricObject.h
//!

#include "DerivedRectangleFromAbstractGeometricObject.h"
#include <iostream>

//Signify to MFC serialization that objects of this class are serializable
//Parameter 1 : Name of the class
//Parameter 2 : Name of the first non-abstract class up on the inheritance chain
//Parameter 3 : Class schema version name. Must use same positive integer value across classes.
IMPLEMENT_SERIAL(JRectangle, CObject, 1)

//! Construct a default retangle object with width and height set to 1
//! @param 
//! @return new JRectangle object
//!
JRectangle::JRectangle()
{
  width = 1;
  height = 1;
}

//! Construct a JRectangle object with specified width and height
//! @param width : width of the new JRectangle
//! @param height : height of the new JRectangle
//! @return newJRectangle object
//!
JRectangle::JRectangle(double width, double height)
{
  setWidth(width);
  setHeight(height);
}

//! Construct a JRectangle object with width, height, color, filled
//! @param width : width of the new JRectangle
//! @param height : height of the new JRectangle
//! @param color : color of the new JRectangle
//! @param filled : whether the JRectangle is filled or not
//! @return new JRectangle object
//!
JRectangle::JRectangle(double width, double height, 
	const string& color, bool filled) : GeometricObject(color, filled)
{
  setWidth(width);
  setHeight(height);
}

//! Accessor for width 
//! @param 
//! @return width of the JRectangle
//!
double JRectangle::getWidth() const
{
  return width;
}

//! Mutator for radius
//! @param width : new width for the JRectangle
//! @return void
//!
void JRectangle::setWidth(double width)
{
  this->width = (width >= 0) ? width : 0;
}

//! Accessor for height
//! @param 
//! @return height of the JRectangle
//!
double JRectangle::getHeight() const
{
  return height;
}

//! Mutator for height
//! @param height : new height for the JRectangle
//! @return void
//!
void JRectangle::setHeight(double height)
{
  this->height = (height >= 0) ? height : 0;
}

//! Return the area of the JRectangle
//! @param
//! @return area of the JRectangle
//!
double JRectangle::getArea() const
{
  return width * height;
}

//! Return the perimeter of the JRectangle
//! @param
//! @return perimeter of the JRectangle
//!
double JRectangle::getPerimeter() const
{
  return 2 * (width + height);
}

//! free operator << to output a JRectangle object to an output stream
//! @param out: output stream to output to
//! @param rectangle: JRectangle object to output
//! @return a reference to the stream, to enable a chain of such operations
//!
ostream& operator<<(ostream& out, const JRectangle& rectangle)
{
	out << "Rectangle Object: \nwidth: " << rectangle.getWidth() << endl;
	out << "height: " << rectangle.getHeight() << endl;
	return out;
}

//! Serialize a Rectangle to/from a MFC CArchive
//! @param ar : CArchive object to serialize to/from
//! @ return none
//!
void JRectangle::Serialize(CArchive& ar)
{
	// Always call base class Serialize().
	GeometricObject::Serialize(ar);	

	// Serialize dynamic members and other raw data 
	if (ar.IsStoring())
	{
		ar << width;
		ar << height;
	}
	else
	{
		ar >> width;
		ar >> height;
	}
}
