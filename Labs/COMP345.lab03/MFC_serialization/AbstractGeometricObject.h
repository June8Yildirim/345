//! @file 
//! @brief Header file for AbstractGeometricObject.cpp
//!

#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H
#include <string>
#include <afx.h>

using namespace std;

//! An abstract class for geometric objects that needs to be dervied with a concrete class.
//! It needs to be a subclass of CObject in order to be serializable, and implement
//! a Serialize() member function
class GeometricObject : public CObject
{
public:
  string getColor() const;
  void setColor(const string& color);
  bool isFilled() const;
  void setFilled(bool filled);
  //! Pure virtual function to compute the area 
  //! @param 
  //! @return area of the GeometricObject, computed differently depending on the type of the object in question
  virtual double getArea() const = 0;  
  //! Pure virtual function to compute the perimeter 
  //! @param 
  //! @return perimeter of the GeometricObject, computed differently depending on the type of the object in question
  virtual double getPerimeter() const = 0;
  virtual void Serialize(CArchive& ar);

private:
	//! In order to be serializable, classes need to include only data members
	//! that are either primitive types or subclasses of CObject
	CString color;
	bool filled;

protected:
	GeometricObject();
	GeometricObject(const string& color, bool filled);
	// DO NOT use the DECLARE_SERIAL on abstract classes, as it expects 
	// that an object can be created for that class
	//DECLARE_SERIAL(GeometricObject);
}; 

#endif
