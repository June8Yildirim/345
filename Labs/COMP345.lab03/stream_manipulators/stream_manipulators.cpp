#include <iostream>  // for cin,cout,fixed,showpoint,setw()
#include <iomanip>   // for setprecision()
#include <string>    // for to_string()
using namespace std;

int main() {
	double price = 78.5;
	cout << "The price is $" << price << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "The price is $" << price << endl;

	string priceheader = "The price is ($): ";
	cout << "1234567890123456789012345678901234567890" << endl;
	// justify further output to the left
	cout << left; 
	// print priceheader, adding spaces up to 20 characters wide
	cout << setw(20) << priceheader;
	// justify further output to the right
	cout << right; 
	// print price, adding spaces up to 10 character wide (right justified)
	cout << setw(10) << price << endl; 

	// Tricky cases follow!

	string priceheader2 = "The price is: ";
	cout << "1234567890123456789012345678901234567890" << endl;
	cout << left;
	// Note: setw() applies only to the next element sent to the stream, 
	// in this case, priceheader. Thus "($)" comes after the 20 characters
	// set by setw(20) for outputting priceheader. 
	cout << setw(20) << priceheader << "($)";
	cout << right;
	cout << setw(10) << price << endl;

	cout << "1234567890123456789012345678901234567890" << endl;
	cout << left;
	cout << setw(20) << priceheader;
	cout << right;
	// Note: Here we use the + operator to concatenate $ with price, 
	// then setw(10) on the concatenated string. 
	// This prints 78.5000 as the price, as setprecision applies to 
	// floating point numbers, but the price has been converted to a string. 
	cout << setw(10) << "$"+to_string(price) << endl;

	return 0;
}