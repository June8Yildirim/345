// From Walter Savitch' book resources - Absolute C++

//This is the header file dtime.h. This is the interface for the class DigitalTime.
//Values of this type are times of day. The values are input and output in 24 hour
//notation as in 9:30 for 9:30 AM and 14:45 for 2:45 PM.
#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using std::istream;
using std::ostream;

// Declare a namespace in which some identifiers are declared/defined
namespace DTimeSavitch{
    class DigitalTime{
    public:
        DigitalTime(int theHour, int theMinute);
        DigitalTime( );
        int getHour( ) const;
        int getMinute( ) const;
        void advance(int minutesAdded);
        void advance(int hoursAdded, int minutesAdded);
        friend bool operator ==(const DigitalTime& time1, const DigitalTime& time2);
        friend istream& operator >>(istream& ins, DigitalTime& theObject);
        friend ostream& operator <<(ostream& outs, const DigitalTime& theObject);
    private:
        int hour;
        int minute;
    };
} //DTimeSavitch
#endif //DTIME_H
