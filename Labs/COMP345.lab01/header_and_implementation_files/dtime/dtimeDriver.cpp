// From Walter Savitch' book resources - Absolute C++

// This is the application file that includes the main function.
// which demonstrates use of the DigitalTime class.

// this file uses cin/cout, which is defined in the iostream library.
#include <iostream>
// cin/cout are defined in the std namespace/
using namespace std;
// this file uses identifiers such as DigitalTime, which are declared in the
// dtime.h file.
#include "dtime.h"

int main() {
  DigitalTime clock, oldClock;
  cout << "You may write midnight as either 0:00 or 24:00,\n"
       << "but, I will always write it as 0:00.\n"
       << "Enter the time in 24 hour notation: ";
  cin >> clock;
  oldClock = clock;
  clock.advance(15);
  if (clock == oldClock)
    cout << "Something is wrong.";
  cout << "You entered " << oldClock << endl;
  cout << "15 minutes later the time will be " << clock << endl;
  clock.advance(2, 15);
  cout << "2 hours and 15 minutes after that\n"
       << "the time will be " << clock << endl;
  return 0;
}
