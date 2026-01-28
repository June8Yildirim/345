//! @file 
//! @brief Implementation file for AbstractGeometricObject.h
//!

#include "AbstractGeometricObject.h"
// DO NOT use the IMPLEMENT_SERIAL on abstract classes, as it expects 
// that an object can be created for that class
// IMPLEMENT_SERIAL(GeometricObject, CObject, 1)

//! Default constructor of GeometricObject class <br>
//! sets color to white and filled to false
//! @param 
//! @return new GeometricObject
//!
GeometricObject::GeometricObject()
{
  color = "white";
  filled = false;
}

//! Constructor of GeometricObject class
//! @param color : new value for color
//! @param filled : new value for filled
//! @return new GeometricObject
//!
GeometricObject::GeometricObject(const string& color, bool filled)
{
  setColor(color);
  setFilled(filled);
}

//! Accessor for GeometricObject's color data member
//! @param
//! @return  value of color
//!
std::string GeometricObject::getColor() const
{
	// As the color data member is a CString to enable serialization
	// and we want the interface of the object to expose it as a "string" type
	// we need to convert it when getColor() is called to access color
	CT2CA pszConvertedAnsiString(color.GetString());

	std::string strStd(pszConvertedAnsiString);
	return strStd;
}

//! Mutator for GeometricObject's color data member
//! @param color : new value for color
//! @return void
//!
void GeometricObject::setColor(const string& color)
{
	// As the color data member is a CString to enable serialization
	// and we want the interface of the object to expose it as a "string" type
	// we need to convert it when setColor() is called to modifiy color
	this->color = color.c_str();
}

//! Accessor for GeometricObject's filled data member
//! @param
//! @return value of filled
//!
bool GeometricObject::isFilled() const
{
  return filled;
}

//! Mutator for GeometricObject's filled data member
//! @param filled : new value for filled
//! @return void
//!
void GeometricObject::setFilled(bool filled)
{
  this->filled = filled;
}

//! Serialize a GeometricObject to/from a MFC CArchive
//! @param ar : CArchive object to serialize to/from
//! @ return none
//!
void GeometricObject::Serialize(CArchive& ar)
{
	// Always call base class Serialize().
	CObject::Serialize(ar);		

	// Serialize dynamic members and other raw data 
	if (ar.IsStoring()) //if the CArchive is set to write
	{
		ar << color;    // CString is a subclass of CObject
		ar << filled;   // bool is a primitive type
	}
	else                // if the CArchive is set to read
	{	
		ar >> color;    // CString is a subclass of CObject
		ar >> filled;   // bool is a primitive type
	}
}

