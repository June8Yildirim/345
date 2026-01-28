//! @file 
//! @brief Implementation file for AbstractGeometricObject.h
//!

#include "AbstractGeometricObject.h"

//! Default constructor of GeometricObject class <br>
//! sets color to white and filled to false
//! @param 
//! @return new GeometricObject
//!
GeometricObject::GeometricObject() {
	color = "white";
	filled = false;
}

//! Constructor of GeometricObject class
//! @param color : new value for color
//! @param filled : new value for filled
//! @return new GeometricObject
//!
GeometricObject::GeometricObject(const string& color, bool filled) {
	setColor(color);
	setFilled(filled);
}

//! Accessor for GeometricObject's color data member
//! @param
//! @return  value of color
//!
string GeometricObject::getColor() const {
	return color;
}

//! Mutator for GeometricObject's color data member
//! @param color : new value for color
//! @return void
//!
void GeometricObject::setColor(const string& color) {
	this->color = color;
}

//! Accessor for GeometricObject's filled data member
//! @param
//! @return value of filled
//!
bool GeometricObject::isFilled() const {
	return filled;
}

//! Mutator for GeometricObject's filled data member
//! @param filled : new value for filled
//! @return void
//!
void GeometricObject::setFilled(bool filled) {
	this->filled = filled;
}

//! method to overload in order to enable stream output (e.g. cout)
//! @param
//! @return a string representation of the object
//!
string GeometricObject::toString() const {
	return "Geometric Object";
}
