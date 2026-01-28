#pragma once
#include "PressureReleaseValve.h"
#include "PressureSensor.h"
#include <fstream>
using namespace std;

class Boiler {
  public:
	Boiler();
	~Boiler();
	void shutdown();
	void start();
	PressureSensorConnector* ps;
	PressureReleaseValveConnector* prv;
	ofstream emergencyFile;
	ofstream pressureReportFile;
	BoilerState boilerState; 

};