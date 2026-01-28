// From Walter Savitch' book resources - Absolute C++

// This file represents a compilation unit.
// This compilation unit is composed of this file and all files it includes and,
// recursively, all files that its included files include.

// This is the implementation file: dtime.cpp of the class DigitalTime.
// The declaration for the class DigitalTime is in the header file dtime.h,
// which needs to be included in order to be referred to here.

// This file refers to cin/cout, which is defined in the iostream library.
#include <iostream>
// This file refers to exit(), which is defined in cstdlib.
// Most programming environments will include cstdlib automatically.
#include <cstdlib>
// This file refers to isdigit(), which is defined in cctype.
// Most programming environments will include cctype automatically.
#include <cctype>
// cin/cout are defined in the std namespace.
using namespace std;

// This file uses names declared in the dtime.h header file
// (e.g. the DigitalTime class/type), so it needs to include it.
#include "dtime.h"

// Uses iostream (cout) and cstdlib (exit) :
DigitalTime::DigitalTime(int theHour, int theMinute) {
  if (theHour < 0 || theHour > 24 || theMinute < 0 || theMinute > 59) {
    cout << "Illegal argument to DigitalTime constructor.";
    exit(1);
  } else {
    hour = theHour;
    minute = theMinute;
  }
  if (hour == 24)
    hour = 0; // standardize midnight as 0:00
}

DigitalTime::DigitalTime() {
  hour = 0;
  minute = 0;
}

// "DigitalTime::" signifies that this function is a member of the DigitalTime
// class.
int DigitalTime::getHour() const { return hour; }

int DigitalTime::getMinute() const { return minute; }

void DigitalTime::advance(int minutesAdded) {
  int grossMinutes = minute + minutesAdded;
  minute = grossMinutes % 60;
  int hourAdjustment = grossMinutes / 60;
  hour = (hour + hourAdjustment) % 24;
}

void DigitalTime::advance(int hoursAdded, int minutesAdded) {
  hour = (hour + hoursAdded) % 24;
  advance(minutesAdded);
}

// As this does not have the "DigitalTime::" prefix, this signifies that
// this is an operator that is not a member, i.e. a free operator.
bool operator==(const DigitalTime &time1, const DigitalTime &time2) {
  return (time1.hour == time2.hour && time1.minute == time2.minute);
}

// Uses iostream (ostream):
ostream &operator<<(ostream &outs, const DigitalTime &theObject) {
  outs << theObject.hour << ':';
  if (theObject.minute < 10)
    outs << '0';
  outs << theObject.minute;
  return outs;
}

// Uses iostream (istream):
istream &operator>>(istream &ins, DigitalTime &theObject) {
  DigitalTime::readHour(theObject.hour);
  DigitalTime::readMinute(theObject.minute);
  return ins;
}

int DigitalTime::digitToInt(char c) { return (int(c) - int('0')); }

// Uses iostream (cin, cout), cctype (isdigit), and cstdlib (exit):
void DigitalTime::readMinute(int &theMinute) {
  char c1, c2;
  cin >> c1 >> c2;
  if (!(isdigit(c1) && isdigit(c2))) {
    cout << "Error illegal input to readMinute\n";
    exit(1);
  }
  theMinute = digitToInt(c1) * 10 + digitToInt(c2);
  if (theMinute < 0 || theMinute > 59) {
    cout << "Error illegal input to readMinute\n";
    exit(1);
  }
}

// Uses iostream (cin), cctype (isdigit), and cstdlib (exit):
void DigitalTime::readHour(int &theHour) {
  char c1, c2;
  cin >> c1 >> c2;
  if (!(isdigit(c1) && (isdigit(c2) || c2 == ':'))) {
    cout << "Error illegal input to readHour\n";
    exit(1);
  }

  if (isdigit(c1) && c2 == ':') {
    theHour = DigitalTime::digitToInt(c1);
  } else {
    theHour = DigitalTime::digitToInt(c1) * 10 + DigitalTime::digitToInt(c2);
    cin >> c2; // discard ':'
    if (c2 != ':') {
      cout << "Error illegal input to readHour\n";
      exit(1);
    }
  }
  if (theHour == 24)
    theHour = 0; // Standardize midnight as 0:00
  if (theHour < 0 || theHour > 23) {
    cout << "Error illegal input to readHour\n";
    exit(1);
  }
}
