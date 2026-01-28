//! @file 
//! @brief Header file for DerivedCircleFromAbstractGeometricObject.cpp
//!

#ifndef CIRCLE_H
#define CIRCLE_H
#include "AbstractGeometricObject.h"

//! Rectangle class that is a subclass of the GeometricObject class
//! It needs to be a subclass of CObject in order to be serializable, and implement
//! a Serialize() member function
class Circle : public GeometricObject
{
public:
  Circle();
  Circle(double);
  Circle(double radius, const string& color, bool filled);
  double getRadius() const;
  void setRadius(double);
  double getArea() const;
  double getPerimeter() const;
  double getDiameter() const;
  virtual void Serialize(CArchive& ar);
  friend ostream& operator<<(ostream&, const Circle&);

private:
  double radius;

protected:
	DECLARE_SERIAL(Circle);
};  


#endif
