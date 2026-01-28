#include <iostream>
#include<string>
using namespace std;

int main(){
	// Here we read integers until cin is faulty. 
	// If a non-integer is entered (making cin faulty), exit the loop.
	cout << "reading integers: " << endl;
	int i;
	cin >> i;
	while (cin) {
		cout << "i = " << i << endl;
		cin >> i;
	}

	cout << "oops! invalid integer... clearing cin" << endl;
	// clear the faulty bit in the cin stream
	cin.clear();

	// Here we read characters until cin is faulty.
	// Note: this will loop forever, as everything that the user can enter 
	// is a character. Once the user enters input (ending with a carriage return) 
	// all charachers in the stream are read and printed individually
	cout << "reading characters until 'z'" << endl;
	char c;
	// Here, cin.get() first get a user input 
	// (i.e. a sequence of characters ending with a carriage return).  
	// These all get into the stream, then get() gets the frist character 
	// from the stream. All the others are left there and are read until 
	// the stream is empty, at which point get() prompts the user for
	// another input. 
	cin.get(c);
	while (cin) {
		cout << "c = " << c << endl;
		cin.get(c);
		if (c == 'z') break; 
	}

	cout << "reading strings until \"bye\"" << endl;
	string str; 
	cin >> str;
	while (cin) {
		cout << "str = " << str << endl;
		cin >> str; 
		if (str.compare("bye") == 0) break;
	}

	cout << "reading strings until \"end\"" << endl;
	string str2;
	cin >> str2;
	while (cin) {
		cout << "str2 = " << str2 << endl;
		// here we use the getline() function from the string library
		// its first parameter is an input stream
		getline(cin,str2);
		if (str2.compare("end") == 0) break;
	}


	return 0;
}