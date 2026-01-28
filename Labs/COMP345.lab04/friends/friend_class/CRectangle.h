#pragma once
#include "CSquare.h"
class CSquare;

class CRectangle
{
private:
	int width;
	int height;

public:
	int area() const
	{
		return width * height;
	}

	void setValues(int w, int h);

	// Non member function declared as friend to access private members of CRectangle
	friend CRectangle dupAndDouble(CRectangle other);

	void convert(CSquare sqr);
};