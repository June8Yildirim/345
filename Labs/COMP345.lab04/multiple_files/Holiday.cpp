// from : Savitch. Absolute C++. 

#include "Holiday.h"

// These are definitions for the member functions declared in Holiday.h
Holiday::Holiday() : doy(1, 1), parkingEnforcement(true){
	// member initialization is done in the initialization list
}

Holiday::Holiday(int month, int day, bool enforcement) : doy(month, day), parkingEnforcement(enforcement){
	// member initialization is done in the initialization list
}