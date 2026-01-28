#include<iostream>

#include "CRectangle.h"

using namespace std;

void CRectangle::setValues(int w, int h)
{
	this->width = w;
	this->height = h;
}

CRectangle dupAndDouble(CRectangle other)
{
	CRectangle copy;
	copy.width = other.width * 2;
	copy.height = other.height * 2;

	return copy;
}

void CRectangle::convert(CSquare sqr)
{
	this->width = sqr.side;
	this->height = sqr.side;
}
