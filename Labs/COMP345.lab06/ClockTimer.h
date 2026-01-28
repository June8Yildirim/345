#pragma once
#include "Subject.h"

class ClockTimer : public Subject {
  public:
	ClockTimer();
	int getHour(){ return hour; };
	int getMinute(){ return minute; };
	int getSecond(){ return second; };
	int getInterval() { return timedInterval; };
	void start();
	void setTimedInterval(int newTimedInterval);
	void setTime(int newHour, int newMinute, int newSecond);
	void tick();
	~ClockTimer();
private:
	int hour;
	int minute;
	int second;
	int timedInterval;
};
