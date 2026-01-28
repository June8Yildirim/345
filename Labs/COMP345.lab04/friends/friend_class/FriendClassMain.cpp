#include<iostream>

#include "CRectangle.h"
using namespace std;

int main(){
	CRectangle rectA, rectB;
	rectA.setValues(10, 10);

	rectB = dupAndDouble(rectA);
	cout << "rectA area " << rectA.area() << endl;
	cout << "rectB area " << rectB.area() << endl;

	CSquare sqr;
	sqr.setSide(10);

	CRectangle rectC;
	rectC.convert(sqr);

	cout << "rectC area " << rectC.area() << endl;

	return 0;
}
