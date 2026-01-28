#pragma once
#include <iostream>
#include "States.h"
using namespace std;

class HardwareException : public exception {
  public:
	HardwareException();
	char * exc_time;
	const char * what() const;
};

class ActuatorException : public HardwareException {
	friend ostream& operator<<(ostream &output, const ActuatorException &e);
  public:
	ActuatorException(HardwareState s);
	HardwareState hw_State;
};

class SensorException : public HardwareException {
	friend ostream& operator<<(ostream &output, const SensorException &e);
  public:
	SensorException(int v);
	int valueRead;
};

class NegativePressureException : public SensorException {
  public:
	NegativePressureException(int v);
};

class OverloadPressureException : public SensorException {
  public:
	OverloadPressureException(int v);
};

class StuckValveException : public ActuatorException {
  public:
	StuckValveException(HardwareState s);
};