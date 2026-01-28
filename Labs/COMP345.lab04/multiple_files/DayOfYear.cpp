// from : Savitch. Absolute C++. 

#include<iostream>
#include<string>
#include "DayOfYear.h"
using namespace std;



// These are definitions for the member functions declared in DayOfYear.h
DayOfYear::DayOfYear(){
	cout << "DayOfYear.DayOfYear() no-argument constructor." << endl;
}

DayOfYear::DayOfYear(int m, int d) : month(m), day(d){
	cout << "DayOfYear().DayOfYear() month and year arguments constructor" << endl;
	// Member initialization is done in the initialization list. 
	// If we want to validate the input, we may want to call a function that does so
	// instead of relying on the initialization list to do the validation. 
	// set(m, d);
}

void DayOfYear::input(){
	cout << "Enter the month as the number : ";
	cin >> month;
	cout << "Enter the day of the month : ";
	cin >> day;

	if (month < 1 || month > 12 || day < 1 || day > 31){
		cerr << "Illegal date, program aborted!!!" << endl;
		exit(1);
	}
}

void DayOfYear::output() const{
	string strMonth;
	switch (month){
	case 1:
		strMonth = "January"; break;
	case 2:
		strMonth = "February"; break;
	case 3:
		strMonth = "March"; break;
	case 4:
		strMonth = "April"; break;
	case 5:
		strMonth = "May"; break;
	case 6:
		strMonth = "June"; break;
	case 7:
		strMonth = "July"; break;
	case 8:
		strMonth = "August"; break;
	case 9:
		strMonth = "September"; break;
	case 10:
		strMonth = "October"; break;
	case 11:
		strMonth = "November"; break;
	case 12:
		strMonth = "December"; break;
	default:
		strMonth = "Error processing day of the year.";
		break;
	}
	cout << strMonth << " " << day << endl;
}

int DayOfYear::getDay() const{
	return day;
}

int DayOfYear::getMonthNumber() const{
	return month;
}

void DayOfYear::set(int newMonth, int newDay){
	if (newMonth >= 1 && newMonth <= 12){
		month = newMonth;
	}
	else{
		cout << "Invalid month. Program aborted." << endl;
		exit(1);
	}

	if (newDay >= 1 && newDay <= 31){
		day = newDay;
	}
	else{
		cout << "Invalid date. Program aborted." << endl;
		exit(1);
	}
}
