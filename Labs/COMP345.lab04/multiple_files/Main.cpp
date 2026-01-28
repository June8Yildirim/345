// from: Savitch. Absolute C++. 

#include<iostream>
#include "DayOfYear.h"
using namespace std;

int main()
{
	DayOfYear canadianDay;
	canadianDay.set(7, 1);
	canadianDay.output();

	DayOfYear *ptrNewYear;
	ptrNewYear = new DayOfYear();
	ptrNewYear->set(1, 1);
	ptrNewYear->output();

	const DayOfYear newYear(1, 1);
	newYear.output();

	DayOfYear customDayOfYear;
	customDayOfYear.input();
	customDayOfYear.output();

	cout << "Compared to canadian day " << customDayOfYear.compareAnotherDayOfYear(canadianDay) << endl;
}