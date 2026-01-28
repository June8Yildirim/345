//! @file 
//! @brief Implementation file for DerivedRectangleFromAbstractGeometricObject.h
//!

#include "DerivedRectangleFromAbstractGeometricObject.h"

//! Construct a default retangle object with width and height set to 1
//! @param 
//! @return new Rectangle object
//!
Rectangle::Rectangle() {
	width = 1;
	height = 1;
}

//! Construct a rectangle object with specified width and height
//! @param width : width of the new rectangle
//! @param height : height of the new rectangle
//! @return newRectangle object
//!
Rectangle::Rectangle(double width, double height) {
	setWidth(width);
	setHeight(height);
}

//! Construct a rectangle object with width, height, color, filled
//! @param width : width of the new rectangle
//! @param height : height of the new rectangle
//! @param color : color of the new rectangle
//! @param filled : whether the rectangle is filled or not
//! @return new Rectangle object
//!
Rectangle::Rectangle(double width, double height, const string& color, bool filled) {
	setWidth(width);
	setHeight(height);
	setColor(color);
	setFilled(filled);
}

//! Accessor for width 
//! @param 
//! @return width of the rectangle
//!
double Rectangle::getWidth() const {
	return width;
}

//! Mutator for radius
//! @param width : new width for the rectangle
//! @return void
//!
void Rectangle::setWidth(double width) {
	this->width = (width >= 0) ? width : 0;
}

//! Accessor for height
//! @param 
//! @return height of the rectangle
//!
double Rectangle::getHeight() const {
	return height;
}

//! Mutator for height
//! @param height : new height for the rectangle
//! @return void
//!
void Rectangle::setHeight(double height) {
	this->height = (height >= 0) ? height : 0;
}

//! Return the area of the rectangle
//! @param
//! @return area of the rectangle
//!
double Rectangle::getArea() const {
	return width * height;
}

//! Return the perimeter of the rectangle
//! @param
//! @return perimeter of the rectangle
//!
double Rectangle::getPerimeter() const {
	return 2 * (width + height);
}
