#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void showState(const fstream& stream)
{
	cout << "Stream status: " << endl;
	cout << "  eof(): " << stream.eof() << endl;
	cout << "  fail(): " << stream.fail() << endl;
	cout << "  bad(): " << stream.bad() << endl;
	cout << "  good(): " << stream.good() << endl;
}

int main()
{
	fstream inout;
	inout.open("temp.txt", ios::out);
	inout << "Dallas";
	cout << "Normal operation (no errors)" << endl;
	showState(inout);
	inout.close();

	inout.open("temp.txt", ios::in);

	string city;
	inout >> city;
	cout << "End of file (no errors)" << endl;
	showState(inout);

	inout.close();

	inout >> city;
	cout << "Bad operation (errors)" << endl;
	showState(inout);

	return 0;
}
