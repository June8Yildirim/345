// From Walter Savitch' book resources - Absolute C++

//This is the application file: timedemo.cpp. This program.
//demonstrates hiding the helping functions in an unnamed namespace.

#include <iostream>
// Here we dont use "using namespace std" because we use fully qualified names 
// below (e.g. DTimeSavitch::DigitalTime). 
#include "dtime.h"

// Declare a free function readHour() in the global scope. If readHour() would not have been defined 
// in the unnamed namespace of the dtime.cpp file, it would also have been in the global scope, 
// creating a redefinition/name clash. As readHour() was defined in the unnamed namespace in the 
// dtime.cpp file, it is only accessible from within the dtime.cpp compilation unit itself, 
// and thus the name clash does not occur here. 
void readHour(int& theHour);

int main( ){
    // Here we use fully qualified names. 
    // This is why we dont have to use "using namespace" in the #includes above. 
    using std::cout;
    using std::cin;
    using std::endl;
    using DTimeSavitch::DigitalTime;

    int theHour;
    readHour(theHour);
    DigitalTime clock(theHour, 0), oldClock;
    oldClock = clock;
    clock.advance(15);
    if (clock == oldClock)
        cout << "Something is wrong.";
    cout << "You entered " << oldClock << endl;
    cout << "15 minutes later the time will be " << clock << endl;
    clock.advance(2, 15);
    cout << "2 hours and 15 minutes after that\n" << "the time will be " << clock << endl;
    return 0;
}

// Definition of the readHour() free function declared above.  
void readHour(int& theHour){
    using std::cout;
    using std::cin;
 
    cout << "Let's play a time game.\n"
         << "Let's pretend the hour has just changed.\n"
         << "You may write midnight as either 0 or 24,\n"
         << "but, I will always write it as 0.\n"
         << "Enter the hour as a number (0 to 24): ";
    cin >> theHour;
}