#pragma once
// should not have #include "Boiler.h" here
// as it would create circular header file read
// rather, have a forward definition for Boiler
// which is only what we need here, as this file
// does not refer to any member for the Boiler class

class Boiler;

class PressureSensor {
  public:
	int getPressure();
};

class PressureSensorConnector {
  private:
	PressureSensor* ps;
	Boiler* b;
  public:
	PressureSensorConnector(PressureSensor *ps, Boiler *b);
	int getPressure();
};