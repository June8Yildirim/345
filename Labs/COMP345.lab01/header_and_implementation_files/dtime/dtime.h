// From Walter Savitch' book resources - Absolute C++

//This is the header file dtime.h. This is the interface for the class DigitalTime.
//Values of this type are times of day. The values are input and output in
//24 hour notation as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.

// These two lines are using precompiler directives to make sure that 
// if the file is read more than once, its content will be read only once
// to avoid redefinitions. 
#ifndef DTIME_H
#define DTIME_H

// This file refers to istream and ostream, which are defined in the iostream library. 
// Some Programming environments will include it automatically (e.g. Visual Studio 2019), 
// but most will not (e.g. g++). 
#include <iostream>
// istream and ostream are defined in the std namespace in the iostream library
using namespace std; 

class DigitalTime
{
public:
    // Constructor that initializes the time value to supplied hour and minutes values.
    DigitalTime(int theHour, int theMinute);
    // Constructor that initializes the time value to 0:00 (which is midnight).
    DigitalTime( );
    int getHour( ) const;
    int getMinute( ) const;
    // Changes the time to minutesAdded minutes later.
    void advance(int minutesAdded);
    // Changes the time to hoursAdded hours plus minutesAdded minutes later.
    void advance(int hoursAdded, int minutesAdded);
    // Friend operator that checks of two times are equal. 
    friend bool operator ==(const DigitalTime& time1, 
                            const DigitalTime& time2);
    // Friend operator that inputs values from the keyboard to create a new time object.  
    friend istream& operator >>(istream& ins, DigitalTime& theObject);
    // Friend operator that outputs a time object to the console. 
    friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);
private: 
    int hour;
    int minute;
    // Precondition: Next input in to be read from the keyboard is 
    // a time in notation, like 9:45 or 14:45.
    // Postcondition: theHour has been set to the hour part of the time. 
    // The colon has been discarded and the next input to be read is the minute.
    static void readHour(int& theHour);
    // Reads the minute from the keyboard after readHour has read the hour.
    static void readMinute(int& theMinute);
    // Precondition: c is one of the digits 0 through 9.
    // Returns the integer for the digit; that is, digitToInt(3) returns 3.
    static int digitToInt(char c);
};

// end marker for the above's #ifndef
#endif //DTIME_H
