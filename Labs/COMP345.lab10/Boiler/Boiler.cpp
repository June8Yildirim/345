#include "Boiler.h"
#include "PressureSensor.h" 
#include "PressureReleaseValve.h"
#include "BoilerExceptions.h"
#include <iostream>
#include <ctime>     //for srand() and time() 
#include <windows.h> //for Sleep()
using namespace std;

Boiler::Boiler(){
	cout << "in Boiler constructor" << endl;
	emergencyFile.open("EmergencyFile.txt");
	emergencyFile << "STARTING BOILER CONTROLLER" << endl;
	pressureReportFile.open("pressureReportFile.txt");
	pressureReportFile << "STARTING BOILER CONTROLLER" << endl;
	ps = new PressureSensorConnector(new PressureSensor(), this);
	// here the valve installed is defectively stuck
	// remove the "stuck" parameter and a random factor will decide
	// whether the valve will eventually become defective
	prv = new PressureReleaseValveConnector(new PressureReleaseValve(stuck), this);
	boilerState = safe;
	srand(time(0)); 
}

void Boiler::shutdown(){
	cout << "in Boiler::shutdown" << endl;
	emergencyFile << "Engaging shutdown procedure." << endl;
	prv->open(); 
	emergencyFile << "BOILER CONTROLLER WAS SHUT DOWN" << endl;
	pressureReportFile << "BOILER CONTROLLER WAS SHUT DOWN" << endl;
}

void Boiler::start(){
	cout << "in Boiler::start()" << endl;
	int i;
	while (boilerState == safe){
		Sleep(1000);
		i = ps->getPressure();
	}
}
Boiler::~Boiler(){
	emergencyFile.close();
	pressureReportFile.close();
}
