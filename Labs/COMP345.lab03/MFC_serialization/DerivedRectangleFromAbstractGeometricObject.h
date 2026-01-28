//! @file 
//! @brief Header file for DerivedJRectangleFromAbstractGeometricObject.cpp
//!

#ifndef JRectangle_H
#define JRectangle_H
#include "AbstractGeometricObject.h"

//! Rectangle class that is a subclass of the GeometricObject class
//! It needs to be a subclass of CObject in order to be serializable, and implement
//! a Serialize() member function
class JRectangle : public GeometricObject 
{
public:
  JRectangle();
  JRectangle(double width, double height);
  JRectangle(double width, double height, const string& color, bool filled);
  double getWidth() const;
  void setWidth(double);
  double getHeight() const;
  void setHeight(double);
  double getArea() const;
  double getPerimeter() const;
  virtual void Serialize(CArchive& ar);
  friend ostream& operator<<(ostream&, const JRectangle&);

private:
  double width;
  double height;

protected:
	DECLARE_SERIAL(JRectangle);
};


#endif
