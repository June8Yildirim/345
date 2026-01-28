#pragma once
#include "States.h"
using namespace std;

class Boiler;

class PressureReleaseValve {
  public:
	PressureReleaseValve(HardwareState s);
	void close();
	void open();
  private:
	ActuatorState act_state;
	HardwareState hw_state;
};

class PressureReleaseValveConnector {
  private:
	PressureReleaseValve* prv;
	Boiler* b;
  public:
	PressureReleaseValveConnector(PressureReleaseValve *prv, Boiler *b);
	void close();
	void open();
};