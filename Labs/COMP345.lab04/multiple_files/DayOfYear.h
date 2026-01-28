// from : Savitch. Absolute C++. 

#pragma once

class DayOfYear
{
public:
	DayOfYear();
	DayOfYear(int m, int d);
	void input();
	void output() const;
	void set(int newMonth, int newDay);
	int getMonthNumber() const;
	int getDay() const;

	/*
	 * Return 0 if day of the year represented by obj1 and obj2 are equal
	 * Return negative number if day of the year represented by obj1 is lesser than obj2
	 * Return positive number if day of the year represented by obj1 is greater than obj2
	 */
	int compareAnotherDayOfYear(const DayOfYear other) const;

private:
	int month;
	int day;
};

// Inline functions' definitions must be found in the compilation unit in which they are used. 
// To achieve that, we may put their definition in the header file in which they are declared.  
// Try putting this definition in DayOfYear.cpp, remove it from here, and recompile. You will 
// get an error. 
// 
// In other words, inline functions have internal linkage. If you want to make an inline function 
// accessible to other compilation units, they must include the definition of the inline function. 
inline int DayOfYear::compareAnotherDayOfYear(const DayOfYear other) const{
	int returnVal = getMonthNumber() - other.getMonthNumber();
	returnVal = returnVal == 0 ? getDay() - other.getDay() : returnVal;
	return returnVal;
}