#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream output;
	// Create/open a file
	output.open("scores.txt");
	// Write two lines
	output << "John" << " " << "T" << " " << "Smith" << " " << 90 << endl;
	output << "Eric" << " " << "K" << " " << "Jones" << " " << 85 << endl;
	// Close the file
	output.close();
	cout << "Done" << endl;

	string firstName, lastName; char mi; int score;
	// open file in read mode
	ifstream input("scores.txt");
	// Read line
	input >> firstName >> mi >> lastName >> score;
	// until file is empty: print line, then read other line 
	while (!input.eof()) {
		cout << firstName << " " << mi << " " << lastName << " " << score << endl;
		input >> firstName >> mi >> lastName >> score;
	}
	input.close();
	cout << "Done" << endl;

	return 0;
}