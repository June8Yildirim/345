// from : Savitch. Absolute C++. 

#pragma once
// This file uses the type "DayOfYear, so it needs to include the file that contains its declaration. 
#include "DayOfYear.h"

class Holiday
{
public:
	Holiday();
	Holiday(int month, int day, bool enforcement);
private:
	DayOfYear doy;
	bool parkingEnforcement;
};