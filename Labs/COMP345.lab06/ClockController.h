#pragma once
#include "DigitalClock.h"

class ClockController {
private: 
	DigitalClock *clockView;
	ClockTimer *clockModel;
public: 
	ClockController(DigitalClock* newView, ClockTimer* newModel);
	void controlClock();
};